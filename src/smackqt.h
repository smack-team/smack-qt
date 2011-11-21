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

#ifndef SMACKQT_H
#define SMACKQT_H

#include "smack-qt_global.h"

#include <QtCore/QString>

namespace SmackQt
{

class SMACKQTSHARED_EXPORT Smack
{
public:
     /*!
       * \brief Constructor
       */
    Smack();

    /*!
      * \brief Destructor
      */
    ~Smack();

    /*!
      * \brief Determine if one context can access another
      * \param subject The subject is the actor that is trying to make the access request
      * \param object This is the resource that is being requested to be accessed
      * \param access The access type that is requested
      * \returns true if permission is allowed, false if denied or if an error occured.
      *
      *  Examples of valid access strings: "r", "w", "rw", "x", "rwx", etc.
      *
      */
    static bool hasAccess(const QString &subject, const QString &object, const QString &access);

    /*!
      * \brief Determine the context that the current process is running as.
      * \returns The context on success or QString() if it could not be found.
      */
    static QString getOwnContext();

    /*!
      * \brief Determine the context of a process on the other end of a socket connection.
      * \param fd The descriptor of the socket
      * \returns The context of the other process or QString() if it could not be found.
      */
    static QString getSocketPeerContext(int fd);

};

} // namespace SmackQt

#endif // SMACKQT_H
