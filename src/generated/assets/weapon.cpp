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

#include <generated/assets/weapon.h>
#include <shared/assets/assetssaveloadcontext.h>
#include <shared/archivefile.h>


void CAsset_Weapon::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_Weapon& SysType)
{
	CAsset::CTuaType::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_CharacterPath, SysType.m_CharacterPath);
	pLoadingContext->ReadAssetPath(TuaType.m_CursorPath, SysType.m_CursorPath);
	pLoadingContext->ReadAssetPath(TuaType.m_SkinPath, SysType.m_SkinPath);
	pLoadingContext->ReadAssetPath(TuaType.m_AttackAnimationPath, SysType.m_AttackAnimationPath);
}

void CAsset_Weapon::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_Weapon& SysType, CTuaType& TuaType)
{
	CAsset::CTuaType::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_CharacterPath, TuaType.m_CharacterPath);
	pLoadingContext->WriteAssetPath(SysType.m_CursorPath, TuaType.m_CursorPath);
	pLoadingContext->WriteAssetPath(SysType.m_SkinPath, TuaType.m_SkinPath);
	pLoadingContext->WriteAssetPath(SysType.m_AttackAnimationPath, TuaType.m_AttackAnimationPath);
}

template<>
CAssetPath CAsset_Weapon::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const
{
	switch(ValueType)
	{
		case CHARACTERPATH:
			return GetCharacterPath();
		case CURSORPATH:
			return GetCursorPath();
		case SKINPATH:
			return GetSkinPath();
		case ATTACKANIMATIONPATH:
			return GetAttackAnimationPath();
	}
	return CAsset::GetValue<CAssetPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_Weapon::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value)
{
	switch(ValueType)
	{
		case CHARACTERPATH:
			SetCharacterPath(Value);
			return true;
		case CURSORPATH:
			SetCursorPath(Value);
			return true;
		case SKINPATH:
			SetSkinPath(Value);
			return true;
		case ATTACKANIMATIONPATH:
			SetAttackAnimationPath(Value);
			return true;
	}
	return CAsset::SetValue<CAssetPath>(ValueType, SubPath, Value);
}

int CAsset_Weapon::AddSubItem(int Type, const CSubPath& SubPath)
{
	return -1;
}


