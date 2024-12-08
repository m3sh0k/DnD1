#ifndef FILETREEMANAGER_H
#define FILETREEMANAGER_H

#include <QFileSystemModel>
#include <QTreeView>

class FileTreeManager : public QObject
{
    Q_OBJECT

public:
    FileTreeManager(QTreeView *treeView, const QString &rootPath, QObject *parent = nullptr);
    void setupTreeView();
    QFileSystemModel *getModel() const;

private:
    QTreeView *treeView;
    QFileSystemModel *model;
    QString rootPath;
};

#endif // FILETREEMANAGER_H
