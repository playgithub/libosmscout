/*
 OSMScout - a Qt backend for libosmscout and libosmscout-map
 Copyright (C) 2018 Lukas Karas

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 */

#ifndef OSMSCOUT_CLIENT_QT_NAVIGATIONMODEL_H
#define OSMSCOUT_CLIENT_QT_NAVIGATIONMODEL_H

#include <osmscout/NavigationModule.h>

#include <osmscout/private/ClientQtImportExport.h>

#include <QObject>

/**
 * Model providing navigation functionality to QML.
 * Main logic sits in osmscout::Navigation class and its Qt wrapper NavigationModule.
 *
 * \ingroup QtAPI
 */
class OSMSCOUT_CLIENT_QT_API NavigationModel : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool knownPosition   READ isPositionKnown  NOTIFY update)

signals:
  void update();

public slots:
  void locationChanged(bool locationValid,
                       double lat, double lon,
                       bool horizontalAccuracyValid, double horizontalAccuracy);
public:
  NavigationModel();

  virtual ~NavigationModel();

  bool isPositionKnown();

private:
  NavigationModule* navigationModule;
};

#endif //OSMSCOUT_CLIENT_QT_NAVIGATIONMODEL_H
