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

#ifndef __CLIENT_ASSETSEDITOR_VIEWMAP_TRANSFORM__
#define __CLIENT_ASSETSEDITOR_VIEWMAP_TRANSFORM__

#include <editor/gui/view_map.h>
#include <editor/gui/view_map_picker.h>

class CCursorTool_MapTransform : public CCursorTool_MapPicker
{
public:
	enum
	{
		GIZMOTYPE_NONE=0,
		GIZMOTYPE_ROTATION,
		GIZMOTYPE_SCALE,
	};
	
	enum
	{
		DRAGTYPE_NONE=0,
		DRAGTYPE_GIZMO,
		DRAGTYPE_TRANSLATION,
	};
	
protected:
	int m_SelectedGizmo;
	int m_GizmoType;
	int m_DragType;
	vec2 m_ClickDiff;
	bool m_Transformed;
	bool m_FrameTransform;
	int m_Token;
	
protected:
	template<typename ASSET> void OnViewButtonClick_Objects_Impl(int Button);
	void OnViewButtonClick_Entities_Impl(int Button);
	template<typename ASSET> void OnViewMouseMove_Objects_Impl();
	template<typename ASSET> void RenderView_Objects_Impl();
	
public:
	CCursorTool_MapTransform(CViewMap* pViewMap);
	void OnViewButtonClick(int Button) override;
	void OnViewButtonRelease(int Button) override;
	void OnViewMouseMove() override;
	void RenderView() override;
	void Update(bool ParentEnabled) override;
	void OnMouseMove() override;
};

#endif
