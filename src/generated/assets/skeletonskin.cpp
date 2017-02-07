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

/*
 * THIS FILE HAS BEEN GENERATED BY A SCRIPT.
 * DO NOT EDIT MANUALLY!
 *
 * Please use the script "scripts/assets/assets.py" to regenerate it.
 *
 * Why this file is generated by a script?
 * Because there is more than 10 files that follow the same format.
 * In addition, each time a new member is added, enums, getter, setters,
 * copy/transfert functions and storage structure must be updated.
 * It's too much to avoid mistakes.
 */

#include <generated/assets/skeletonskin.h>
#include <shared/assets/assetssaveloadcontext.h>
#include <shared/archivefile.h>

CAsset_SkeletonSkin::CBone::CBone()
{
	m_Anchor = 0.0f;
	m_Translation = 0.0f;
	m_Scale = 1.0f;
	m_Angle = 0.0f;
	m_Color = 1.0f;
	m_Alignment = ALIGNMENT_BONE;
}


void CAsset_SkeletonSkin::CBone::CTuaType_0_1_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_SkeletonSkin::CBone& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_SpritePath, SysType.m_SpritePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_BonePath, SysType.m_BonePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_LayerPath, SysType.m_LayerPath);
	SysType.m_Anchor = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Anchor);
	SysType.m_Translation.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_X);
	SysType.m_Translation.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_Y);
	SysType.m_Scale.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_X);
	SysType.m_Scale.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_Y);
	SysType.m_Angle = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Angle);
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	SysType.m_Alignment = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Alignment);
}


void CAsset_SkeletonSkin::CTuaType_0_1_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_SkeletonSkin& SysType)
{
	CAsset::CTuaType_0_1_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_SkeletonPath, SysType.m_SkeletonPath);
	{
		const CAsset_SkeletonSkin::CBone::CTuaType_0_1_0* pData = (const CAsset_SkeletonSkin::CBone::CTuaType_0_1_0*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Sprite.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Sprite.m_Size);
		SysType.m_Sprite.resize(Size);
		for(uint32 i=0; i<Size; i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_1_0::Read(pLoadingContext, pData[i], SysType.m_Sprite[i]);
		}
	}
	
}


void CAsset_SkeletonSkin::CBone::CTuaType_0_1_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CBone& SysType, CTuaType_0_1_0& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_SpritePath, TuaType.m_SpritePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_BonePath, TuaType.m_BonePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_LayerPath, TuaType.m_LayerPath);
	TuaType.m_Anchor = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Anchor);
	TuaType.m_Translation.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.x);
	TuaType.m_Translation.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.y);
	TuaType.m_Scale.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.x);
	TuaType.m_Scale.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.y);
	TuaType.m_Angle = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Angle);
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	TuaType.m_Alignment = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Alignment);
}

void CAsset_SkeletonSkin::CTuaType_0_1_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_1_0& TuaType)
{
	CAsset::CTuaType_0_1_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_SkeletonPath, TuaType.m_SkeletonPath);
	{
		TuaType.m_Sprite.m_Size = SysType.m_Sprite.size();
		CAsset_SkeletonSkin::CBone::CTuaType_0_1_0* pData = new CAsset_SkeletonSkin::CBone::CTuaType_0_1_0[SysType.m_Sprite.size()];
		for(unsigned int i=0; i<SysType.m_Sprite.size(); i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_1_0::Write(pLoadingContext, SysType.m_Sprite[i], pData[i]);
		}
		TuaType.m_Sprite.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonSkin::CBone::CTuaType_0_1_0)*SysType.m_Sprite.size());
		delete[] pData;
	}
}

void CAsset_SkeletonSkin::CBone::CTuaType_0_2_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_SkeletonSkin::CBone& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_SpritePath, SysType.m_SpritePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_BonePath, SysType.m_BonePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_LayerPath, SysType.m_LayerPath);
	SysType.m_Anchor = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Anchor);
	SysType.m_Translation.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_X);
	SysType.m_Translation.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_Y);
	SysType.m_Scale.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_X);
	SysType.m_Scale.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_Y);
	SysType.m_Angle = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Angle);
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	SysType.m_Alignment = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Alignment);
}


void CAsset_SkeletonSkin::CTuaType_0_2_0::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_SkeletonSkin& SysType)
{
	CAsset::CTuaType_0_2_0::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_SkeletonPath, SysType.m_SkeletonPath);
	{
		const CAsset_SkeletonSkin::CBone::CTuaType_0_2_0* pData = (const CAsset_SkeletonSkin::CBone::CTuaType_0_2_0*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Sprite.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Sprite.m_Size);
		SysType.m_Sprite.resize(Size);
		for(uint32 i=0; i<Size; i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_2_0::Read(pLoadingContext, pData[i], SysType.m_Sprite[i]);
		}
	}
	
}


void CAsset_SkeletonSkin::CBone::CTuaType_0_2_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CBone& SysType, CTuaType_0_2_0& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_SpritePath, TuaType.m_SpritePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_BonePath, TuaType.m_BonePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_LayerPath, TuaType.m_LayerPath);
	TuaType.m_Anchor = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Anchor);
	TuaType.m_Translation.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.x);
	TuaType.m_Translation.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.y);
	TuaType.m_Scale.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.x);
	TuaType.m_Scale.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.y);
	TuaType.m_Angle = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Angle);
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	TuaType.m_Alignment = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Alignment);
}

void CAsset_SkeletonSkin::CTuaType_0_2_0::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_2_0& TuaType)
{
	CAsset::CTuaType_0_2_0::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_SkeletonPath, TuaType.m_SkeletonPath);
	{
		TuaType.m_Sprite.m_Size = SysType.m_Sprite.size();
		CAsset_SkeletonSkin::CBone::CTuaType_0_2_0* pData = new CAsset_SkeletonSkin::CBone::CTuaType_0_2_0[SysType.m_Sprite.size()];
		for(unsigned int i=0; i<SysType.m_Sprite.size(); i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_2_0::Write(pLoadingContext, SysType.m_Sprite[i], pData[i]);
		}
		TuaType.m_Sprite.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonSkin::CBone::CTuaType_0_2_0)*SysType.m_Sprite.size());
		delete[] pData;
	}
}

void CAsset_SkeletonSkin::CBone::CTuaType_0_2_1::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_SkeletonSkin::CBone& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_SpritePath, SysType.m_SpritePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_BonePath, SysType.m_BonePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_LayerPath, SysType.m_LayerPath);
	SysType.m_Anchor = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Anchor);
	SysType.m_Translation.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_X);
	SysType.m_Translation.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_Y);
	SysType.m_Scale.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_X);
	SysType.m_Scale.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_Y);
	SysType.m_Angle = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Angle);
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	SysType.m_Alignment = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Alignment);
}


void CAsset_SkeletonSkin::CTuaType_0_2_1::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_SkeletonSkin& SysType)
{
	CAsset::CTuaType_0_2_1::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_SkeletonPath, SysType.m_SkeletonPath);
	{
		const CAsset_SkeletonSkin::CBone::CTuaType_0_2_1* pData = (const CAsset_SkeletonSkin::CBone::CTuaType_0_2_1*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Sprite.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Sprite.m_Size);
		SysType.m_Sprite.resize(Size);
		for(uint32 i=0; i<Size; i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_2_1::Read(pLoadingContext, pData[i], SysType.m_Sprite[i]);
		}
	}
	
}


void CAsset_SkeletonSkin::CBone::CTuaType_0_2_1::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CBone& SysType, CTuaType_0_2_1& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_SpritePath, TuaType.m_SpritePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_BonePath, TuaType.m_BonePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_LayerPath, TuaType.m_LayerPath);
	TuaType.m_Anchor = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Anchor);
	TuaType.m_Translation.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.x);
	TuaType.m_Translation.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.y);
	TuaType.m_Scale.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.x);
	TuaType.m_Scale.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.y);
	TuaType.m_Angle = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Angle);
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	TuaType.m_Alignment = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Alignment);
}

void CAsset_SkeletonSkin::CTuaType_0_2_1::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_2_1& TuaType)
{
	CAsset::CTuaType_0_2_1::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_SkeletonPath, TuaType.m_SkeletonPath);
	{
		TuaType.m_Sprite.m_Size = SysType.m_Sprite.size();
		CAsset_SkeletonSkin::CBone::CTuaType_0_2_1* pData = new CAsset_SkeletonSkin::CBone::CTuaType_0_2_1[SysType.m_Sprite.size()];
		for(unsigned int i=0; i<SysType.m_Sprite.size(); i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_2_1::Write(pLoadingContext, SysType.m_Sprite[i], pData[i]);
		}
		TuaType.m_Sprite.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonSkin::CBone::CTuaType_0_2_1)*SysType.m_Sprite.size());
		delete[] pData;
	}
}

void CAsset_SkeletonSkin::CBone::CTuaType_0_2_2::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_SkeletonSkin::CBone& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_SpritePath, SysType.m_SpritePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_BonePath, SysType.m_BonePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_LayerPath, SysType.m_LayerPath);
	SysType.m_Anchor = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Anchor);
	SysType.m_Translation.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_X);
	SysType.m_Translation.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_Y);
	SysType.m_Scale.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_X);
	SysType.m_Scale.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_Y);
	SysType.m_Angle = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Angle);
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	SysType.m_Alignment = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Alignment);
}


void CAsset_SkeletonSkin::CTuaType_0_2_2::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_SkeletonSkin& SysType)
{
	CAsset::CTuaType_0_2_2::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_SkeletonPath, SysType.m_SkeletonPath);
	{
		const CAsset_SkeletonSkin::CBone::CTuaType_0_2_2* pData = (const CAsset_SkeletonSkin::CBone::CTuaType_0_2_2*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Sprite.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Sprite.m_Size);
		SysType.m_Sprite.resize(Size);
		for(uint32 i=0; i<Size; i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_2_2::Read(pLoadingContext, pData[i], SysType.m_Sprite[i]);
		}
	}
	
}


void CAsset_SkeletonSkin::CBone::CTuaType_0_2_2::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CBone& SysType, CTuaType_0_2_2& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_SpritePath, TuaType.m_SpritePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_BonePath, TuaType.m_BonePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_LayerPath, TuaType.m_LayerPath);
	TuaType.m_Anchor = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Anchor);
	TuaType.m_Translation.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.x);
	TuaType.m_Translation.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.y);
	TuaType.m_Scale.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.x);
	TuaType.m_Scale.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.y);
	TuaType.m_Angle = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Angle);
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	TuaType.m_Alignment = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Alignment);
}

void CAsset_SkeletonSkin::CTuaType_0_2_2::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_2_2& TuaType)
{
	CAsset::CTuaType_0_2_2::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_SkeletonPath, TuaType.m_SkeletonPath);
	{
		TuaType.m_Sprite.m_Size = SysType.m_Sprite.size();
		CAsset_SkeletonSkin::CBone::CTuaType_0_2_2* pData = new CAsset_SkeletonSkin::CBone::CTuaType_0_2_2[SysType.m_Sprite.size()];
		for(unsigned int i=0; i<SysType.m_Sprite.size(); i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_2_2::Write(pLoadingContext, SysType.m_Sprite[i], pData[i]);
		}
		TuaType.m_Sprite.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonSkin::CBone::CTuaType_0_2_2)*SysType.m_Sprite.size());
		delete[] pData;
	}
}

void CAsset_SkeletonSkin::CBone::CTuaType_0_2_3::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_3& TuaType, CAsset_SkeletonSkin::CBone& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_SpritePath, SysType.m_SpritePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_BonePath, SysType.m_BonePath);
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_LayerPath, SysType.m_LayerPath);
	SysType.m_Anchor = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Anchor);
	SysType.m_Translation.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_X);
	SysType.m_Translation.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_Y);
	SysType.m_Scale.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_X);
	SysType.m_Scale.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_Y);
	SysType.m_Angle = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Angle);
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	SysType.m_Alignment = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Alignment);
}


void CAsset_SkeletonSkin::CTuaType_0_2_3::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_3& TuaType, CAsset_SkeletonSkin& SysType)
{
	CAsset::CTuaType_0_2_3::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_SkeletonPath, SysType.m_SkeletonPath);
	{
		const CAsset_SkeletonSkin::CBone::CTuaType_0_2_3* pData = (const CAsset_SkeletonSkin::CBone::CTuaType_0_2_3*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Sprite.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Sprite.m_Size);
		SysType.m_Sprite.resize(Size);
		for(uint32 i=0; i<Size; i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_2_3::Read(pLoadingContext, pData[i], SysType.m_Sprite[i]);
		}
	}
	
}


void CAsset_SkeletonSkin::CBone::CTuaType_0_2_3::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CBone& SysType, CTuaType_0_2_3& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_SpritePath, TuaType.m_SpritePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_BonePath, TuaType.m_BonePath);
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_LayerPath, TuaType.m_LayerPath);
	TuaType.m_Anchor = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Anchor);
	TuaType.m_Translation.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.x);
	TuaType.m_Translation.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.y);
	TuaType.m_Scale.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.x);
	TuaType.m_Scale.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.y);
	TuaType.m_Angle = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Angle);
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	TuaType.m_Alignment = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Alignment);
}

void CAsset_SkeletonSkin::CTuaType_0_2_3::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_2_3& TuaType)
{
	CAsset::CTuaType_0_2_3::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_SkeletonPath, TuaType.m_SkeletonPath);
	{
		TuaType.m_Sprite.m_Size = SysType.m_Sprite.size();
		CAsset_SkeletonSkin::CBone::CTuaType_0_2_3* pData = new CAsset_SkeletonSkin::CBone::CTuaType_0_2_3[SysType.m_Sprite.size()];
		for(unsigned int i=0; i<SysType.m_Sprite.size(); i++)
		{
			CAsset_SkeletonSkin::CBone::CTuaType_0_2_3::Write(pLoadingContext, SysType.m_Sprite[i], pData[i]);
		}
		TuaType.m_Sprite.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonSkin::CBone::CTuaType_0_2_3)*SysType.m_Sprite.size());
		delete[] pData;
	}
}

template<>
int CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const
{
	switch(ValueType)
	{
		case SPRITE_ARRAYSIZE:
			return GetSpriteArraySize();
		case SPRITE_ALIGNMENT:
			return GetSpriteAlignment(SubPath);
	}
	return CAsset::GetValue<int>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, int Value)
{
	switch(ValueType)
	{
		case SPRITE_ARRAYSIZE:
			SetSpriteArraySize(Value);
			return true;
		case SPRITE_ALIGNMENT:
			SetSpriteAlignment(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<int>(ValueType, SubPath, Value);
}

template<>
float CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, float DefaultValue) const
{
	switch(ValueType)
	{
		case SPRITE_ANCHOR:
			return GetSpriteAnchor(SubPath);
		case SPRITE_TRANSLATION_X:
			return GetSpriteTranslationX(SubPath);
		case SPRITE_TRANSLATION_Y:
			return GetSpriteTranslationY(SubPath);
		case SPRITE_SCALE_X:
			return GetSpriteScaleX(SubPath);
		case SPRITE_SCALE_Y:
			return GetSpriteScaleY(SubPath);
		case SPRITE_ANGLE:
			return GetSpriteAngle(SubPath);
	}
	return CAsset::GetValue<float>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, float Value)
{
	switch(ValueType)
	{
		case SPRITE_ANCHOR:
			SetSpriteAnchor(SubPath, Value);
			return true;
		case SPRITE_TRANSLATION_X:
			SetSpriteTranslationX(SubPath, Value);
			return true;
		case SPRITE_TRANSLATION_Y:
			SetSpriteTranslationY(SubPath, Value);
			return true;
		case SPRITE_SCALE_X:
			SetSpriteScaleX(SubPath, Value);
			return true;
		case SPRITE_SCALE_Y:
			SetSpriteScaleY(SubPath, Value);
			return true;
		case SPRITE_ANGLE:
			SetSpriteAngle(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<float>(ValueType, SubPath, Value);
}

template<>
vec2 CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, vec2 DefaultValue) const
{
	switch(ValueType)
	{
		case SPRITE_TRANSLATION:
			return GetSpriteTranslation(SubPath);
		case SPRITE_SCALE:
			return GetSpriteScale(SubPath);
	}
	return CAsset::GetValue<vec2>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, vec2 Value)
{
	switch(ValueType)
	{
		case SPRITE_TRANSLATION:
			SetSpriteTranslation(SubPath, Value);
			return true;
		case SPRITE_SCALE:
			SetSpriteScale(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<vec2>(ValueType, SubPath, Value);
}

template<>
vec4 CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, vec4 DefaultValue) const
{
	switch(ValueType)
	{
		case SPRITE_COLOR:
			return GetSpriteColor(SubPath);
	}
	return CAsset::GetValue<vec4>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, vec4 Value)
{
	switch(ValueType)
	{
		case SPRITE_COLOR:
			SetSpriteColor(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<vec4>(ValueType, SubPath, Value);
}

template<>
CAssetPath CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const
{
	switch(ValueType)
	{
		case SKELETONPATH:
			return GetSkeletonPath();
		case SPRITE_SPRITEPATH:
			return GetSpriteSpritePath(SubPath);
	}
	return CAsset::GetValue<CAssetPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value)
{
	switch(ValueType)
	{
		case SKELETONPATH:
			SetSkeletonPath(Value);
			return true;
		case SPRITE_SPRITEPATH:
			SetSpriteSpritePath(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<CAssetPath>(ValueType, SubPath, Value);
}

template<>
CSubPath CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, CSubPath DefaultValue) const
{
	switch(ValueType)
	{
		case SPRITE_BONEPATH:
			return GetSpriteBonePath(SubPath);
		case SPRITE_LAYERPATH:
			return GetSpriteLayerPath(SubPath);
	}
	return CAsset::GetValue<CSubPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, CSubPath Value)
{
	switch(ValueType)
	{
		case SPRITE_BONEPATH:
			SetSpriteBonePath(SubPath, Value);
			return true;
		case SPRITE_LAYERPATH:
			SetSpriteLayerPath(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<CSubPath>(ValueType, SubPath, Value);
}

int CAsset_SkeletonSkin::AddSubItem(int Type, const CSubPath& SubPath)
{
	switch(Type)
	{
		case TYPE_SPRITE:
			return AddSprite();
	}
	return -1;
}

int CAsset_SkeletonSkin::AddSubItemAt(int Type, const CSubPath& SubPath, int Index)
{
	switch(Type)
	{
		case TYPE_SPRITE:
			AddAtSprite(Index);
			return Index;
	}
	return -1;
}

void CAsset_SkeletonSkin::DeleteSubItem(const CSubPath& SubPath)
{
	switch(SubPath.GetType())
	{
		case TYPE_SPRITE:
			DeleteSprite(SubPath);
			break;
	}
}

void CAsset_SkeletonSkin::RelMoveSubItem(const CSubPath& SubPath, int RelMove)
{
	switch(SubPath.GetType())
	{
		case TYPE_SPRITE:
			RelMoveSprite(SubPath, RelMove);
			break;
	}
}


