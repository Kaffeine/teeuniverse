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

#ifndef __CLIENT_ASSETS_MAPENTITIES__
#define __CLIENT_ASSETS_MAPENTITIES__

#include <shared/assets/asset.h>
#include <cassert>
#include <vector>
#include <shared/assets/assetpath.h>
#include <shared/tl/algorithm.h>

class CAsset_MapEntities : public CAsset
{
public:
	static const int TypeId = 19;
	
	enum
	{
		TYPE_ENTITY,
	};
	
	static inline CSubPath SubPath_Entity(int Id0) { return CSubPath(TYPE_ENTITY, Id0, 0, 0); }
	
	enum
	{
		NAME = CAsset::NAME,
		PARENTPATH,
		ENTITY_ARRAYSIZE,
		ENTITY_PTR,
		ENTITY_ARRAY,
		ENTITY_TYPEPATH,
		ENTITY_POSITION,
		ENTITY_POSITION_X,
		ENTITY_POSITION_Y,
		ENTITY,
		VISIBILITY,
	};
	
	class CIteratorEntity
	{
	protected:
		int m_Index;
		bool m_Reverse;
	public:
		CIteratorEntity() : m_Index(0), m_Reverse(false) {}
		CIteratorEntity(int Index, bool Reverse) : m_Index(Index), m_Reverse(Reverse) {}
		CIteratorEntity& operator++() { if(m_Reverse) m_Index--; else m_Index++; return *this; }
		CSubPath operator*() { return SubPath_Entity(m_Index); }
		bool operator==(const CIteratorEntity& Iter2) { return Iter2.m_Index == m_Index; }
		bool operator!=(const CIteratorEntity& Iter2) { return Iter2.m_Index != m_Index; }
	};
	
	CIteratorEntity BeginEntity() const { return CIteratorEntity(0, false); }
	CIteratorEntity EndEntity() const { return CIteratorEntity(m_Entity.size(), false); }
	CIteratorEntity ReverseBeginEntity() const { return CIteratorEntity(m_Entity.size()-1, true); }
	CIteratorEntity ReverseEndEntity() const { return CIteratorEntity(-1, true); }
	
	class CEntity
	{
	public:
		class CTuaType_0_1_0
		{
		public:
			CAssetPath::CTuaType m_TypePath;
			CTuaVec2 m_Position;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_MapEntities::CEntity& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType_0_1_0& TuaType);
		};
		
		class CTuaType_0_2_0
		{
		public:
			CAssetPath::CTuaType m_TypePath;
			CTuaVec2 m_Position;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_MapEntities::CEntity& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType_0_2_0& TuaType);
		};
		
		class CTuaType_0_2_1
		{
		public:
			CAssetPath::CTuaType m_TypePath;
			CTuaVec2 m_Position;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_MapEntities::CEntity& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType_0_2_1& TuaType);
		};
		
		class CTuaType_0_2_2
		{
		public:
			CAssetPath::CTuaType m_TypePath;
			CTuaVec2 m_Position;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_MapEntities::CEntity& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType_0_2_2& TuaType);
		};
		
		class CTuaType_0_2_3
		{
		public:
			CAssetPath::CTuaType m_TypePath;
			CTuaVec2 m_Position;
			static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_3& TuaType, CAsset_MapEntities::CEntity& SysType);
			static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities::CEntity& SysType, CTuaType_0_2_3& TuaType);
		};
		
	
	private:
		CAssetPath m_TypePath;
		vec2 m_Position;
	
	public:
		CEntity();
		inline CAssetPath GetTypePath() const { return m_TypePath; }
		
		inline vec2 GetPosition() const { return m_Position; }
		
		inline float GetPositionX() const { return m_Position.x; }
		
		inline float GetPositionY() const { return m_Position.y; }
		
		inline void SetTypePath(const CAssetPath& Value) { m_TypePath = Value; }
		
		inline void SetPosition(vec2 Value) { m_Position = Value; }
		
		inline void SetPositionX(float Value) { m_Position.x = Value; }
		
		inline void SetPositionY(float Value) { m_Position.y = Value; }
		
		void AssetPathOperation(const CAssetPath::COperation& Operation)
		{
			Operation.Apply(m_TypePath);
		}
		
	};
	class CTuaType_0_1_0 : public CAsset::CTuaType_0_1_0
	{
	public:
		CAssetPath::CTuaType m_ParentPath;
		CTuaArray m_Entity;
		tua_uint8 m_Visibility;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_1_0& TuaType, CAsset_MapEntities& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType_0_1_0& TuaType);
	};
	
	class CTuaType_0_2_0 : public CAsset::CTuaType_0_2_0
	{
	public:
		CAssetPath::CTuaType m_ParentPath;
		CTuaArray m_Entity;
		tua_uint8 m_Visibility;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_0& TuaType, CAsset_MapEntities& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType_0_2_0& TuaType);
	};
	
	class CTuaType_0_2_1 : public CAsset::CTuaType_0_2_1
	{
	public:
		CAssetPath::CTuaType m_ParentPath;
		CTuaArray m_Entity;
		tua_uint8 m_Visibility;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_1& TuaType, CAsset_MapEntities& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType_0_2_1& TuaType);
	};
	
	class CTuaType_0_2_2 : public CAsset::CTuaType_0_2_2
	{
	public:
		CAssetPath::CTuaType m_ParentPath;
		CTuaArray m_Entity;
		tua_uint8 m_Visibility;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_2& TuaType, CAsset_MapEntities& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType_0_2_2& TuaType);
	};
	
	class CTuaType_0_2_3 : public CAsset::CTuaType_0_2_3
	{
	public:
		CAssetPath::CTuaType m_ParentPath;
		CTuaArray m_Entity;
		tua_uint8 m_Visibility;
		static void Read(class CAssetsSaveLoadContext* pLoadingContext, const CTuaType_0_2_3& TuaType, CAsset_MapEntities& SysType);
		static void Write(class CAssetsSaveLoadContext* pLoadingContext, const CAsset_MapEntities& SysType, CTuaType_0_2_3& TuaType);
	};
	

private:
	CAssetPath m_ParentPath;
	std::vector<CAsset_MapEntities::CEntity> m_Entity;
	bool m_Visibility;

public:
	virtual ~CAsset_MapEntities() {}
	
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
	
	CAsset_MapEntities();
	inline CAssetPath GetParentPath() const { return m_ParentPath; }
	
	inline int GetEntityArraySize() const { return m_Entity.size(); }
	
	inline const CAsset_MapEntities::CEntity* GetEntityPtr() const { return &(m_Entity.front()); }
	
	inline const std::vector<CAsset_MapEntities::CEntity>& GetEntityArray() const { return m_Entity; }
	inline std::vector<CAsset_MapEntities::CEntity>& GetEntityArray() { return m_Entity; }
	
	inline const CAsset_MapEntities::CEntity& GetEntity(const CSubPath& SubPath) const
	{
		assert(SubPath.GetId() < m_Entity.size());
		{
			return m_Entity[SubPath.GetId()];
		}
	}
	
	inline CAssetPath GetEntityTypePath(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Entity.size())
			return m_Entity[SubPath.GetId()].GetTypePath();
		else return CAssetPath::Null();
	}
	
	inline vec2 GetEntityPosition(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Entity.size())
			return m_Entity[SubPath.GetId()].GetPosition();
		else return 0.0f;
	}
	
	inline float GetEntityPositionX(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Entity.size())
			return m_Entity[SubPath.GetId()].GetPositionX();
		else return 0.0f;
	}
	
	inline float GetEntityPositionY(const CSubPath& SubPath) const
	{
		if(SubPath.GetId() < m_Entity.size())
			return m_Entity[SubPath.GetId()].GetPositionY();
		else return 0.0f;
	}
	
	inline bool GetVisibility() const { return m_Visibility; }
	
	inline void SetParentPath(const CAssetPath& Value) { m_ParentPath = Value; }
	
	inline void SetEntityArraySize(int Value) { m_Entity.resize(Value); }
	
	inline void SetEntity(const CSubPath& SubPath, const CAsset_MapEntities::CEntity& Value)
	{
		if(SubPath.GetId() < m_Entity.size())
		{
			m_Entity[SubPath.GetId()] = Value;
		}
	}
	
	inline void SetEntityTypePath(const CSubPath& SubPath, const CAssetPath& Value)
	{
		if(SubPath.GetId() < m_Entity.size())
			m_Entity[SubPath.GetId()].SetTypePath(Value);
	}
	
	inline void SetEntityPosition(const CSubPath& SubPath, vec2 Value)
	{
		if(SubPath.GetId() < m_Entity.size())
			m_Entity[SubPath.GetId()].SetPosition(Value);
	}
	
	inline void SetEntityPositionX(const CSubPath& SubPath, float Value)
	{
		if(SubPath.GetId() < m_Entity.size())
			m_Entity[SubPath.GetId()].SetPositionX(Value);
	}
	
	inline void SetEntityPositionY(const CSubPath& SubPath, float Value)
	{
		if(SubPath.GetId() < m_Entity.size())
			m_Entity[SubPath.GetId()].SetPositionY(Value);
	}
	
	inline void SetVisibility(bool Value) { m_Visibility = Value; }
	
	inline int AddEntity()
	{
		int Id = m_Entity.size();
		m_Entity.emplace_back();
		return Id;
	}
	
	inline void AddAtEntity(int Index) { m_Entity.insert(m_Entity.begin() + Index, CAsset_MapEntities::CEntity()); }
	
	inline void DeleteEntity(const CSubPath& SubPath) { m_Entity.erase(m_Entity.begin() + SubPath.GetId()); }
	
	inline void RelMoveEntity(const CSubPath& SubPath, int RelMove) { relative_move(m_Entity, SubPath.GetId(), RelMove); }
	
	inline bool IsValidEntity(const CSubPath& SubPath) const { return (SubPath.IsNotNull() && SubPath.GetId() < m_Entity.size()); }
	
	void AssetPathOperation(const CAssetPath::COperation& Operation)
	{
		Operation.Apply(m_ParentPath);
		for(unsigned int i=0; i<m_Entity.size(); i++)
		{
			m_Entity[i].AssetPathOperation(Operation);
		}
	}
	
};

template<> int CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const;
template<> bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, int Value);
template<> bool CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, bool DefaultValue) const;
template<> bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, bool Value);
template<> float CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, float DefaultValue) const;
template<> bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, float Value);
template<> vec2 CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, vec2 DefaultValue) const;
template<> bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, vec2 Value);
template<> CAssetPath CAsset_MapEntities::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const;
template<> bool CAsset_MapEntities::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value);

#endif
