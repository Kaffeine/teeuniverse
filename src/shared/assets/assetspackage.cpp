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

#include <shared/assets/assetspackage.h>
#include <shared/components/assetsmanager.h>

CAssetsPackage::CAssetsPackage() :
	m_State(STATE_CREATED),
	m_ReadOnly(true),
	m_Edited(false)
{
	
}

void CAssetsPackage::InitAssetState(const CAssetState& State)
{
	#define MACRO_ASSETTYPE(Name) m_##Name.InitAssetState(State);
	#include <generated/assets/assetsmacro.h>
	#undef MACRO_ASSETTYPE
}
	
void CAssetsPackage::Load_AssetsFile(class CAssetsSaveLoadContext* pLoadingContext)
{
	m_State = STATE_JUST_LOADED;
	
	CTuaType_Info* pItem = reinterpret_cast<CTuaType_Info*>(pLoadingContext->ArchiveFile()->GetItem(0, 0));
	if(!pItem)
		return;
	
	int AssetsVersion = pLoadingContext->ArchiveFile()->ReadUInt32(pItem->m_AssetsVersion);
	if(AssetsVersion < 0 || AssetsVersion >= ASSETSVERSION_NOT_SUPPORTED)
		return;
	
	m_Author = pLoadingContext->ArchiveFile()->GetString(pItem->m_Author);
	m_Credits = pLoadingContext->ArchiveFile()->GetString(pItem->m_Credits);
	m_License = pLoadingContext->ArchiveFile()->GetString(pItem->m_License);
	m_Version = pLoadingContext->ArchiveFile()->GetString(pItem->m_Version);
	
	//TAG_ASSETSVERSION
	switch(AssetsVersion)
	{
		case ASSETSVERSION_0_2_0:
			#define MACRO_ASSETTYPE(Name) m_##Name.Load_AssetsFile_0_2_0(pLoadingContext);
			#include <generated/assets/assetsmacro.h>
			#undef MACRO_ASSETTYPE
			break;
		case ASSETSVERSION_0_2_1:
			#define MACRO_ASSETTYPE(Name) m_##Name.Load_AssetsFile_0_2_1(pLoadingContext);
			#include <generated/assets/assetsmacro.h>
			#undef MACRO_ASSETTYPE
			break;
		case ASSETSVERSION_0_2_2:
			#define MACRO_ASSETTYPE(Name) m_##Name.Load_AssetsFile_0_2_2(pLoadingContext);
			#include <generated/assets/assetsmacro.h>
			#undef MACRO_ASSETTYPE
			break;
		case ASSETSVERSION_0_2_3:
			#define MACRO_ASSETTYPE(Name) m_##Name.Load_AssetsFile_0_2_3(pLoadingContext);
			#include <generated/assets/assetsmacro.h>
			#undef MACRO_ASSETTYPE
			break;
		case ASSETSVERSION_0_2_4:
			#define MACRO_ASSETTYPE(Name) m_##Name.Load_AssetsFile_0_2_4(pLoadingContext);
			#include <generated/assets/assetsmacro.h>
			#undef MACRO_ASSETTYPE
			break;
		case ASSETSVERSION_0_3_0:
			#define MACRO_ASSETTYPE(Name) m_##Name.Load_AssetsFile_0_3_0(pLoadingContext);
			#include <generated/assets/assetsmacro.h>
			#undef MACRO_ASSETTYPE
			break;
		case ASSETSVERSION_0_3_3:
			#define MACRO_ASSETTYPE(Name) m_##Name.Load_AssetsFile_0_3_3(pLoadingContext);
			#include <generated/assets/assetsmacro.h>
			#undef MACRO_ASSETTYPE
			break;
	}

	if(AssetsVersion < ASSETSVERSION_0_3_3)
	{
		// Fixup Entities pos
		using MapsList = CAssetsList<CAsset_Map, CAssetState>;
		MapsList &Maps = GetList<CAsset_Map>();
		for(MapsList::CEntry &Map : Maps.m_Assets)
		{
			CAsset_Map *pMap = &Map.m_Asset;
			CAsset_Map::CIteratorEntityLayer IterEntityLayer;
			for(IterEntityLayer = pMap->BeginEntityLayer(); IterEntityLayer != pMap->EndEntityLayer(); ++IterEntityLayer)
			{
				CSubPath SubPath = *IterEntityLayer;
				CAssetPath EntitiesPath = pMap->GetEntityLayer(SubPath);
				// Note: EntityLayer ID needs an update after the load and the current value is invalid
				// at this point. The fixup is done in CAssetsManager::Load_AssetsFile() via CAssetPath::COperation::ResolveName
				// Do the fixup manually here.
				EntitiesPath.SetId(SubPath.GetId());

				CAsset_MapEntities *pEntitiesAsset = pMap->AssetsManager()->GetAsset_Hard<CAsset_MapEntities>(EntitiesPath);
				if(!pEntitiesAsset)
					continue;

				std::vector<CAsset_MapEntities::CEntity>& Entities = pEntitiesAsset->GetEntityArray();
				for(CAsset_MapEntities::CEntity &Entity : Entities)
				{
					Entity.SetPivot(Entity.GetPosition());
					Entity.SetPosition(vec2(0, 0));
				}
			}
		}
	}
}
	
void CAssetsPackage::Save_AssetsFile(class CAssetsSaveContext* pLoadingContext)
{
	pLoadingContext->ArchiveFile()->SetItemType(0, sizeof(CTuaType_Info), 1);
	CTuaType_Info* pItem = reinterpret_cast<CTuaType_Info*>(pLoadingContext->ArchiveFile()->GetItem(0, 0));
	const uint32_t FormatVersion = pLoadingContext->FormatVersion();

	pItem->m_AssetsVersion = pLoadingContext->ArchiveFile()->WriteUInt32(FormatVersion);
	pItem->m_Author = pLoadingContext->ArchiveFile()->AddString(m_Author.buffer());
	pItem->m_Credits = pLoadingContext->ArchiveFile()->AddString(m_Credits.buffer());
	pItem->m_License = pLoadingContext->ArchiveFile()->AddString(m_License.buffer());
	pItem->m_Version = pLoadingContext->ArchiveFile()->AddString(m_Version.buffer());

	//TAG_ASSETSVERSION
	if (FormatVersion == ASSETSVERSION_0_3_0)
	{
		#define MACRO_ASSETTYPE(Name) m_##Name.Save_AssetsFile_0_3_0(pLoadingContext);
		#include <generated/assets/assetsmacro.h>
		#undef MACRO_ASSETTYPE
	}
	else
	{
		assert(FormatVersion == ASSETSVERSION_0_3_3);
		#define MACRO_ASSETTYPE(Name) m_##Name.Save_AssetsFile_0_3_3(pLoadingContext);
		#include <generated/assets/assetsmacro.h>
		#undef MACRO_ASSETTYPE
	}

	pLoadingContext->ArchiveFile()->SetItemType(1, sizeof(CAssetsPackage::CTuaType_Dependency), pLoadingContext->Dependencies().size());
	for(unsigned int i = 0; i < pLoadingContext->Dependencies().size(); i++)
	{
		const char* pPackageName = pLoadingContext->AssetsManager()->GetPackageName(pLoadingContext->Dependencies()[i]);
		CAssetsPackage::CTuaType_Dependency* pItem = reinterpret_cast<CAssetsPackage::CTuaType_Dependency*>(pLoadingContext->ArchiveFile()->GetItem(1, i));
		pItem->m_PackageName = pLoadingContext->ArchiveFile()->AddString(pPackageName);
		pItem->m_PackageCrc = pLoadingContext->ArchiveFile()->WriteUInt32(0);
	}
}

void CAssetsPackage::DeleteAsset(const CAssetPath& Path)
{
	#define MACRO_ASSETTYPE(Name) case CAsset_##Name::TypeId:\
		m_##Name.DeleteAsset(Path);\
		break;
	switch(Path.GetType())
	{
		#include <generated/assets/assetsmacro.h>
	}
	#undef MACRO_ASSETTYPE
}

void CAssetsPackage::AssetPathOperation(const CAssetPath::COperation& Operation)
{
	#define MACRO_ASSETTYPE(Name) m_##Name.AssetPathOperation(Operation);
	#include <generated/assets/assetsmacro.h>
	#undef MACRO_ASSETTYPE
}

void CAssetsPackage::SubPathOperation(const CAssetPath& Path, const CSubPath::COperation& Operation)
{
	#define MACRO_ASSETTYPE(Name) m_##Name.SubPathOperation(Path, Operation);
	#include <generated/assets/assetsmacro.h>
	#undef MACRO_ASSETTYPE
}

#define MACRO_ASSETTYPE(Name) template<> CAssetsList<CAsset_##Name, CAssetState>& CAssetsPackage::GetList() { return m_##Name; }
#include <generated/assets/assetsmacro.h>
#undef MACRO_ASSETTYPE

#define MACRO_ASSETTYPE(Name) template<> const CAssetsList<CAsset_##Name, CAssetState>& CAssetsPackage::GetList() const { return m_##Name; }
#include <generated/assets/assetsmacro.h>
#undef MACRO_ASSETTYPE
