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

#ifndef __CLIENT_ASSETS_GUILINESTYLE__
#define __CLIENT_ASSETS_GUILINESTYLE__

#include <shared/assets/asset.h>
#include <shared/math/vector.h>
#include <shared/assets/assetpath.h>

class CAsset_GuiLineStyle : public CAsset
{
public:
	enum
	{
		FLAG_BORDER=1,
		FLAG_IMAGE=2,
	};
	
	static const int TypeId = 7;
	
	enum
	{
		NAME = CAsset::NAME,
		FLAGS,
		BORDERCOLOR,
		IMAGELPATH,
		IMAGEMPATH,
		IMAGERPATH,
	};
	
	class CTuaType_0_2_0 : public CAsset::CTuaType_0_2_0
	{
	public:
		tua_int32 m_Flags;
		tua_uint32 m_BorderColor;
		CAssetPath::CTuaType m_ImageLPath;
		CAssetPath::CTuaType m_ImageMPath;
		CAssetPath::CTuaType m_ImageRPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_GuiLineStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLineStyle& SysType, CTuaType_0_2_0& TuaType);
	};
	
	class CTuaType_0_2_1 : public CAsset::CTuaType_0_2_1
	{
	public:
		tua_int32 m_Flags;
		tua_uint32 m_BorderColor;
		CAssetPath::CTuaType m_ImageLPath;
		CAssetPath::CTuaType m_ImageMPath;
		CAssetPath::CTuaType m_ImageRPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_GuiLineStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLineStyle& SysType, CTuaType_0_2_1& TuaType);
	};
	
	class CTuaType_0_2_2 : public CAsset::CTuaType_0_2_2
	{
	public:
		tua_int32 m_Flags;
		tua_uint32 m_BorderColor;
		CAssetPath::CTuaType m_ImageLPath;
		CAssetPath::CTuaType m_ImageMPath;
		CAssetPath::CTuaType m_ImageRPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_GuiLineStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLineStyle& SysType, CTuaType_0_2_2& TuaType);
	};
	
	class CTuaType_0_2_3 : public CAsset::CTuaType_0_2_3
	{
	public:
		tua_int32 m_Flags;
		tua_uint32 m_BorderColor;
		CAssetPath::CTuaType m_ImageLPath;
		CAssetPath::CTuaType m_ImageMPath;
		CAssetPath::CTuaType m_ImageRPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_3& TuaType, CAsset_GuiLineStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLineStyle& SysType, CTuaType_0_2_3& TuaType);
	};
	
	class CTuaType_0_2_4 : public CAsset::CTuaType_0_2_4
	{
	public:
		tua_int32 m_Flags;
		tua_uint32 m_BorderColor;
		CAssetPath::CTuaType m_ImageLPath;
		CAssetPath::CTuaType m_ImageMPath;
		CAssetPath::CTuaType m_ImageRPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_4& TuaType, CAsset_GuiLineStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLineStyle& SysType, CTuaType_0_2_4& TuaType);
	};
	
	class CTuaType_0_3_0 : public CAsset::CTuaType_0_3_0
	{
	public:
		tua_int32 m_Flags;
		tua_uint32 m_BorderColor;
		CAssetPath::CTuaType m_ImageLPath;
		CAssetPath::CTuaType m_ImageMPath;
		CAssetPath::CTuaType m_ImageRPath;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_3_0& TuaType, CAsset_GuiLineStyle& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_GuiLineStyle& SysType, CTuaType_0_3_0& TuaType);
	};
	

private:
	int m_Flags;
	vec4 m_BorderColor;
	CAssetPath m_ImageLPath;
	CAssetPath m_ImageMPath;
	CAssetPath m_ImageRPath;

public:
	virtual ~CAsset_GuiLineStyle() {}
	
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
	
	void RelMoveSubItem(CSubPath& SubPath, int RelMove);
	
	CAsset_GuiLineStyle();
	int GetFlags() const { return m_Flags; }
	
	vec4 GetBorderColor() const { return m_BorderColor; }
	
	CAssetPath GetImageLPath() const { return m_ImageLPath; }
	
	CAssetPath GetImageMPath() const { return m_ImageMPath; }
	
	CAssetPath GetImageRPath() const { return m_ImageRPath; }
	
	void SetFlags(int Value) { m_Flags = Value; }
	
	void SetBorderColor(vec4 Value) { m_BorderColor = Value; }
	
	void SetImageLPath(const CAssetPath& Value) { m_ImageLPath = Value; }
	
	void SetImageMPath(const CAssetPath& Value) { m_ImageMPath = Value; }
	
	void SetImageRPath(const CAssetPath& Value) { m_ImageRPath = Value; }
	
	void AssetPathOperation(const CAssetPath::COperation& Operation)
	{
		Operation.Apply(m_ImageLPath);
		Operation.Apply(m_ImageMPath);
		Operation.Apply(m_ImageRPath);
	}
	
};

template<> int CAsset_GuiLineStyle::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const;
template<> bool CAsset_GuiLineStyle::SetValue(int ValueType, const CSubPath& SubPath, int Value);
template<> vec4 CAsset_GuiLineStyle::GetValue(int ValueType, const CSubPath& SubPath, vec4 DefaultValue) const;
template<> bool CAsset_GuiLineStyle::SetValue(int ValueType, const CSubPath& SubPath, vec4 Value);
template<> CAssetPath CAsset_GuiLineStyle::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const;
template<> bool CAsset_GuiLineStyle::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value);

#endif
