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

#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusConnectionInterface>
#include <QtDBus/QDBusContext>
#include <QScopedPointer>

using namespace SmackQt;

static QString getLabel(const QString &serviceName)
{
    QScopedPointer<Internal::SmackContextInterface> smackIf(new Internal::SmackContextInterface());
    QDBusPendingReply<QString> reply = smackIf->getConnectionSmackContext(serviceName);
    reply.waitForFinished();
    if (!reply.isValid())
        return QString();

    return reply.value();
}

DBusSmackContext::DBusSmackContext()
{
}

DBusSmackContext::~DBusSmackContext()
{
}

QString DBusSmackContext::getCallerSmackContext(const QDBusContext &context)
{
    //Determine the name of the service that has connected to us
    return getLabel(context.message().service());
}

bool DBusSmackContext::hasCallerAccess(const QDBusContext &context, const QString &object, const QString &access)
{
    QString subject = getLabel(context.message().service());

    if (subject.isEmpty())
        return false;

    return Smack::hasAccess(subject, object, access);
}
