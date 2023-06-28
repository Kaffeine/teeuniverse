/*
 * Copyright (C) 2016 necropotame (necropotame@gmail.com)
 * 
 * This file is part of TeeUniverse.
 * 
 * TeeUniverse is free software: you can redistribute it and/or  modify
 * it under the terms of the GNU Affero General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * TeeUniverse is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with TeeUniverse.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "archivefile.h"

#include <shared/system/debug.h>
#include <shared/math/math.h>
#include <shared/components/storage.h>

#include <zlib.h>

#include <cstdint>
#include <limits>

CArchiveFile::CArchiveFile()
{
	//Init
	for(int i=0; i<256; i++)
	{
		m_ItemTypes[i].m_ItemSize = 0;
		m_ItemTypes[i].m_NumItems = 0;
		m_ItemTypes[i].m_pData = nullptr;
	}
}

CArchiveFile::~CArchiveFile()
{
	Close();
}

bool CArchiveFile::Open(CStorage* pStorage, const char* pFilename, int StorageType)
{
	//Open file
	IOHANDLE File = pStorage->OpenFile(pFilename, IOFLAG_READ, StorageType);
	if(!File)
	{
		debug::WarningStream("ArchiveFile") << "could not open '" << pFilename << "'" << std::endl;
		return false;
	}

	//Get CRC
	m_Crc = crc32(0L, nullptr, 0);
	{
		enum
		{
			BUFFER_SIZE = 64*1024
		};

		unsigned char aBuffer[BUFFER_SIZE];

		while(1)
		{
			unsigned Bytes = io_read(File, aBuffer, BUFFER_SIZE);
			if(Bytes <= 0)
				break;
			m_Crc = crc32(m_Crc, aBuffer, Bytes);
		}

		io_seek(File, 0, IOSEEK_START);
	}

	//Check signature
	char aSignature[5];
	io_read(File, &aSignature, sizeof(aSignature));
	if(str_comp_num(aSignature, "TUA1", 4) != 0)
	{
		debug::WarningStream("ArchiveFile") << "wrong signature. " << aSignature[0] << " " << aSignature[1] << " " << aSignature[2] << " " << aSignature[3] << " " << std::endl;
		io_close(File);
		return false;
	}
	
	//Get Header
	CArchiveFile_Header StoredHeader;
	io_read(File, &StoredHeader, sizeof(StoredHeader));
	
	//Get items
    uint32_t NumTypes = ReadUInt32(StoredHeader.m_NumTypes);
    for(uint32_t i=0; i<NumTypes; i++)
	{
		CArchiveFile_ItemType StoredType;
		io_read(File, &StoredType, sizeof(StoredType));


        uint32_t TypeId = ReadUInt32(StoredType.m_TypeId);
		CItemType& Type = m_ItemTypes[TypeId];
		Type.m_ItemSize = ReadUInt32(StoredType.m_ItemSize);
		Type.m_NumItems = ReadUInt32(StoredType.m_NumItems);
		
		Type.m_pData = new uint8_t[Type.m_ItemSize * Type.m_NumItems];
		
		io_read(File, Type.m_pData, Type.m_ItemSize * Type.m_NumItems * sizeof(uint8_t));
	}
	
	//Get raw datas
    uint32_t NumRawDatas = ReadUInt32(StoredHeader.m_NumRawDatas);
    for(uint32_t i=0; i<NumRawDatas; i++)
	{
		CArchiveFile_RawData StoredRawData;
		io_read(File, &StoredRawData, sizeof(StoredRawData));
		
		m_RawDatas.emplace_back();
		m_RawDatas.back().m_CompressedSize = ReadUInt32(StoredRawData.m_CompressedSize);
		m_RawDatas.back().m_UncompressedSize = ReadUInt32(StoredRawData.m_UncompressedSize);
		
		if(m_RawDatas.back().m_CompressedSize > 0)
		{
			m_RawDatas.back().m_pCompressedData = new uint8_t[m_RawDatas.back().m_CompressedSize];
			io_read(File, m_RawDatas.back().m_pCompressedData, m_RawDatas.back().m_CompressedSize * sizeof(uint8_t));
			m_RawDatas.back().m_pUncompressedData = nullptr;
		}
		else
		{
			m_RawDatas.back().m_pUncompressedData = new uint8_t[m_RawDatas.back().m_UncompressedSize];
			io_read(File, m_RawDatas.back().m_pUncompressedData, m_RawDatas.back().m_UncompressedSize * sizeof(uint8_t));
			m_RawDatas.back().m_pCompressedData = nullptr;
		}
	}
	
	//Get strings
    uint32_t NumStrings = ReadUInt32(StoredHeader.m_NumStrings);
    for(uint32_t i=0; i<NumStrings; i++)
	{
		tua_uint32 StoredLength;
		io_read(File, &StoredLength, sizeof(StoredLength));
        uint32_t Length = ReadUInt32(StoredLength);
		
		m_Strings.emplace_back();
		m_Strings.back().m_pText = new char[Length+1];
		io_read(File, m_Strings.back().m_pText, sizeof(char)*(Length+1));
	}
	
	io_close(File);
	
	return true;
}

bool CArchiveFile::Write(CStorage* pStorage, fs_stream_wb* pFileStream)
{
	//Write signature
	const char aSignature[] = "TUA1";
	pFileStream->write(&aSignature, sizeof(aSignature));
	
	//Counte number of types
	int NumTypes = 0;
	for(int i=0; i<256; i++)
	{
		if(m_ItemTypes[i].m_NumItems > 0)
			NumTypes++;
	}
	
	//Write Header
	CArchiveFile_Header StoredHeader;
	StoredHeader.m_NumTypes = WriteUInt32(NumTypes);
	StoredHeader.m_NumStrings = WriteUInt32(m_Strings.size());
	StoredHeader.m_NumRawDatas = WriteUInt32(m_RawDatas.size());
	pFileStream->write(&StoredHeader, sizeof(StoredHeader));
	
	//Write items
    for(uint32_t i=0; i<256; i++)
	{
		CItemType& Type = m_ItemTypes[i];
		
		if(Type.m_NumItems == 0)
			continue;
		
		CArchiveFile_ItemType StoredType;
		StoredType.m_ItemSize = WriteUInt32(Type.m_ItemSize);
		StoredType.m_NumItems = WriteUInt32(Type.m_NumItems);
		StoredType.m_TypeId = WriteUInt32(i);
		pFileStream->write(&StoredType, sizeof(StoredType));
		
		pFileStream->write(Type.m_pData, StoredType.m_NumItems * StoredType.m_ItemSize * sizeof(uint8_t));
	}
	
	//Write raw datas
    for(uint32_t i=0; i<(uint32_t)m_RawDatas.size(); i++)
	{
		CRawData& RawData = m_RawDatas[i];
		CArchiveFile_RawData StoredRawData;
		if(RawData.m_pCompressedData)
		{
			StoredRawData.m_CompressedSize = WriteUInt32(RawData.m_CompressedSize);
			StoredRawData.m_UncompressedSize = WriteUInt32(RawData.m_UncompressedSize);
			pFileStream->write(&StoredRawData, sizeof(StoredRawData));
			pFileStream->write(RawData.m_pCompressedData, RawData.m_CompressedSize * sizeof(uint8_t));
		}
		else
		{
			StoredRawData.m_CompressedSize = WriteUInt32(0);
			StoredRawData.m_UncompressedSize = WriteUInt32(RawData.m_UncompressedSize);
			pFileStream->write(&StoredRawData, sizeof(StoredRawData));
			pFileStream->write(RawData.m_pUncompressedData, RawData.m_UncompressedSize * sizeof(uint8_t));
		}
	}
	
	//Write strings
    for(uint32_t i=0; i<(uint32_t)m_Strings.size(); i++)
	{
		
		CString& String = m_Strings[i];
        uint32_t Length = str_length(String.m_pText);
		tua_uint32 StoredLength = WriteUInt32(Length);
		pFileStream->write(&StoredLength, sizeof(StoredLength));
		pFileStream->write(String.m_pText, sizeof(char)*(Length+1));
	}
	
	return true;
}

bool CArchiveFile::Write(CStorage* pStorage, const char* pFilename, int Type)
{
	dynamic_string Buffer;
	pStorage->GetCompletePath(Type, pFilename, Buffer);
	
	fs_filestream_wb FileStream(Buffer.buffer());
	if(!FileStream.is_valid())
	{
		debug::WarningStream("ArchiveFile") << "could not open '" << pFilename << "' for writing" << std::endl;
		return false;
	}
	
	Write(pStorage, &FileStream);
	
	FileStream.close();
	
	return true;
}

void CArchiveFile::Close()
{
	for(int i=0; i<256; i++)
	{
		if(m_ItemTypes[i].m_pData)
		{
			delete[] m_ItemTypes[i].m_pData;
			m_ItemTypes[i].m_pData = nullptr;
		}
	}
	
	for(unsigned int i=0; i<m_RawDatas.size(); i++)
	{
		if(m_RawDatas[i].m_pCompressedData)
			delete[] m_RawDatas[i].m_pCompressedData;
		if(m_RawDatas[i].m_pUncompressedData)
			delete[] m_RawDatas[i].m_pUncompressedData;
	}
	m_RawDatas.clear();
	
	for(unsigned int i=0; i<m_Strings.size(); i++)
	{
		if(m_Strings[i].m_pText)
			delete[] m_Strings[i].m_pText;
	}
	m_Strings.clear();
}

void CArchiveFile::SetItemType(uint32_t Type, uint32_t ItemSize, uint32_t NumItems)
{
	if(m_ItemTypes[Type].m_pData)
		delete[] m_ItemTypes[Type].m_pData;
	
	m_ItemTypes[Type].m_ItemSize = ItemSize;
	m_ItemTypes[Type].m_NumItems = NumItems;
	m_ItemTypes[Type].m_pData = new uint8_t[ItemSize * NumItems];
}

uint8_t* CArchiveFile::GetData(tua_dataid StoredDataId)
{
    uint32_t DataId = ReadDataId(StoredDataId);

    if(DataId >= (uint32_t)m_RawDatas.size())
	{
		debug::ErrorStream("ArchiveFile") << "can't read the data #" << DataId << std::endl;
		return nullptr;
	}
	
	if(m_RawDatas[DataId].m_pUncompressedData)
	{
		return m_RawDatas[DataId].m_pUncompressedData;
	}
	else
	{
		unsigned long Size = m_RawDatas[DataId].m_UncompressedSize;
		m_RawDatas[DataId].m_pUncompressedData = new uint8_t[m_RawDatas[DataId].m_UncompressedSize];
		
		int Result = uncompress(
			(Bytef*)m_RawDatas[DataId].m_pUncompressedData,
			&Size,
			(Bytef*)m_RawDatas[DataId].m_pCompressedData,
			m_RawDatas[DataId].m_CompressedSize
		);
		
		if(Result != Z_OK)
		{
			debug::ErrorStream("ArchiveFile") << "compression error: " << zError(Result) << std::endl;
			return nullptr;
		}
			
		return m_RawDatas[DataId].m_pUncompressedData;
	}
}

tua_dataid CArchiveFile::AddData(void *pData, uint32_t Size)
{
	unsigned long CompressedSize = compressBound(Size);
	m_RawDatas.emplace_back();
	m_RawDatas.back().m_UncompressedSize = Size;
	m_RawDatas.back().m_pUncompressedData = nullptr;
	
	m_RawDatas.back().m_pCompressedData = new uint8_t[CompressedSize];
	
	int Result = compress((Bytef*)m_RawDatas.back().m_pCompressedData, &CompressedSize, (Bytef*)pData, Size);
	if(Result != Z_OK)
		debug::ErrorStream("ArchiveFile") << "compression error: " << zError(Result) << std::endl;
	
	if(CompressedSize >= Size)
	{
		m_RawDatas.back().m_CompressedSize = 0;
		delete[] m_RawDatas.back().m_pCompressedData;
		m_RawDatas.back().m_pCompressedData = nullptr;
		
		m_RawDatas.back().m_pUncompressedData = new uint8_t[Size];
		mem_copy(m_RawDatas.back().m_pUncompressedData, pData, Size);
	}
	else
	{
		m_RawDatas.back().m_CompressedSize = CompressedSize;
	}

    return WriteDataId((uint32_t) m_RawDatas.size()-1);
}

const char* CArchiveFile::GetString(tua_stringid StoredStringId)
{
	if(StoredStringId == std::numeric_limits<tua_stringid>::max())
		return nullptr;

    uint32_t StringId = ReadStringId(StoredStringId);
	if(StringId >= (tua_stringid)m_Strings.size())
		return nullptr;
	else
		return m_Strings[StringId].m_pText;
}

tua_stringid CArchiveFile::AddString(const char* pText)
{
	if(!pText)
		return -1;
	
	//Search if the string already exists
	for(unsigned int i=0; i<m_Strings.size(); i++)
	{
		if(str_comp(pText, m_Strings[i].m_pText) == 0)
            return WriteStringId((uint32_t) i);
	}
	
	int Length = str_length(pText);
	m_Strings.emplace_back();
	m_Strings.back().m_pText = new char[Length+1];
	str_copy(m_Strings.back().m_pText, pText, sizeof(char)*(Length+1));

    return WriteStringId((uint32_t) m_Strings.size()-1);
}
