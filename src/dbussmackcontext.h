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

#ifndef DBUSSMACKCONTEXT_H
#define DBUSSMACKCONTEXT_H

#include "smack-qt_global.h"

#include <QtCore/QString>

QT_FORWARD_DECLARE_CLASS(QDBusContext)

namespace SmackQt
{


class SMACKQTSHARED_EXPORT DBusSmackContext
{
public:

    /*!
      * \brief Constructor
      */
    DBusSmackContext();

    /*!
      * \brief Destructor
      */
    ~DBusSmackContext();

    /*!
      * \brief Determine the smack context of the remote end of a DBus connection.
      * \param context The DBusContext of the connection.
      * \returns The smack context if it exists or QString() otherwise.
      *
      * \code
      *
      * QString remoteLabel = DBusSmackContext::getCallerSmackContext(*this);
      * QString selfLabel = Smack::getOwnContext();
      *
      * if (Smack::hasAccess(remoteLabel, selfLabel, QLatin1String("W")))
      *     DoWriteTask();
      *
      * if (Smack::hasAccess(remoteLabel, selfLabel, QLatin1String("X")))
      *     DoExecTask();
      *
      * \endcode
      */
    static QString getCallerSmackContext(const QDBusContext &context);

    /*!
      * \brief A convenience function to determine if the remote end has access to access the object.
      * \param context The DBusContext of the connection.
      * \param object The context of the object that is being accessed.
      * \param access The type of access being requested
      * \returns true if allowed, false otherwise.
      *
      * NB This is a convenience for a one time call, if you require to perform multiple tests against the remote context
      * you should use \ref getCallerSmackContext().
      *
      * \code
      * if (DBusSmackContext::hasCallerAccess(*this, QLatin1String("Object_Label"), QLatin1String("rw"))
      *     DoSomething();
      * \endcode
      *
      */
    static bool hasCallerAccess(const QDBusContext &context, const QString &object, const QString &access);
};

} // namespace SmackQt

#endif // DBUSSMACKCONTEXT_H
