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

#include "connectioncredentialsinterface.h"

#include <QtCore/QList>
#include <QtCore/QVariant>
#include <QtCore/QLatin1String>

using namespace SmackQt;
using namespace SmackQt::Internal;

namespace Constants
{
    //! DBus service
    static const QLatin1String DBusService("org.freedesktop.DBus");
    //! DBus path
    static const QLatin1String DBusPath("/");
    //! The interface the methods belongs to
    const char * const DBusInterface("org.freedesktop.DBus");
    //! The method to call to get the connection label
    static const QLatin1String DBusMethod("GetConnectionCredentials");
    //! The DBus name of the Smack credential
    static const QLatin1String SmackContext("SmackSecurityContext");
}

ConnectionCredentialsInterface::ConnectionCredentialsInterface(QObject *parent)
  : QDBusAbstractInterface(Constants::DBusService, Constants::DBusPath, Constants::DBusInterface,
                           QDBusConnection::sessionBus(), parent)
{
}

ConnectionCredentialsInterface::~ConnectionCredentialsInterface()
{

}

QDBusPendingReply<QVariantMap> ConnectionCredentialsInterface::getConnectionCredentials(const QString &service)
{
    return asyncCall(Constants::DBusMethod, QVariant::fromValue(service));
}

QString ConnectionCredentialsInterface::getSmackContext(const QVariantMap &credentials)
{
    return credentials.value(Constants::SmackContext, QVariant()).toString();
}
