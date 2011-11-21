/*
 * This file is part of smack-qt
 *
 * Copyright (C) 2011 Intel Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 * Authors:
 * Brian McGillion <brian.mcgillion@intel.com>
 */

/**
  \mainpage The SmackQt documentation

  This library contains Qt wrappers for some <a href="https://github.com/brianmcgillion/smack">libsmack</a> features:
    \li <a href="../../libsmack-doc/html/index.html">libsmack</a> - Smack Context handling library (\ref SmackQt::Smack "Smack" and \ref SmackQt::DBusSmackContext "DBusSmackContext")

*/

#ifndef SMACKQT_GLOBAL_H
#define SMACKQT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SMACKQT_LIBRARY)
#  define SMACKQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SMACKQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SMACK_GLOBAL_H
