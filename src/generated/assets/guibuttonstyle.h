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

#ifndef __CLIENT_ASSETS_GUIBUTTONSTYLE__
#define __CLIENT_ASSETS_GUIBUTTONSTYLE__

#include <shared/assets/asset.h>
#include <shared/assets/assetpath.h>

class CAsset_GuiButtonStyle : public CAsset
{
public:
	static const int TypeId = 3;
	
	enum
	{
		NAME = CAsset::NAME,
		IDLESTYLEPATH,
		MOUSEOVERSTYLEPATH,
		READONLYSTYLEPATH,
		FOCUSSTYLEPATH,
	};
	
	class CTuaType_0_1_0 : public CAsset::CTuaType_0_1_0
	{
	public:
		CAssetPath::CTuaType m_IdleStylePath;
		CAssetPath::CTuaType m_MouseOverStylePath;
		CAssetPath::CTuaType m_ReadOnlyStylePath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_GuiButtonStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiButtonStyle& SysType, CTuaType_0_1_0& TuaType);
	};
	
	class CTuaType_0_2_0 : public CAsset::CTuaType_0_2_0
	{
	public:
		CAssetPath::CTuaType m_IdleStylePath;
		CAssetPath::CTuaType m_MouseOverStylePath;
		CAssetPath::CTuaType m_ReadOnlyStylePath;
		CAssetPath::CTuaType m_FocusStylePath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_GuiButtonStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiButtonStyle& SysType, CTuaType_0_2_0& TuaType);
	};
	
	class CTuaType_0_2_1 : public CAsset::CTuaType_0_2_1
	{
	public:
		CAssetPath::CTuaType m_IdleStylePath;
		CAssetPath::CTuaType m_MouseOverStylePath;
		CAssetPath::CTuaType m_ReadOnlyStylePath;
		CAssetPath::CTuaType m_FocusStylePath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_GuiButtonStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiButtonStyle& SysType, CTuaType_0_2_1& TuaType);
	};
	
	class CTuaType_0_2_2 : public CAsset::CTuaType_0_2_2
	{
	public:
		CAssetPath::CTuaType m_IdleStylePath;
		CAssetPath::CTuaType m_MouseOverStylePath;
		CAssetPath::CTuaType m_ReadOnlyStylePath;
		CAssetPath::CTuaType m_FocusStylePath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_GuiButtonStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiButtonStyle& SysType, CTuaType_0_2_2& TuaType);
	};
	
	class CTuaType_0_2_3 : public CAsset::CTuaType_0_2_3
	{
	public:
		CAssetPath::CTuaType m_IdleStylePath;
		CAssetPath::CTuaType m_MouseOverStylePath;
		CAssetPath::CTuaType m_ReadOnlyStylePath;
		CAssetPath::CTuaType m_FocusStylePath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_3& TuaType, CAsset_GuiButtonStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiButtonStyle& SysType, CTuaType_0_2_3& TuaType);
	};
	

private:
	CAssetPath m_IdleStylePath;
	CAssetPath m_MouseOverStylePath;
	CAssetPath m_ReadOnlyStylePath;
	CAssetPath m_FocusStylePath;

public:
	virtual ~CAsset_GuiButtonStyle() {}
	
	template<typename T>
	T GetValue(int ValueType, const CSubPath& SubPath, T DefaultValue) const
	{
		return CAsset::GetValue<T>(ValueType, SubPath, DefaultValue);
	}
	
	template<typename T>
	bool SetValue(int ValueType, const CSubPath& SubPath, T Value)
	{
		return CAsset::SetValue<T>(ValueType, SubPath, Value);
	}
	
	int AddSubItem(int Type, const CSubPath& SubPath);
	
	int AddSubItemAt(int Type, const CSubPath& SubPath, int Index);
	
	void DeleteSubItem(const CSubPath& SubPath);
	
	void RelMoveSubItem(const CSubPath& SubPath, int RelMove);
	
	inline CAssetPath GetIdleStylePath() const { return m_IdleStylePath; }
	
	inline CAssetPath GetMouseOverStylePath() const { return m_MouseOverStylePath; }
	
	inline CAssetPath GetReadOnlyStylePath() const { return m_ReadOnlyStylePath; }
	
	inline CAssetPath GetFocusStylePath() const { return m_FocusStylePath; }
	
	inline void SetIdleStylePath(const CAssetPath& Value) { m_IdleStylePath = Value; }
	
	inline void SetMouseOverStylePath(const CAssetPath& Value) { m_MouseOverStylePath = Value; }
	
	inline void SetReadOnlyStylePath(const CAssetPath& Value) { m_ReadOnlyStylePath = Value; }
	
	inline void SetFocusStylePath(const CAssetPath& Value) { m_FocusStylePath = Value; }
	
	void AssetPathOperation(const CAssetPath::COperation& Operation)
	{
		Operation.Apply(m_IdleStylePath);
		Operation.Apply(m_MouseOverStylePath);
		Operation.Apply(m_ReadOnlyStylePath);
		Operation.Apply(m_FocusStylePath);
	}
	
};

template<> CAssetPath CAsset_GuiButtonStyle::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const;
template<> bool CAsset_GuiButtonStyle::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value);

#endif
