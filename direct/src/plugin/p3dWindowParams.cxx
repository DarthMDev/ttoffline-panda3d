// Filename: p3dWindowParams.cxx
// Created by:  drose (22Jun09)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#include "p3dWindowParams.h"

////////////////////////////////////////////////////////////////////
//     Function: P3DWindowParams::Default Constructor
//       Access: Public
//  Description: 
////////////////////////////////////////////////////////////////////
P3DWindowParams::
P3DWindowParams() :
  _window_type(P3D_WT_hidden),
  _win_x(0), _win_y(0),
  _win_width(0), _win_height(0)
{
}

////////////////////////////////////////////////////////////////////
//     Function: P3DWindowParams::Constructor
//       Access: Public
//  Description: 
////////////////////////////////////////////////////////////////////
P3DWindowParams::
P3DWindowParams(P3D_window_type window_type,
                int win_x, int win_y,
                int win_width, int win_height,
                P3D_window_handle parent_window) :
  _window_type(window_type),
  _win_x(win_x), _win_y(win_y),
  _win_width(win_width), _win_height(win_height),
  _parent_window(parent_window)
{
}

////////////////////////////////////////////////////////////////////
//     Function: P3DWindowParams::Copy Assignment
//       Access: Public
//  Description: 
////////////////////////////////////////////////////////////////////
void P3DWindowParams::
operator = (const P3DWindowParams &other) {
  _window_type = other._window_type;
  _win_x = other._win_x;
  _win_y = other._win_y;
  _win_width = other._win_width;
  _win_height = other._win_height;
  _parent_window = other._parent_window;
}

////////////////////////////////////////////////////////////////////
//     Function: P3DWindowParams::make_xml
//       Access: Public
//  Description: Returns a newly-allocated XML structure that
//               corresponds to the window parameter data within this
//               instance.
////////////////////////////////////////////////////////////////////
TiXmlElement *P3DWindowParams::
make_xml() {
  TiXmlElement *xwparams = new TiXmlElement("wparams");

  switch (_window_type) {
  case P3D_WT_embedded:
    xwparams->SetAttribute("window_type", "embedded");
    xwparams->SetAttribute("win_x", _win_x);
    xwparams->SetAttribute("win_y", _win_y);
    xwparams->SetAttribute("win_width", _win_width);
    xwparams->SetAttribute("win_height", _win_height);
#ifdef _WIN32
    xwparams->SetAttribute("parent_hwnd", (int)_parent_window._hwnd);
#endif
    break;

  case P3D_WT_toplevel:
    xwparams->SetAttribute("window_type", "toplevel");
    xwparams->SetAttribute("win_x", _win_x);
    xwparams->SetAttribute("win_y", _win_y);
    xwparams->SetAttribute("win_width", _win_width);
    xwparams->SetAttribute("win_height", _win_height);
    break;

  case P3D_WT_fullscreen:
    xwparams->SetAttribute("window_type", "fullscreen");
    xwparams->SetAttribute("win_width", _win_width);
    xwparams->SetAttribute("win_height", _win_height);
    break;

  case P3D_WT_hidden:
    xwparams->SetAttribute("window_type", "hidden");
    break;
  }

  return xwparams;
}