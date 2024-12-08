#ifndef CONTEXTMENUHANDLER_H
#define CONTEXTMENUHANDLER_H

#include <QMenu>
#include <QTreeView>
#include <QFileSystemModel>

class ContextMenuHandler : public QObject
{
    Q_OBJECT

public:
    explicit ContextMenuHandler(QTreeView *treeView, QFileSystemModel *model, QObject *parent = nullptr);
    void showContextMenu(const QPoint &pos);

private:
    QTreeView *treeView;
    QFileSystemModel *model;
};

#endif // CONTEXTMENUHANDLER_H
