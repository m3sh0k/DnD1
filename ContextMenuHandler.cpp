#include "ContextMenuHandler.h"
#include <QAction>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QMessageBox>

ContextMenuHandler::ContextMenuHandler(QTreeView *treeView, QFileSystemModel *model, QObject *parent)
    : QObject(parent), treeView(treeView), model(model)
{
    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(treeView, &QTreeView::customContextMenuRequested, this, &ContextMenuHandler::showContextMenu);
}

void ContextMenuHandler::showContextMenu(const QPoint &pos)
{
    QMenu contextMenu(treeView);
    QAction *addFolderAction = contextMenu.addAction("Добавить папку");
    QAction *addFileAction = contextMenu.addAction("Добавить файл");
    QAction *removeAction = contextMenu.addAction("Удалить");

    QAction *selectedAction = contextMenu.exec(treeView->mapToGlobal(pos));
    QModelIndex index = treeView->indexAt(pos);
    QString parentDirPath = index.isValid() ? model->filePath(index) : QDir::currentPath();
    QDir dir(parentDirPath);

    if (selectedAction == addFolderAction) {
        QString folderName = "Новая папка";
        int counter = 1;
        while (dir.exists(folderName)) {
            folderName = "Новая папка " + QString::number(counter++);
        }
        dir.mkdir(folderName);
    } else if (selectedAction == addFileAction) {
        QString filePath = QFileDialog::getOpenFileName(treeView, tr("Выберите файл"));
        if (filePath.isEmpty()) return;

        QFileInfo fileInfo(filePath);
        QString destinationPath = parentDirPath + "/" + fileInfo.fileName();
        int counter = 1;
        while (QFile::exists(destinationPath)) {
            destinationPath = parentDirPath + "/" + fileInfo.completeBaseName() + "_" + QString::number(counter++) + "." + fileInfo.suffix();
        }

        QFile::copy(filePath, destinationPath);
    } else if (selectedAction == removeAction) {
        if (index.isValid()) {
            QString filePath = model->filePath(index);
            QFileInfo fileInfo(filePath);
            if (fileInfo.isDir()) {
                QDir dir(filePath);
                dir.removeRecursively();
            } else {
                QFile file(filePath);
                file.remove();
            }
        }
    }
}
