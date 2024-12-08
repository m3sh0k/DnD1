#include "MapManager.h"
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFileInfo>

MapManager::MapManager(QTabWidget *tabWidget, QObject *parent)
    : QObject(parent), tabWidget(tabWidget)
{
}

void MapManager::openMap(const QString &filePath)
{
    QFileInfo fileInfo(filePath);
    if (!fileInfo.exists() || !fileInfo.isFile()) {
        QMessageBox::warning(tabWidget, "Ошибка", "Не удалось найти карту.");
        return;
    }

    // Создаем новую вкладку
    QWidget *mapTab = new QWidget(tabWidget);
    QVBoxLayout *layout = new QVBoxLayout(mapTab);

    // Создаем MapWidget
    MapWidget *mapWidget = new MapWidget(mapTab);
    mapWidget->setImage(QImage(filePath));  // Загружаем изображение в MapWidget

    layout->addWidget(mapWidget);  // Добавляем MapWidget на вкладку
    mapTab->setLayout(layout);

    // Добавляем вкладку
    tabWidget->addTab(mapTab, fileInfo.fileName());
    tabWidget->setCurrentWidget(mapTab);
}

void MapManager::saveMapAsJson(const QString &filePath)
{
    // Получаем текущий виджет карты
    QWidget *currentWidget = tabWidget->currentWidget();
    if (currentWidget) {
        MapWidget *mapWidget = dynamic_cast<MapWidget*>(currentWidget->layout()->itemAt(0)->widget());
        if (mapWidget) {
            mapWidget->saveImageAsJson(filePath);  // Сохраняем в JSON
        }
    }
}
