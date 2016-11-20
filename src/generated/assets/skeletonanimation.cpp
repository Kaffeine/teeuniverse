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

#include <generated/assets/skeletonanimation.h>
#include <shared/assets/assetssaveloadcontext.h>
#include <shared/archivefile.h>

CAsset_SkeletonAnimation::CBoneAnimation::CFrame::CFrame()
{
	m_Translation = 0.0f;
	m_Scale = 1.0f;
	m_Angle = 0.0f;
	m_Alignment = BONEALIGN_PARENTBONE;
}

CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CKeyFrame()
{
	m_Time = 0;
}

CAsset_SkeletonAnimation::CBoneAnimation::CBoneAnimation()
{
	m_CycleType = CYCLETYPE_CLAMP;
}

CAsset_SkeletonAnimation::CLayerAnimation::CFrame::CFrame()
{
	m_Color = 1.0f;
	m_State = LAYERSTATE_VISIBLE;
}

CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CKeyFrame()
{
	m_Time = 0;
}

CAsset_SkeletonAnimation::CLayerAnimation::CLayerAnimation()
{
	m_CycleType = CYCLETYPE_CLAMP;
}


void CAsset_SkeletonAnimation::CBoneAnimation::CFrame::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_SkeletonAnimation::CBoneAnimation::CFrame& SysType)
{
	SysType.m_Translation.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_X);
	SysType.m_Translation.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Translation.m_Y);
	SysType.m_Scale.x = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_X);
	SysType.m_Scale.y = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Scale.m_Y);
	SysType.m_Angle = pLoadingContext->ArchiveFile()->ReadFloat(TuaType.m_Angle);
	SysType.m_Alignment = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Alignment);
}

void CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame& SysType)
{
	CAsset_SkeletonAnimation::CBoneAnimation::CFrame::CTuaType::Read(pLoadingContext, TuaType, SysType);

	SysType.m_Time = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Time);
}

void CAsset_SkeletonAnimation::CBoneAnimation::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_SkeletonAnimation::CBoneAnimation& SysType)
{
	{
		const CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CTuaType* pData = (const CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CTuaType*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_KeyFrame.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_KeyFrame.m_Size);
		SysType.m_KeyFrame.resize(Size);
		for(int i=0; i<Size; i++)
		{
			CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CTuaType::Read(pLoadingContext, pData[i], SysType.m_KeyFrame[i]);
		}
	}
	
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_BonePath, SysType.m_BonePath);
	SysType.m_CycleType = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_CycleType);
}

void CAsset_SkeletonAnimation::CLayerAnimation::CFrame::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_SkeletonAnimation::CLayerAnimation::CFrame& SysType)
{
	SysType.m_Color = pLoadingContext->ArchiveFile()->ReadColor(TuaType.m_Color);
	SysType.m_State = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_State);
}

void CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame& SysType)
{
	CAsset_SkeletonAnimation::CLayerAnimation::CFrame::CTuaType::Read(pLoadingContext, TuaType, SysType);

	SysType.m_Time = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_Time);
}

void CAsset_SkeletonAnimation::CLayerAnimation::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_SkeletonAnimation::CLayerAnimation& SysType)
{
	{
		const CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CTuaType* pData = (const CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CTuaType*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_KeyFrame.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_KeyFrame.m_Size);
		SysType.m_KeyFrame.resize(Size);
		for(int i=0; i<Size; i++)
		{
			CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CTuaType::Read(pLoadingContext, pData[i], SysType.m_KeyFrame[i]);
		}
	}
	
	CSubPath::CTuaType::Read(pLoadingContext->ArchiveFile(), TuaType.m_LayerPath, SysType.m_LayerPath);
	SysType.m_CycleType = pLoadingContext->ArchiveFile()->ReadInt32(TuaType.m_CycleType);
}

void CAsset_SkeletonAnimation::CTuaType::Read(CAssetsSaveLoadContext* pLoadingContext, const CTuaType& TuaType, CAsset_SkeletonAnimation& SysType)
{
	CAsset::CTuaType::Read(pLoadingContext, TuaType, SysType);

	pLoadingContext->ReadAssetPath(TuaType.m_SkeletonPath, SysType.m_SkeletonPath);
	{
		const CAsset_SkeletonAnimation::CBoneAnimation::CTuaType* pData = (const CAsset_SkeletonAnimation::CBoneAnimation::CTuaType*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_LocalBoneAnim.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_LocalBoneAnim.m_Size);
		SysType.m_LocalBoneAnim.resize(Size);
		for(int i=0; i<Size; i++)
		{
			CAsset_SkeletonAnimation::CBoneAnimation::CTuaType::Read(pLoadingContext, pData[i], SysType.m_LocalBoneAnim[i]);
		}
	}
	
	{
		const CAsset_SkeletonAnimation::CBoneAnimation::CTuaType* pData = (const CAsset_SkeletonAnimation::CBoneAnimation::CTuaType*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_ParentBoneAnim.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_ParentBoneAnim.m_Size);
		SysType.m_ParentBoneAnim.resize(Size);
		for(int i=0; i<Size; i++)
		{
			CAsset_SkeletonAnimation::CBoneAnimation::CTuaType::Read(pLoadingContext, pData[i], SysType.m_ParentBoneAnim[i]);
		}
	}
	
	{
		const CAsset_SkeletonAnimation::CLayerAnimation::CTuaType* pData = (const CAsset_SkeletonAnimation::CLayerAnimation::CTuaType*) pLoadingContext->ArchiveFile()->GetData(TuaType.m_LayerAnimation.m_Data);
		uint32 Size = pLoadingContext->ArchiveFile()->ReadUInt32(TuaType.m_LayerAnimation.m_Size);
		SysType.m_LayerAnimation.resize(Size);
		for(int i=0; i<Size; i++)
		{
			CAsset_SkeletonAnimation::CLayerAnimation::CTuaType::Read(pLoadingContext, pData[i], SysType.m_LayerAnimation[i]);
		}
	}
	
}

void CAsset_SkeletonAnimation::CBoneAnimation::CFrame::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonAnimation::CBoneAnimation::CFrame& SysType, CTuaType& TuaType)
{
	TuaType.m_Translation.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.x);
	TuaType.m_Translation.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Translation.y);
	TuaType.m_Scale.m_X = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.x);
	TuaType.m_Scale.m_Y = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Scale.y);
	TuaType.m_Angle = pLoadingContext->ArchiveFile()->WriteFloat(SysType.m_Angle);
	TuaType.m_Alignment = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Alignment);
}

void CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame& SysType, CTuaType& TuaType)
{
	CAsset_SkeletonAnimation::CBoneAnimation::CFrame::CTuaType::Write(pLoadingContext, SysType, TuaType);

	TuaType.m_Time = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Time);
}

void CAsset_SkeletonAnimation::CBoneAnimation::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonAnimation::CBoneAnimation& SysType, CTuaType& TuaType)
{
	{
		TuaType.m_KeyFrame.m_Size = SysType.m_KeyFrame.size();
		CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CTuaType* pData = new CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CTuaType[SysType.m_KeyFrame.size()];
		for(int i=0; i<SysType.m_KeyFrame.size(); i++)
		{
			CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CTuaType::Write(pLoadingContext, SysType.m_KeyFrame[i], pData[i]);
		}
		TuaType.m_KeyFrame.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonAnimation::CBoneAnimation::CKeyFrame::CTuaType)*SysType.m_KeyFrame.size());
		delete[] pData;
	}
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_BonePath, TuaType.m_BonePath);
	TuaType.m_CycleType = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_CycleType);
}

void CAsset_SkeletonAnimation::CLayerAnimation::CFrame::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonAnimation::CLayerAnimation::CFrame& SysType, CTuaType& TuaType)
{
	TuaType.m_Color = pLoadingContext->ArchiveFile()->WriteColor(SysType.m_Color);
	TuaType.m_State = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_State);
}

void CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame& SysType, CTuaType& TuaType)
{
	CAsset_SkeletonAnimation::CLayerAnimation::CFrame::CTuaType::Write(pLoadingContext, SysType, TuaType);

	TuaType.m_Time = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_Time);
}

void CAsset_SkeletonAnimation::CLayerAnimation::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonAnimation::CLayerAnimation& SysType, CTuaType& TuaType)
{
	{
		TuaType.m_KeyFrame.m_Size = SysType.m_KeyFrame.size();
		CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CTuaType* pData = new CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CTuaType[SysType.m_KeyFrame.size()];
		for(int i=0; i<SysType.m_KeyFrame.size(); i++)
		{
			CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CTuaType::Write(pLoadingContext, SysType.m_KeyFrame[i], pData[i]);
		}
		TuaType.m_KeyFrame.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonAnimation::CLayerAnimation::CKeyFrame::CTuaType)*SysType.m_KeyFrame.size());
		delete[] pData;
	}
	CSubPath::CTuaType::Write(pLoadingContext->ArchiveFile(), SysType.m_LayerPath, TuaType.m_LayerPath);
	TuaType.m_CycleType = pLoadingContext->ArchiveFile()->WriteInt32(SysType.m_CycleType);
}

void CAsset_SkeletonAnimation::CTuaType::Write(CAssetsSaveLoadContext* pLoadingContext, const CAsset_SkeletonAnimation& SysType, CTuaType& TuaType)
{
	CAsset::CTuaType::Write(pLoadingContext, SysType, TuaType);

	pLoadingContext->WriteAssetPath(SysType.m_SkeletonPath, TuaType.m_SkeletonPath);
	{
		TuaType.m_LocalBoneAnim.m_Size = SysType.m_LocalBoneAnim.size();
		CAsset_SkeletonAnimation::CBoneAnimation::CTuaType* pData = new CAsset_SkeletonAnimation::CBoneAnimation::CTuaType[SysType.m_LocalBoneAnim.size()];
		for(int i=0; i<SysType.m_LocalBoneAnim.size(); i++)
		{
			CAsset_SkeletonAnimation::CBoneAnimation::CTuaType::Write(pLoadingContext, SysType.m_LocalBoneAnim[i], pData[i]);
		}
		TuaType.m_LocalBoneAnim.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonAnimation::CBoneAnimation::CTuaType)*SysType.m_LocalBoneAnim.size());
		delete[] pData;
	}
	{
		TuaType.m_ParentBoneAnim.m_Size = SysType.m_ParentBoneAnim.size();
		CAsset_SkeletonAnimation::CBoneAnimation::CTuaType* pData = new CAsset_SkeletonAnimation::CBoneAnimation::CTuaType[SysType.m_ParentBoneAnim.size()];
		for(int i=0; i<SysType.m_ParentBoneAnim.size(); i++)
		{
			CAsset_SkeletonAnimation::CBoneAnimation::CTuaType::Write(pLoadingContext, SysType.m_ParentBoneAnim[i], pData[i]);
		}
		TuaType.m_ParentBoneAnim.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonAnimation::CBoneAnimation::CTuaType)*SysType.m_ParentBoneAnim.size());
		delete[] pData;
	}
	{
		TuaType.m_LayerAnimation.m_Size = SysType.m_LayerAnimation.size();
		CAsset_SkeletonAnimation::CLayerAnimation::CTuaType* pData = new CAsset_SkeletonAnimation::CLayerAnimation::CTuaType[SysType.m_LayerAnimation.size()];
		for(int i=0; i<SysType.m_LayerAnimation.size(); i++)
		{
			CAsset_SkeletonAnimation::CLayerAnimation::CTuaType::Write(pLoadingContext, SysType.m_LayerAnimation[i], pData[i]);
		}
		TuaType.m_LayerAnimation.m_Data = pLoadingContext->ArchiveFile()->AddData((uint8*) pData, sizeof(CAsset_SkeletonAnimation::CLayerAnimation::CTuaType)*SysType.m_LayerAnimation.size());
		delete[] pData;
	}
}

template<>
int CAsset_SkeletonAnimation::GetValue(int ValueType, const CSubPath& SubPath, int DefaultValue) const
{
	switch(ValueType)
	{
		case LOCALBONEANIM_ARRAYSIZE:
			return GetLocalBoneAnimArraySize();
		case LOCALBONEANIM_KEYFRAME_ARRAYSIZE:
			return GetLocalBoneAnimKeyFrameArraySize(SubPath);
		case LOCALBONEANIM_KEYFRAME_TIME:
			return GetLocalBoneAnimKeyFrameTime(SubPath);
		case LOCALBONEANIM_CYCLETYPE:
			return GetLocalBoneAnimCycleType(SubPath);
		case PARENTBONEANIM_ARRAYSIZE:
			return GetParentBoneAnimArraySize();
		case PARENTBONEANIM_KEYFRAME_ARRAYSIZE:
			return GetParentBoneAnimKeyFrameArraySize(SubPath);
		case PARENTBONEANIM_KEYFRAME_TIME:
			return GetParentBoneAnimKeyFrameTime(SubPath);
		case PARENTBONEANIM_CYCLETYPE:
			return GetParentBoneAnimCycleType(SubPath);
		case LAYERANIMATION_ARRAYSIZE:
			return GetLayerAnimationArraySize();
		case LAYERANIMATION_KEYFRAME_ARRAYSIZE:
			return GetLayerAnimationKeyFrameArraySize(SubPath);
		case LAYERANIMATION_KEYFRAME_TIME:
			return GetLayerAnimationKeyFrameTime(SubPath);
		case LAYERANIMATION_CYCLETYPE:
			return GetLayerAnimationCycleType(SubPath);
	}
	return CAsset::GetValue<int>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_SkeletonAnimation::SetValue(int ValueType, const CSubPath& SubPath, int Value)
{
	switch(ValueType)
	{
		case LOCALBONEANIM_ARRAYSIZE:
			SetLocalBoneAnimArraySize(Value);
			return true;
		case LOCALBONEANIM_KEYFRAME_ARRAYSIZE:
			SetLocalBoneAnimKeyFrameArraySize(SubPath, Value);
			return true;
		case LOCALBONEANIM_KEYFRAME_TIME:
			SetLocalBoneAnimKeyFrameTime(SubPath, Value);
			return true;
		case LOCALBONEANIM_CYCLETYPE:
			SetLocalBoneAnimCycleType(SubPath, Value);
			return true;
		case PARENTBONEANIM_ARRAYSIZE:
			SetParentBoneAnimArraySize(Value);
			return true;
		case PARENTBONEANIM_KEYFRAME_ARRAYSIZE:
			SetParentBoneAnimKeyFrameArraySize(SubPath, Value);
			return true;
		case PARENTBONEANIM_KEYFRAME_TIME:
			SetParentBoneAnimKeyFrameTime(SubPath, Value);
			return true;
		case PARENTBONEANIM_CYCLETYPE:
			SetParentBoneAnimCycleType(SubPath, Value);
			return true;
		case LAYERANIMATION_ARRAYSIZE:
			SetLayerAnimationArraySize(Value);
			return true;
		case LAYERANIMATION_KEYFRAME_ARRAYSIZE:
			SetLayerAnimationKeyFrameArraySize(SubPath, Value);
			return true;
		case LAYERANIMATION_KEYFRAME_TIME:
			SetLayerAnimationKeyFrameTime(SubPath, Value);
			return true;
		case LAYERANIMATION_CYCLETYPE:
			SetLayerAnimationCycleType(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<int>(ValueType, SubPath, Value);
}

template<>
CAssetPath CAsset_SkeletonAnimation::GetValue(int ValueType, const CSubPath& SubPath, CAssetPath DefaultValue) const
{
	switch(ValueType)
	{
		case SKELETONPATH:
			return GetSkeletonPath();
	}
	return CAsset::GetValue<CAssetPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_SkeletonAnimation::SetValue(int ValueType, const CSubPath& SubPath, CAssetPath Value)
{
	switch(ValueType)
	{
		case SKELETONPATH:
			SetSkeletonPath(Value);
			return true;
	}
	return CAsset::SetValue<CAssetPath>(ValueType, SubPath, Value);
}

template<>
CSubPath CAsset_SkeletonAnimation::GetValue(int ValueType, const CSubPath& SubPath, CSubPath DefaultValue) const
{
	switch(ValueType)
	{
		case LOCALBONEANIM_BONEPATH:
			return GetLocalBoneAnimBonePath(SubPath);
		case PARENTBONEANIM_BONEPATH:
			return GetParentBoneAnimBonePath(SubPath);
		case LAYERANIMATION_LAYERPATH:
			return GetLayerAnimationLayerPath(SubPath);
	}
	return CAsset::GetValue<CSubPath>(ValueType, SubPath, DefaultValue);
}

template<>
bool CAsset_SkeletonAnimation::SetValue(int ValueType, const CSubPath& SubPath, CSubPath Value)
{
	switch(ValueType)
	{
		case LOCALBONEANIM_BONEPATH:
			SetLocalBoneAnimBonePath(SubPath, Value);
			return true;
		case PARENTBONEANIM_BONEPATH:
			SetParentBoneAnimBonePath(SubPath, Value);
			return true;
		case LAYERANIMATION_LAYERPATH:
			SetLayerAnimationLayerPath(SubPath, Value);
			return true;
	}
	return CAsset::SetValue<CSubPath>(ValueType, SubPath, Value);
}

int CAsset_SkeletonAnimation::AddSubItem(int Type, const CSubPath& SubPath)
{
	switch(Type)
	{
		case TYPE_LOCALBONEANIM:
			return AddLocalBoneAnim();
		case TYPE_LOCALBONEANIM_KEYFRAME:
			return AddLocalBoneAnimKeyFrame(SubPath);
		case TYPE_PARENTBONEANIM:
			return AddParentBoneAnim();
		case TYPE_PARENTBONEANIM_KEYFRAME:
			return AddParentBoneAnimKeyFrame(SubPath);
		case TYPE_LAYERANIMATION:
			return AddLayerAnimation();
		case TYPE_LAYERANIMATION_KEYFRAME:
			return AddLayerAnimationKeyFrame(SubPath);
	}
	return -1;
}


