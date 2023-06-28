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
 
#ifndef __SHARED_SYSTEM_TIME__
#define __SHARED_SYSTEM_TIME__

#include <chrono>

typedef std::chrono::system_clock CClock;
typedef CClock::duration CTimeDiff;
typedef std::chrono::time_point<CClock, CTimeDiff> CTimePoint;

inline CTimePoint GetCurrentTimePoint()
{
	return CClock::now();
}

inline CTimeDiff GetTimePointDiff(const CTimePoint& a, const CTimePoint& b)
{
	return b-a;
}

inline int64_t GetTimeMsDiff(const CTimePoint& a, const CTimePoint& b)
{
	return std::chrono::duration_cast<std::chrono::milliseconds>(b-a).count();
}

#endif


