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

#include "smackqt.h"

#include <sys/smack.h>
#include <stdlib.h>

using namespace SmackQt;

Smack::Smack()
{
}

Smack::~Smack()
{
}

bool Smack::hasAccess(const QString &subject, const QString &object, const QString &access)
{
    return (smack_have_access(subject.toStdString().c_str(), object.toStdString().c_str(), access.toStdString().c_str()) == 1);
}

QString Smack::getOwnContext()
{
    char *label;

    if(smack_new_label_from_self(&label) < 0)
        return QString();

    QString result = QString::fromLatin1(label);

    free(label);
    return result;
}

QString Smack::getSocketPeerContext(int fd)
{
    char *label = NULL;

    if (smack_new_label_from_socket(fd, &label) < 0)
        return QString();

    QString result = QString::fromLatin1(label);

    free(label);
    return result;
}
