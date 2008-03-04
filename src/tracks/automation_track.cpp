#ifndef SINGLE_SOURCE_COMPILE

/*
 * automation_track.cpp - automationTrack handles automation of objects without
 *                        a track
 *
 * Copyright (c) 2006-2008 Javier Serrano Polo <jasp00/at/users.sourceforge.net>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#include "automation_track.h"




automationTrack::automationTrack( trackContainer * _tc ) :
	track( AutomationTrack, _tc )
{
}




automationTrack::~automationTrack()
{
}




bool automationTrack::play( const midiTime & _start, const fpp_t _frames,
				const f_cnt_t _frame_base, Sint16 _tco_num )
{
	sendMidiTime( _start );
	return( FALSE );
}




trackContentObject * automationTrack::createTCO( const midiTime & )
{
	return( NULL );
}




void automationTrack::saveTrackSpecificSettings( QDomDocument & _doc,
							QDomElement & _this )
{
}




void automationTrack::loadTrackSpecificSettings( const QDomElement & _this )
{
}



#endif
