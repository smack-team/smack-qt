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

QT_FORWARD_DECLARE_CLASS(QDBusMessage)
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
      * \param message The DBusMessage that has arrived from the connection.
      * \param error On failure retrieve an error string indicating the problem.
      * \returns The smack context if it exists or QString() otherwise.
      *
      * \code
      *
      * QString remoteLabel = DBusSmackContext::getCallerSmackContext(this->message());
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
    static QString getCallerSmackContext(const QDBusMessage &message, QString *error = 0);

    /*!
      * \brief A convenience function to determine if the remote end has access to access the object.
      * \param message The DBusMessage that has arrived from the connection.
      * \param object The context of the object that is being accessed.
      * \param access The type of access being requested
      * \param error Retrieve an error message indicating the failure if one occurs.
      * \returns true if allowed, false otherwise.
      *
      * NB! This is a convenience for a one time call, if you require to perform multiple tests against the remote context
      * you should use \ref getCallerSmackContext().
      *
      * \code
      * if (DBusSmackContext::hasCallerAccess(this->message(), QLatin1String("Object_Label"), QLatin1String("rw"))
      *     DoSomething();
      * \endcode
      *
      */
    static bool hasCallerAccess(const QDBusMessage &message, const QString &object, const QString &access, QString *error = 0);

    /*!
      * \brief Find the underlying socket file descriptor that is used by a DBus connection
      * \param context The DBus context of the shared connection \sa QDBusContext
      * \param error On failure retrieve an error string indicating the problem.
      * \returns The file descriptor if it exists or -1 on error.
      *
      * DO NOT read or write or call select() on the returned fd, as per the libdbus1 documentation.
      * \sa http://dbus.freedesktop.org/doc/api/html/group_DBusConnection.html
      */
    static int getConnectionSocketFd(const QDBusContext &context, QString *error = 0);

    /*!
      * \brief Determine the Smack Context of the other process in a DBus peer-to-peer connection
      * \param context The DBus context of the shared connection \sa QDBusContext
      * \param error On failure retrieve an error string indicating the problem.
      * \returns The smack context if it exists or QString() otherwise.
      */
    static QString getPeerSmackContext(const QDBusContext &context, QString *error = 0);
};

} // namespace SmackQt

#endif // DBUSSMACKCONTEXT_H
