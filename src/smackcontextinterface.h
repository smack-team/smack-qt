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

#ifndef SMACKCONTEXTINTERFACE_H
#define SMACKCONTEXTINTERFACE_H

#include <QDBusAbstractInterface>
#include <QDBusPendingReply>
#include <QString>

namespace SmackQt
{
namespace Internal
{

 /*!
   * \class SmackContextInterface
   *
   * Connect to the DBus server and query for the Smack context of a service.
   */
class SmackContextInterface : public QDBusAbstractInterface
{
    Q_OBJECT

public:

    /*!
      * \Constructor
      * \param parent The optional parent object
      */
    explicit SmackContextInterface(QObject *parent = 0);

  /*!
    * \brief Destructor
    */
  ~SmackContextInterface();

public Q_SLOTS: // METHODS

  /*!
    * \brief Get DBus connection Smack context
    * \param service Service name of the remote end
    * \returns The label of the connection if it exists
    */
  QDBusPendingReply<QString> getConnectionSmackContext(const QString &service);
};

} //namespace Internal
} //namespace SmackQt

#endif // SMACKCONTEXTINTERFACE_H
