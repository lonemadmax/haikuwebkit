/*
 * Copyright (C) 2007 Ryan Leavengood <leavengood@gmail.com>
 * Copyright (C) 2010 Stephan Aßmus <superstippi@gmx.de>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "config.h"
#include "Cursor.h"

#include "NotImplemented.h"

namespace WebCore {

void Cursor::ensurePlatformCursor() const
{
    if (m_platformCursor)
        return;

    BCursorID which;
    switch(m_type)
    {
        case Cursor::Type::Pointer:
            which = B_CURSOR_ID_SYSTEM_DEFAULT;
            break;
        case Cursor::Type::Hand:
            which = B_CURSOR_ID_FOLLOW_LINK;
            break;
        case Cursor::Type::Cross:
        case Cursor::Type::Cell:
            which = B_CURSOR_ID_CROSS_HAIR;
            break;
        case Cursor::Type::IBeam:
            which = B_CURSOR_ID_I_BEAM;
            break;
        case Cursor::Type::Help:
            which = B_CURSOR_ID_HELP;
            break;
        case Cursor::Type::EastResize:
            which = B_CURSOR_ID_RESIZE_EAST;
            break;
        case Cursor::Type::NorthResize:
            which = B_CURSOR_ID_RESIZE_NORTH;
            break;
        case Cursor::Type::NorthEastResize:
            which = B_CURSOR_ID_RESIZE_NORTH_EAST;
            break;
        case Cursor::Type::NorthWestResize:
            which = B_CURSOR_ID_RESIZE_NORTH_WEST;
            break;
        case Cursor::Type::SouthResize:
            which = B_CURSOR_ID_RESIZE_SOUTH;
            break;
        case Cursor::Type::SouthEastResize:
            which = B_CURSOR_ID_RESIZE_SOUTH_EAST;
            break;
        case Cursor::Type::SouthWestResize:
            which = B_CURSOR_ID_RESIZE_SOUTH_WEST;
            break;
        case Cursor::Type::WestResize:
            which = B_CURSOR_ID_RESIZE_WEST;
            break;
        case Cursor::Type::NorthSouthResize:
        case Cursor::Type::RowResize:
            which = B_CURSOR_ID_RESIZE_NORTH_SOUTH;
            break;
        case Cursor::Type::EastWestResize:
        case Cursor::Type::ColumnResize:
            which = B_CURSOR_ID_RESIZE_EAST_WEST;
            break;
        case Cursor::Type::NorthEastSouthWestResize:
            which = B_CURSOR_ID_RESIZE_NORTH_EAST_SOUTH_WEST;
            break;
        case Cursor::Type::NorthWestSouthEastResize:
            which = B_CURSOR_ID_RESIZE_NORTH_WEST_SOUTH_EAST;
            break;
        case Cursor::Type::MiddlePanning:
        case Cursor::Type::EastPanning:
        case Cursor::Type::NorthPanning:
        case Cursor::Type::NorthEastPanning:
        case Cursor::Type::NorthWestPanning:
        case Cursor::Type::SouthPanning:
        case Cursor::Type::SouthEastPanning:
        case Cursor::Type::SouthWestPanning:
        case Cursor::Type::WestPanning:
        case Cursor::Type::Grabbing:
            which = B_CURSOR_ID_GRABBING;
            break;
        case Cursor::Type::Move:
            which = B_CURSOR_ID_MOVE;
            break;
        case Cursor::Type::VerticalText:
            which = B_CURSOR_ID_I_BEAM_HORIZONTAL;
            break;
        case Cursor::Type::ContextMenu:
            which = B_CURSOR_ID_CONTEXT_MENU;
            break;
        case Cursor::Type::Alias:
            which = B_CURSOR_ID_CREATE_LINK;
            break;
        case Cursor::Type::Wait:
        case Cursor::Type::Progress:
            which = B_CURSOR_ID_PROGRESS;
            break;
        case Cursor::Type::NoDrop:
        case Cursor::Type::NotAllowed:
            which = B_CURSOR_ID_NOT_ALLOWED;
            break;
        case Cursor::Type::Copy:
            which = B_CURSOR_ID_COPY;
            break;
        case Cursor::Type::None:
            which = B_CURSOR_ID_NO_CURSOR;
            break;
        case Cursor::Type::ZoomIn:
            which = B_CURSOR_ID_ZOOM_IN;
            break;
        case Cursor::Type::ZoomOut:
            which = B_CURSOR_ID_ZOOM_OUT;
            break;
        case Cursor::Type::Grab:
            which = B_CURSOR_ID_GRAB;
            break;
        case Cursor::Type::Custom:
            which = B_CURSOR_ID_SYSTEM_DEFAULT;
            notImplemented();
            // TODO create from bitmap.
            break;
    }

    m_platformCursor = new BCursor(which);
}

} // namespace WebCore

