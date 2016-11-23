/*
 * Copyright (C) 2016 necropotame (necropotame@gmail.com)
 * 
 * This file is part of TeeUniverses.
 * 
 * TeeUniverses is free software: you can redistribute it and/or  modify
 * it under the terms of the GNU Affero General Public License, version 3,
 * as published by the Free Software Foundation.
 *
 * TeeUniverses is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with TeeUniverses.  If not, see <http://www.gnu.org/licenses/>.
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

#include <generated/assets/mapentities.h>
#include <shared/assets/assetssaveloadcontext.h>
#include <shared/archivefile.h>

CAsset_MapEntities::CEntity::CEntity()
{
	m_Position = 0.0f;
}


void CAsset_MapEntities::CEntity::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_MapEntities::CEntity& SysType)
{
	pLoadingContext->ReadAssetPath(TuaType.m_TypePath, SysType.m_TypePath);
	SysType.m_Position.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_X);
	SysType.m_Position.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Position.m_Y);
}

void CAsset_MapEntities::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_MapEntities& SysType)
{
	CAsset::CTuaType::Read(pLoadingContext, TuaType, SysType);

	{
		const CAsset_MapEntities::CEntity::CTuaType* pData = (const CAsset_MapEntities::CEntity::CTuaType*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_Entity.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_Entity.m_Size);
		SysType.m_Entity.resize(Size);
		for(int i=0; i<Size; i++)
		{
			CAsset_MapEntities::CEntity::CTuaType::Read(pLoadingContext, pData[i], SysType.m_Entity[i]);
		}
	}
	
}

void CAsset_MapEntities::CEntity::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType& TuaType)
{
	pLoadingContext->WriteAssetPath(SysType.m_TypePath, TuaType.m_TypePath);
	TuaType.m_Position.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.x);
	TuaType.m_Position.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Position.y);
}

void CAsset_MapEntities::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType& TuaType)
{
	CAsset::CTuaType::Write(pLoadingContext, SysType, TuaType);

	{
		TuaType.m_Entity.m_Size = SysType.m_Entity.size();
		CAsset_MapEntities::CEntity::CTuaType* pData = new CAsset_MapEntities::CEntity::CTuaType[SysType.m_Entity.size()];
		for(int i=0; i<SysType.m_Entity.size(); i++)
		{
			CAsset_MapEntities::CEntity::CTuaType::Write(pLoadingContext, SysType.m_Entity[i], pData[i]);
		}
		TuaType.m_Entity.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_MapEntities::CEntity::CTuaType)*SysType.m_Entity.size());
		delete[] pData;
	}
}

template<>
int CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const
{
	switch(ValueType)
	{
		case ENTITY_ARRAYSIZE:
			return GetEntityArraySize();
	}
	return CAsset::GetValue<int>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, int Value)
{
	switch(ValueType)
	{
		case ENTITY_ARRAYSIZE:
			SetEntityArraySize(Value);
			return true;
	}
	return CAsset::SetValue<int>(ValueType, SubPath, Value);
}

template<>
float CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, float DefaultValue) const
{
	switch(ValueType)
	{
		case ENTITY_POSITION_X:
			return GetEntityPositionX(SubPath);
		case ENTITY_POSITION_Y:
			return GetEntityPositionY(SubPath);
	}
	return CAsset::GetValue<float>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, float Value)
{
	switch(ValueType)
	{
		case ENTITY_POSITION_X:
			SetEntityPositionX(SubPath, Value);
			return true;
		case ENTITY_POSITION_Y:
			SetEntityPositionY(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<float>(ValueType, SubPath, Value);
}

template<>
vec2 CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, vec2 DefaultValue) const
{
	switch(ValueType)
	{
		case ENTITY_POSITION:
			return GetEntityPosition(SubPath);
	}
	return CAsset::GetValue<vec2>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, vec2 Value)
{
	switch(ValueType)
	{
		case ENTITY_POSITION:
			SetEntityPosition(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<vec2>(ValueType, SubPath, Value);
}

template<>
CAssetPath CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const
{
	switch(ValueType)
	{
		case ENTITY_TYPEPATH:
			return GetEntityTypePath(SubPath);
	}
	return CAsset::GetValue<CAssetPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value)
{
	switch(ValueType)
	{
		case ENTITY_TYPEPATH:
			SetEntityTypePath(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<CAssetPath>(ValueType, SubPath, Value);
}

int CAsset_MapEntities::AddSubItem(int Type, const CSubPath& SubPath)
{
	switch(Type)
	{
		case TYPE_ENTITY:
			return AddEntity();
	}
	return -1;
}

