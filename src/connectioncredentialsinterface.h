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

#ifndef CONNECTIONCREDENTIALSINTERFACE_H
#define CONNECTIONCREDENTIALSINTERFACE_H

#include <QtDBus/QDBusAbstractInterface>
#include <QtDBus/QDBusPendingReply>
#include <QtCore/QString>
#include <QtCore/QVariantMap>

namespace SmackQt
{
namespace Internal
{

/*!
   * \class ConnectionCredentialsInterface
   *
   * Connect to the DBus server and query for the Smack context of a service.
   */
class ConnectionCredentialsInterface : public QDBusAbstractInterface
{
    Q_OBJECT

public:

    /*!
      * \Constructor
      * \param parent The optional parent object
      */
    explicit ConnectionCredentialsInterface(QObject *parent = 0);

    /*!
     * \brief Destructor
     */
    ~ConnectionCredentialsInterface();

    /*!
      * \brief Get the Smack context from the connection credentials
      * \param credentials The hash that contains the credentials that has been retrieved from the DBus service
      * \returns the context if it exists or QString otherwise.
      */
    QString getSmackContext(const QVariantMap &credentials);

public Q_SLOTS: // METHODS

    /*!
     * \brief Get DBus connection Security credentials
     * \param service Service name of the remote end
     * \returns All the credentials of the connection if it exists
     */
    QDBusPendingReply<QVariantMap> getConnectionCredentials(const QString &service);
};

} //namespace Internal
} //namespace SmackQt

#endif // CONNECTIONCREDENTIALSINTERFACE_H
