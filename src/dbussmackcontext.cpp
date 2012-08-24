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

#include "dbussmackcontext.h"
#include "smackcontextinterface.h"
#include "smackqt.h"

#include <dbus/dbus.h>
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusContext>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusConnectionInterface>
#include <QtCore/QScopedPointer>

using namespace SmackQt;

static QString getLabel(const QString &serviceName, QString *error)
{
    QScopedPointer<Internal::SmackContextInterface> smackIf(new Internal::SmackContextInterface());
    QDBusPendingReply<QString> reply = smackIf->getConnectionSmackContext(serviceName);
    reply.waitForFinished();
    if (!reply.isValid())
    {
        if (error)
        {
            error->clear();
            error->append(reply.error().message());
        }
        return QString();
    }

    return reply.value();
}

DBusSmackContext::DBusSmackContext()
{
}

DBusSmackContext::~DBusSmackContext()
{
}

QString DBusSmackContext::getCallerSmackContext(const QDBusMessage &message, QString *error)
{
    //Determine the name of the service that has connected to us
    return getLabel(message.service(), error);
}

bool DBusSmackContext::hasCallerAccess(const QDBusMessage &message, const QString &object, const QString &access, QString *error)
{
    QString subject = getLabel(message.service(), error);

    if (subject.isEmpty())
        return false;

    return Smack::hasAccess(subject, object, access);
}

int SmackQt::DBusSmackContext::getConnectionSocketFd(const QDBusContext &context, QString *error)
{
    int fd = -1;
    QDBusConnection conn = context.connection();
    DBusConnection *raw_conn = reinterpret_cast<DBusConnection *>(conn.internalPointer());

    dbus_bool_t result = dbus_connection_get_unix_fd(raw_conn, &fd);

    if (!result)
    {
        if (error)
        {
            error->clear();
            error->append("Failed to find the socket from the connection");
            return -1;
        }
    }

    return fd;
}

QString SmackQt::DBusSmackContext::getPeerSmackContext(const QDBusContext &context, QString *error)
{
    int fd = DBusSmackContext::getConnectionSocketFd(context, error);
    if (fd < 0)
        return QString();

    return Smack::getSocketPeerContext(fd);
}
