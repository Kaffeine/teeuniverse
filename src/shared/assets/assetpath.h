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

#ifndef __CLIENT_ASSETS_ASSETPATH__
#define __CLIENT_ASSETS_ASSETPATH__

#include <shared/archivefile.h>
#include <shared/math/math.h>

#include <cstdint>
#include <string>
#include <vector>

class CAssetPath
{
public:
	class CTuaType
	{
	public:
		tua_stringid m_Name;
		tua_uint16 m_PackageId;
		tua_uint16 m_Type;
	};

private:
	uint32_t m_Id;
	uint16_t m_PackageId; //(packageid == 0 means self)
	uint16_t m_Type; //(type == 0 means null)

public:
	CAssetPath() :
		m_Id(0), m_PackageId(0), m_Type(0) {}
	CAssetPath(uint16_t Type, uint16_t PackageId, uint32_t Id) :
		m_Id(Id), m_PackageId(PackageId), m_Type(Type + 1) {}

	uint16_t GetType() const { return m_Type - 1; }
	uint16_t GetPackageId() const { return m_PackageId; }
	uint32_t GetId() const { return m_Id; }

	uint16_t GetRawType() const { return m_Type; }
	uint16_t GetRawPackageId() const { return m_PackageId; }
	uint32_t GetRawId() const { return m_Id; }

	void SetType(uint16_t Type) { m_Type = Type + 1; }
	void SetPackageId(uint16_t PackageId) { m_PackageId = PackageId; }
	void SetId(uint32_t Id) { m_Id = Id; }

	void SetRawType(uint16_t Type) { m_Type = Type; }
	void SetRawPackageId(uint16_t PackageId) { m_PackageId = PackageId; }
	void SetRawId(uint32_t Id) { m_Id = Id; }

	bool IsNull() const { return m_Type == 0; }
	bool IsNotNull() const { return m_Type != 0; }

	bool operator==(const CAssetPath &Path) const { return (m_PackageId == Path.m_PackageId && m_Id == Path.m_Id && m_Type == Path.m_Type); }
	bool operator!=(const CAssetPath &Path) const { return !(*this == Path); }

	static CAssetPath Null() { return CAssetPath(); }

public:
	enum
	{
		OPERATION_DELETE = 0,
		OPERATION_RESOLVE_NAME,
	};

	class COperation
	{
	private:
		int m_OperationId;
		union
		{
			struct
			{
				uint32_t m_Id;
				uint16_t m_PackageId;
				uint16_t m_Type;
			} m_OpDelete;
			struct
			{
				class CAssetsManager *m_pAssetsManager;
				std::vector<std::string> *m_pNames;
			} m_OpResolveName;
		};

	public:
		static COperation DeleteAsset(const CAssetPath &Path)
		{
			COperation Operation;
			Operation.m_OperationId = OPERATION_DELETE;
			Operation.m_OpDelete.m_PackageId = Path.GetPackageId();
			Operation.m_OpDelete.m_Type = Path.GetType();
			Operation.m_OpDelete.m_Id = Path.GetId();
			return Operation;
		}

		static COperation ResolveName(class CAssetsManager *pAssetsManager, std::vector<std::string> *pNames)
		{
			COperation Operation;
			Operation.m_OperationId = OPERATION_RESOLVE_NAME;
			Operation.m_OpResolveName.m_pNames = pNames;
			Operation.m_OpResolveName.m_pAssetsManager = pAssetsManager;
			return Operation;
		}

		bool MustBeDeleted(CAssetPath &Path) const
		{
			return (
				m_OperationId == OPERATION_DELETE &&
				Path.GetPackageId() == m_OpDelete.m_PackageId &&
				Path.GetType() == m_OpDelete.m_Type &&
				Path.GetId() == m_OpDelete.m_Id);
		}

		void Apply(CAssetPath &Path) const;
	};
};

class CSubPath
{
public:
	class CTuaType
	{
	public:
		tua_uint16 m_Id0;
		tua_uint16 m_Id1;
		tua_uint16 m_Id2;
		tua_uint16 m_Type;

		static void Read(CArchiveFile *pArchiveFile, const CTuaType &TuaPath, CSubPath &SysPath)
		{
			SysPath.SetType(pArchiveFile->ReadUInt16(TuaPath.m_Type));
			SysPath.SetId(pArchiveFile->ReadUInt16(TuaPath.m_Id0));
			SysPath.SetId2(pArchiveFile->ReadUInt16(TuaPath.m_Id1));
			SysPath.SetId3(pArchiveFile->ReadUInt16(TuaPath.m_Id2));
		}

		static void Write(CArchiveFile *pArchiveFile, const CSubPath &SysPath, CTuaType &TuaPath)
		{
			TuaPath.m_Type = pArchiveFile->WriteUInt16(SysPath.GetType());
			TuaPath.m_Id0 = pArchiveFile->WriteUInt16(SysPath.GetId());
			TuaPath.m_Id1 = pArchiveFile->WriteUInt16(SysPath.GetId2());
			TuaPath.m_Id2 = pArchiveFile->WriteUInt16(SysPath.GetId3());
		}
	};

private:
	uint16_t m_Type;
	uint16_t m_Id0;
	uint16_t m_Id1;
	uint16_t m_Id2;

public:
	CSubPath() :
		m_Type(0), m_Id0(0), m_Id1(0), m_Id2(0) {}
	CSubPath(int Type, int Id0, int Id1, int Id2) :
		m_Type(Type + 1), m_Id0(Id0), m_Id1(Id1), m_Id2(Id2) {}

public:
	uint16_t GetType() const { return m_Type - 1; }
	uint16_t GetId() const { return m_Id0; }
	uint16_t GetId2() const { return m_Id1; }
	uint16_t GetId3() const { return m_Id2; }

	void SetType(uint16_t Value) { m_Type = Value + 1; }
	void SetId(uint16_t Value) { m_Id0 = Value; }
	void SetId2(uint16_t Value) { m_Id1 = Value; }
	void SetId3(uint16_t Value) { m_Id2 = Value; }

	CSubPath PopId() const { return CSubPath(GetType(), GetId2(), GetId3(), 0); }
	CSubPath DoublePopId() const { return CSubPath(GetType(), GetId3(), 0, 0); }

	bool IsNull() const { return m_Type == 0; }
	bool IsNotNull() const { return m_Type != 0; }

	bool operator==(const CSubPath &Path) const { return (mem_comp(this, &Path, sizeof(CSubPath)) == 0); }
	bool operator!=(const CSubPath &Path) const { return (mem_comp(this, &Path, sizeof(CSubPath)) != 0); }

	static CSubPath Null() { return CSubPath(); }

public:
	enum
	{
		OPERATION_SHIFTID = 0,
	};

	class COperation
	{
	private:
		int m_Type;
		int m_PackageId;
		int m_IdStart;
		int m_IdEnd;
		int m_Shift;

	public:
		void Apply(CSubPath &Path) const;
	};
};

#endif
