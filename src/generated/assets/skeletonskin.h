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

#ifndef __CLIENT_ASSETS_SKELETONSKIN__
#define __CLIENT_ASSETS_SKELETONSKIN__

#include <shared/assets/asset.h>
#include <cassert>
#include <vector>
#include <shared/assets/assetpath.h>
#include <shared/tl/algorithm.h>

class CAsset_SkeletonSkin : public CAsset
{
public:
	enum
	{
		ALIGNMENT_WORLD=0,
		ALIGNMENT_BONE,
	};
	
	static const int TypeId = 24;
	
	enum
	{
		TYPE_SPRITE,
	};
	
	static inline CSubPath SubPath_Sprite(int Id0) { return CSubPath(TYPE_SPRITE, Id0, 0, 0); }
	
	enum
	{
		NAME = CAsset::NAME,
		SKELETONPATH,
		SPRITE_ARRAYSIZE,
		SPRITE_PTR,
		SPRITE_ARRAY,
		SPRITE_SPRITEPATH,
		SPRITE_BONEPATH,
		SPRITE_LAYERPATH,
		SPRITE_ANCHOR,
		SPRITE_TRANSLATION,
		SPRITE_TRANSLATION_X,
		SPRITE_TRANSLATION_Y,
		SPRITE_SCALE,
		SPRITE_SCALE_X,
		SPRITE_SCALE_Y,
		SPRITE_ANGLE,
		SPRITE_COLOR,
		SPRITE_ALIGNMENT,
		SPRITE,
	};
	
	class CIteratorSprite
	{
	protected:
		int m_Index;
		bool m_Reverse;
	public:
		CIteratorSprite() : m_Index(0), m_Reverse(false) {}
		CIteratorSprite(int Index, bool Reverse) : m_Index(Index), m_Reverse(Reverse) {}
		CIteratorSprite& operator++() { if(m_Reverse) m_Index--; else m_Index++; return *this; }
		CSubPath operator*() { return SubPath_Sprite(m_Index); }
		bool operator==(const CIteratorSprite& Iter2) { return Iter2.m_Index == m_Index; }
		bool operator!=(const CIteratorSprite& Iter2) { return Iter2.m_Index != m_Index; }
	};
	
	CIteratorSprite BeginSprite() const { return CIteratorSprite(0, false); }
	CIteratorSprite EndSprite() const { return CIteratorSprite(m_Sprite.size(), false); }
	CIteratorSprite ReverseBeginSprite() const { return CIteratorSprite(m_Sprite.size()-1, true); }
	CIteratorSprite ReverseEndSprite() const { return CIteratorSprite(-1, true); }
	
	class CSprite
	{
	public:
		class CTuaType_0_2_0
		{
		public:
			CAssetPath::CTuaType m_SpritePath;
			CSubPath::CTuaType m_BonePath;
			CSubPath::CTuaType m_LayerPath;
			tua_float m_Anchor;
			CTuaVec2 m_Translation;
			CTuaVec2 m_Scale;
			tua_float m_Angle;
			tua_uint32 m_Color;
			tua_int32 m_Alignment;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_SkeletonSkin::CSprite& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CSprite& SysType, CTuaType_0_2_0& TuaType);
		};
		
		class CTuaType_0_2_1
		{
		public:
			CAssetPath::CTuaType m_SpritePath;
			CSubPath::CTuaType m_BonePath;
			CSubPath::CTuaType m_LayerPath;
			tua_float m_Anchor;
			CTuaVec2 m_Translation;
			CTuaVec2 m_Scale;
			tua_float m_Angle;
			tua_uint32 m_Color;
			tua_int32 m_Alignment;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_SkeletonSkin::CSprite& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CSprite& SysType, CTuaType_0_2_1& TuaType);
		};
		
		class CTuaType_0_2_2
		{
		public:
			CAssetPath::CTuaType m_SpritePath;
			CSubPath::CTuaType m_BonePath;
			CSubPath::CTuaType m_LayerPath;
			tua_float m_Anchor;
			CTuaVec2 m_Translation;
			CTuaVec2 m_Scale;
			tua_float m_Angle;
			tua_uint32 m_Color;
			tua_int32 m_Alignment;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_SkeletonSkin::CSprite& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CSprite& SysType, CTuaType_0_2_2& TuaType);
		};
		
		class CTuaType_0_2_3
		{
		public:
			CAssetPath::CTuaType m_SpritePath;
			CSubPath::CTuaType m_BonePath;
			CSubPath::CTuaType m_LayerPath;
			tua_float m_Anchor;
			CTuaVec2 m_Translation;
			CTuaVec2 m_Scale;
			tua_float m_Angle;
			tua_uint32 m_Color;
			tua_int32 m_Alignment;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_3& TuaType, CAsset_SkeletonSkin::CSprite& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CSprite& SysType, CTuaType_0_2_3& TuaType);
		};
		
		class CTuaType_0_2_4
		{
		public:
			CAssetPath::CTuaType m_SpritePath;
			CSubPath::CTuaType m_BonePath;
			CSubPath::CTuaType m_LayerPath;
			tua_float m_Anchor;
			CTuaVec2 m_Translation;
			CTuaVec2 m_Scale;
			tua_float m_Angle;
			tua_uint32 m_Color;
			tua_int32 m_Alignment;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_4& TuaType, CAsset_SkeletonSkin::CSprite& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CSprite& SysType, CTuaType_0_2_4& TuaType);
		};
		
		class CTuaType_0_3_0
		{
		public:
			CAssetPath::CTuaType m_SpritePath;
			CSubPath::CTuaType m_BonePath;
			CSubPath::CTuaType m_LayerPath;
			tua_float m_Anchor;
			CTuaVec2 m_Translation;
			CTuaVec2 m_Scale;
			tua_float m_Angle;
			tua_uint32 m_Color;
			tua_int32 m_Alignment;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_3_0& TuaType, CAsset_SkeletonSkin::CSprite& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin::CSprite& SysType, CTuaType_0_3_0& TuaType);
		};
		
	
	private:
		CAssetPath m_SpritePath;
		CSubPath m_BonePath;
		CSubPath m_LayerPath;
		float m_Anchor;
		vec2 m_Translation;
		vec2 m_Scale;
		float m_Angle;
		vec4 m_Color;
		int m_Alignment;
	
	public:
		CSprite();
		CAssetPath GetSpritePath() const { return m_SpritePath; }
		
		CSubPath GetBonePath() const { return m_BonePath; }
		
		CSubPath GetLayerPath() const { return m_LayerPath; }
		
		float GetAnchor() const { return m_Anchor; }
		
		vec2 GetTranslation() const { return m_Translation; }
		
		float GetTranslationX() const { return m_Translation.x; }
		
		float GetTranslationY() const { return m_Translation.y; }
		
		vec2 GetScale() const { return m_Scale; }
		
		float GetScaleX() const { return m_Scale.x; }
		
		float GetScaleY() const { return m_Scale.y; }
		
		float GetAngle() const { return m_Angle; }
		
		vec4 GetColor() const { return m_Color; }
		
		int GetAlignment() const { return m_Alignment; }
		
		void SetSpritePath(const CAssetPath& Value) { m_SpritePath = Value; }
		
		void SetBonePath(const CSubPath& Value) { m_BonePath = Value; }
		
		void SetLayerPath(const CSubPath& Value) { m_LayerPath = Value; }
		
		void SetAnchor(float Value) { m_Anchor = Value; }
		
		void SetTranslation(vec2 Value) { m_Translation = Value; }
		
		void SetTranslationX(float Value) { m_Translation.x = Value; }
		
		void SetTranslationY(float Value) { m_Translation.y = Value; }
		
		void SetScale(vec2 Value) { m_Scale = Value; }
		
		void SetScaleX(float Value) { m_Scale.x = Value; }
		
		void SetScaleY(float Value) { m_Scale.y = Value; }
		
		void SetAngle(float Value) { m_Angle = Value; }
		
		void SetColor(vec4 Value) { m_Color = Value; }
		
		void SetAlignment(int Value) { m_Alignment = Value; }
		
		void AssetPathOperation(const CAssetPath::COperation& Operation)
		{
			Operation.Apply(m_SpritePath);
		}
		
	};
	class CTuaType_0_2_0 : public CAsset::CTuaType_0_2_0
	{
	public:
		CAssetPath::CTuaType m_SkeletonPath;
		CTuaArray m_Sprite;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_SkeletonSkin& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_2_0& TuaType);
	};
	
	class CTuaType_0_2_1 : public CAsset::CTuaType_0_2_1
	{
	public:
		CAssetPath::CTuaType m_SkeletonPath;
		CTuaArray m_Sprite;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_SkeletonSkin& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_2_1& TuaType);
	};
	
	class CTuaType_0_2_2 : public CAsset::CTuaType_0_2_2
	{
	public:
		CAssetPath::CTuaType m_SkeletonPath;
		CTuaArray m_Sprite;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_SkeletonSkin& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_2_2& TuaType);
	};
	
	class CTuaType_0_2_3 : public CAsset::CTuaType_0_2_3
	{
	public:
		CAssetPath::CTuaType m_SkeletonPath;
		CTuaArray m_Sprite;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_3& TuaType, CAsset_SkeletonSkin& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_2_3& TuaType);
	};
	
	class CTuaType_0_2_4 : public CAsset::CTuaType_0_2_4
	{
	public:
		CAssetPath::CTuaType m_SkeletonPath;
		CTuaArray m_Sprite;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_4& TuaType, CAsset_SkeletonSkin& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_2_4& TuaType);
	};
	
	class CTuaType_0_3_0 : public CAsset::CTuaType_0_3_0
	{
	public:
		CAssetPath::CTuaType m_SkeletonPath;
		CTuaArray m_Sprite;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_3_0& TuaType, CAsset_SkeletonSkin& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonSkin& SysType, CTuaType_0_3_0& TuaType);
	};
	

private:
	CAssetPath m_SkeletonPath;
	std::vector<CAsset_SkeletonSkin::CSprite> m_Sprite;

public:
	virtual ~CAsset_SkeletonSkin() {}
	
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
	
	CAssetPath GetSkeletonPath() const { return m_SkeletonPath; }
	
	int GetSpriteArraySize() const { return m_Sprite.size(); }
	
	const CAsset_SkeletonSkin::CSprite* GetSpritePtr() const { return &(m_Sprite.front()); }
	
	const std::vector<CAsset_SkeletonSkin::CSprite>& GetSpriteArray() const { return m_Sprite; }
	std::vector<CAsset_SkeletonSkin::CSprite>& GetSpriteArray() { return m_Sprite; }
	
	const CAsset_SkeletonSkin::CSprite& GetSprite(const CSubPath& SubPath) const
	{
		assert(SubPath.GetId() < m_Sprite.size());
		{
			return m_Sprite[SubPath.GetId()];
		}
	}
	
	CAssetPath GetSpriteSpritePath(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetSpritePath();
		else return CAssetPath::Null();
	}
	
	CSubPath GetSpriteBonePath(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetBonePath();
		else return CSubPath::Null();
	}
	
	CSubPath GetSpriteLayerPath(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetLayerPath();
		else return CSubPath::Null();
	}
	
	float GetSpriteAnchor(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetAnchor();
		else return 0.0f;
	}
	
	vec2 GetSpriteTranslation(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetTranslation();
		else return 0.0f;
	}
	
	float GetSpriteTranslationX(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetTranslationX();
		else return 0.0f;
	}
	
	float GetSpriteTranslationY(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetTranslationY();
		else return 0.0f;
	}
	
	vec2 GetSpriteScale(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetScale();
		else return 0.0f;
	}
	
	float GetSpriteScaleX(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetScaleX();
		else return 0.0f;
	}
	
	float GetSpriteScaleY(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetScaleY();
		else return 0.0f;
	}
	
	float GetSpriteAngle(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetAngle();
		else return 0.0f;
	}
	
	vec4 GetSpriteColor(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetColor();
		else return 1.0f;
	}
	
	int GetSpriteAlignment(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Sprite.size())
			return m_Sprite[SubPath.GetId()].GetAlignment();
		else return 0;
	}
	
	void SetSkeletonPath(const CAssetPath& Value) { m_SkeletonPath = Value; }
	
	void SetSpriteArraySize(int Value) { m_Sprite.resize(Value); }
	
	void SetSprite(const CSubPath& SubPath, const CAsset_SkeletonSkin::CSprite& Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
		{
			m_Sprite[SubPath.GetId()] = Value;
		}
	}
	
	void SetSpriteSpritePath(const CSubPath& SubPath, const CAssetPath& Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetSpritePath(Value);
	}
	
	void SetSpriteBonePath(const CSubPath& SubPath, const CSubPath& Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetBonePath(Value);
	}
	
	void SetSpriteLayerPath(const CSubPath& SubPath, const CSubPath& Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetLayerPath(Value);
	}
	
	void SetSpriteAnchor(const CSubPath& SubPath, float Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetAnchor(Value);
	}
	
	void SetSpriteTranslation(const CSubPath& SubPath, vec2 Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetTranslation(Value);
	}
	
	void SetSpriteTranslationX(const CSubPath& SubPath, float Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetTranslationX(Value);
	}
	
	void SetSpriteTranslationY(const CSubPath& SubPath, float Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetTranslationY(Value);
	}
	
	void SetSpriteScale(const CSubPath& SubPath, vec2 Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetScale(Value);
	}
	
	void SetSpriteScaleX(const CSubPath& SubPath, float Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetScaleX(Value);
	}
	
	void SetSpriteScaleY(const CSubPath& SubPath, float Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetScaleY(Value);
	}
	
	void SetSpriteAngle(const CSubPath& SubPath, float Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetAngle(Value);
	}
	
	void SetSpriteColor(const CSubPath& SubPath, vec4 Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetColor(Value);
	}
	
	void SetSpriteAlignment(const CSubPath& SubPath, int Value)
	{
		if(SubPath.GetId() < m_Sprite.size())
			m_Sprite[SubPath.GetId()].SetAlignment(Value);
	}
	
	int AddSprite()
	{
		int Id = m_Sprite.size();
		m_Sprite.emplace_back();
		return Id;
	}
	
	void AddAtSprite(int Index) { m_Sprite.insert(m_Sprite.begin() + Index, CAsset_SkeletonSkin::CSprite()); }
	
	void DeleteSprite(const CSubPath& SubPath) { m_Sprite.erase(m_Sprite.begin() + SubPath.GetId()); }
	
	void RelMoveSprite(CSubPath& SubPath, int RelMove)
	{
		int NewId = relative_move(m_Sprite, SubPath.GetId(), RelMove);
		SubPath.SetId(NewId);
	}
	
	bool IsValidSprite(const CSubPath& SubPath) const { return (SubPath.IsNotNull() && SubPath.GetId() < m_Sprite.size()); }
	
	void AssetPathOperation(const CAssetPath::COperation& Operation)
	{
		Operation.Apply(m_SkeletonPath);
		for(unsigned int i=0; i<m_Sprite.size(); i++)
		{
			m_Sprite[i].AssetPathOperation(Operation);
		}
	}
	
};

template<> int CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const;
template<> bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, int Value);
template<> float CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, float DefaultValue) const;
template<> bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, float Value);
template<> vec2 CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, vec2 DefaultValue) const;
template<> bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, vec2 Value);
template<> vec4 CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, vec4 DefaultValue) const;
template<> bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, vec4 Value);
template<> CAssetPath CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const;
template<> bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value);
template<> CSubPath CAsset_SkeletonSkin::GetValue(int ValueType, const CSubPath& SubPath, CSubPath DefaultValue) const;
template<> bool CAsset_SkeletonSkin::SetValue(int ValueType, const CSubPath& SubPath, CSubPath Value);

#endif
