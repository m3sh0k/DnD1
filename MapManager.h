#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <QWidget>
#include <QTabWidget>

class MapManager : public QObject
{
    Q_OBJECT

public:
    explicit MapManager(QTabWidget *tabWidget, QObject *parent = nullptr);
    void openMap(const QString &filePath);

private:
    QTabWidget *tabWidget;
};

#endif // MAPMANAGER_H
