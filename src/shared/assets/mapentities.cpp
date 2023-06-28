/*
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

#include <generated/assets/mapentities.h>
#include <generated/assets/skeletonanimation.h>
#include <shared/components/assetsmanager.h>

void CAsset_MapEntities::CEntity::GetTransform(CAssetsManager* pAssetsManager, int64_t Time, matrix2x2* pMatrix, vec2* pPosition) const
{
	*pPosition = m_Pivot;

	float Angle = 0;

	if(m_AnimationPath.IsNotNull())
	{
		const CAsset_SkeletonAnimation* pAnimation = pAssetsManager->GetAsset<CAsset_SkeletonAnimation>(m_AnimationPath);
		if(pAnimation)
		{
			CAsset_SkeletonAnimation::CBoneAnimation::CFrame Frame;
			CSubPath AnimSubPath = pAnimation->FindBoneAnim(CSubPath::Null());
			if(pAnimation->GetBoneAnimFrame(AnimSubPath, Time, Frame))
			{
				*pPosition += Frame.GetTranslation();
				Angle += Frame.GetAngle();
			}
		}
	}
	
	*pMatrix = matrix2x2::rotation(Angle);
}

void CAsset_MapEntities::GetEntityTransform(const CSubPath& SubPath, int64_t Time, matrix2x2* pMatrix, vec2* pPosition) const
{
	m_Entity[SubPath.GetId()].GetTransform(AssetsManager(), Time, pMatrix, pPosition);
}
