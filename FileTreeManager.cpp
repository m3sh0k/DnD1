#include "FileTreeManager.h"
#include <QDir>

FileTreeManager::FileTreeManager(QTreeView *treeView, const QString &rootPath, QObject *parent)
    : QObject(parent), treeView(treeView), rootPath(rootPath)
{
    model = new QFileSystemModel(this);
}

void FileTreeManager::setupTreeView()
{
    model->setRootPath(rootPath);
    treeView->setModel(model);
    treeView->setRootIndex(model->index(rootPath));

    // Скрытие ненужных столбцов
    treeView->hideColumn(1);  // Скрываем "Size"
    treeView->hideColumn(2);  // Скрываем "Type"
    treeView->hideColumn(3);  // Скрываем "Date"
    treeView->setHeaderHidden(true);  // Отключаем заголовки
}

QFileSystemModel *FileTreeManager::getModel() const
{
    return model;
}
