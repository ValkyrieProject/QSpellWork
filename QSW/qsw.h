#pragma once

#include <QMap>
#include <QHash>
#include <QSettings>

#include "blp/BLP.h"
#include "dbc/DBC.h"
#include "mpq/MPQ.h"

#include "settings.h"

typedef QMap<qint64, QString> Enumerator;
typedef QHash<QString, Enumerator> EnumHash;
typedef QMapIterator<qint64, QString> EnumIterator;

namespace QSW {

    static QString VERSION = "2.0.0";

    enum Pages
    {
        PAGE_MAIN       = 0,
        PAGE_CLEFT      = 1,
        PAGE_CRIGHT     = 2,
        PAGE_MAX        = 3
    };

    QJsonSettings& settings();
    EnumHash loadEnumFile(QString fileName);
}
