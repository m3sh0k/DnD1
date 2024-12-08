#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QFileSystemModel>
#include <QTabWidget>
#include <QPushButton>
#include "FileTreeManager.h"
#include "MapManager.h"
#include "ContextMenuHandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    FileTreeManager *mapsManager;
    FileTreeManager *monstersManager;
    FileTreeManager *spellsManager;
    FileTreeManager *itemsManager;

    MapManager *mapManager;

    void setupSideMenu();
    void setupTreeViews();
    void setupConnections();

    // Слоты для кнопок
    void on_monsters_pushButton_released();
    void on_spells_pushButton_released();
    void on_item_pushButton_released();
    void on_cart_pushButton_released();

    // Обработчики для двойного клика
    void onCartTreeViewDoubleClicked(const QModelIndex &index);
};

#endif // MAINWINDOW_H
