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

    // Загружаем карту
    QPixmap pixmap(filePath);
    if (!pixmap.isNull()) {
        QLabel *mapLabel = new QLabel(mapTab);
        mapLabel->setAlignment(Qt::AlignCenter);
        mapLabel->setPixmap(pixmap.scaled(tabWidget->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

        layout->addWidget(mapLabel);
        mapTab->setLayout(layout);

        // Добавляем вкладку
        tabWidget->addTab(mapTab, fileInfo.fileName());
        tabWidget->setCurrentWidget(mapTab);
    } else {
        QMessageBox::warning(tabWidget, "Ошибка", "Не удалось загрузить карту. Проверьте формат файла.");
        delete mapTab;
    }
}
