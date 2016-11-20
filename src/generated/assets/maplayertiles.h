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

#ifndef __CLIENT_ASSETS_MAPLAYERTILES__
#define __CLIENT_ASSETS_MAPLAYERTILES__

#include <shared/assets/asset.h>
#include <shared/tl/array2d.h>
#include <shared/math/vector.h>
#include <shared/assets/assetpath.h>

class CAsset_MapLayerTiles : public CAsset
{
public:
	enum
	{
		TILEFLAG_VFLIP=1,
		TILEFLAG_HFLIP=2,
		TILEFLAG_OPAQUE=4,
		TILEFLAG_ROTATE=8,
	};
	
	static const int TypeId = 17;
	
	enum
	{
		TYPE_TILE,
	};
	
	static inline CSubPath SubPath_Tile(int Id0, int Id1) { return CSubPath(TYPE_TILE, Id0, Id1, 0); }
	
	enum
	{
		NAME = CAsset::NAME,
		IMAGEPATH,
		COLOR,
		TILE_WIDTH,
		TILE_HEIGHT,
		TILE_PTR,
		TILE_ARRAY,
		TILE_INDEX,
		TILE_FLAGS,
		TILE,
	};
	
	class CTile
	{
	public:
		class CTuaType
		{
		public:
			tua_uint8 m_Index;
			tua_uint8 m_Flags;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_MapLayerTiles::CTile& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles::CTile& SysType, CTuaType& TuaType);
		};
		
	
	private:
		uint8 m_Index;
		uint8 m_Flags;
	
	public:
		CTile();
		void copy(const CAsset_MapLayerTiles::CTile& Item)
		{
			m_Index = Item.m_Index;
			m_Flags = Item.m_Flags;
		}
		
		void transfert(CAsset_MapLayerTiles::CTile& Item)
		{
			m_Index = Item.m_Index;
			m_Flags = Item.m_Flags;
		}
		
		inline uint8 GetIndex() const { return m_Index; }
		
		inline uint8 GetFlags() const { return m_Flags; }
		
		inline void SetIndex(uint8 Value) { m_Index = Value; }
		
		inline void SetFlags(uint8 Value) { m_Flags = Value; }
		
		void AssetPathOperation(const CAssetPath::COperation& Operation)
		{
		}
		
	};
	class CTuaType : public CAsset::CTuaType
	{
	public:
		CAssetPath::CTuaType m_ImagePath;
		tua_uint32 m_Color;
		CTuaArray2d m_Tile;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_MapLayerTiles& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapLayerTiles& SysType, CTuaType& TuaType);
	};
	

private:
	CAssetPath m_ImagePath;
	vec4 m_Color;
	array2d< CTile, allocator_copy<CTile> > m_Tile;

public:
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
	
	CAsset_MapLayerTiles();
	void copy(const CAsset_MapLayerTiles& Item)
	{
		CAsset::copy(Item);
		m_ImagePath = Item.m_ImagePath;
		m_Color = Item.m_Color;
		m_Tile.copy(Item.m_Tile);
	}
	
	void transfert(CAsset_MapLayerTiles& Item)
	{
		CAsset::transfert(Item);
		m_ImagePath = Item.m_ImagePath;
		m_Color = Item.m_Color;
		m_Tile.transfert(Item.m_Tile);
	}
	
	inline CAssetPath GetImagePath() const { return m_ImagePath; }
	
	inline vec4 GetColor() const { return m_Color; }
	
	inline int GetTileWidth() const { return m_Tile.get_width(); }
	
	inline int GetTileHeight() const { return m_Tile.get_height(); }
	
	inline const CAsset_MapLayerTiles::CTile* GetTilePtr() const { return m_Tile.base_ptr(); }
	
	inline const array2d< CTile, allocator_copy<CTile> >& GetTileArray() const { return m_Tile; }
	inline array2d< CTile, allocator_copy<CTile> >& GetTileArray() { return m_Tile; }
	
	inline const CAsset_MapLayerTiles::CTile& GetTile(const CSubPath& SubPath) const { return m_Tile.get_clamp(SubPath.GetId(), SubPath.GetId2()); }
	
	inline uint8 GetTileIndex(const CSubPath& SubPath) const { return m_Tile.get_clamp(SubPath.GetId(), SubPath.GetId2()).GetIndex(); }
	
	inline uint8 GetTileFlags(const CSubPath& SubPath) const { return m_Tile.get_clamp(SubPath.GetId(), SubPath.GetId2()).GetFlags(); }
	
	inline void SetImagePath(const CAssetPath& Value) { m_ImagePath = Value; }
	
	inline void SetColor(vec4 Value) { m_Color = Value; }
	
	inline void SetTileWidth(int Value) { m_Tile.resize_width(Value); }
	
	inline void SetTileHeight(int Value) { m_Tile.resize_height(Value); }
	
	inline void SetTile(const CSubPath& SubPath, const CAsset_MapLayerTiles::CTile& Value) { m_Tile.set_clamp(SubPath.GetId(), SubPath.GetId2(), Value); }
	
	inline void SetTileIndex(const CSubPath& SubPath, uint8 Value) { m_Tile.get_clamp(SubPath.GetId(), SubPath.GetId2()).SetIndex(Value); }
	
	inline void SetTileFlags(const CSubPath& SubPath, uint8 Value) { m_Tile.get_clamp(SubPath.GetId(), SubPath.GetId2()).SetFlags(Value); }
	
	void AssetPathOperation(const CAssetPath::COperation& Operation)
	{
		Operation.Apply(m_ImagePath);
		for(int i=0; i<m_Tile.get_linear_size(); i++)
		{
			m_Tile.linear_get_clamp(i).AssetPathOperation(Operation);
		}
	}
	
};

#endif
