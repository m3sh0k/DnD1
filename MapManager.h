#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <QWidget>
#include <QTabWidget>
#include "mapwidget.h"  // Подключаем MapWidget

class MapManager : public QObject
{
    Q_OBJECT

public:
    explicit MapManager(QTabWidget *tabWidget, QObject *parent = nullptr);
    void openMap(const QString &filePath);
    void saveMapAsJson(const QString &filePath);

private:
    QTabWidget *tabWidget;
};

#endif // MAPMANAGER_H
