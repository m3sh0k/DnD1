#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "FileTreeManager.h"
#include "MapManager.h"
#include "ContextMenuHandler.h"
#include "mapwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupSideMenu();
    setupTreeViews();
    setupConnections();

    // Создание менеджеров
    mapsManager = new FileTreeManager(ui->cart_treeView, QDir::currentPath() + "/map", this);
    mapsManager->setupTreeView();

    monstersManager = new FileTreeManager(ui->monster_treeView, QDir::currentPath() + "/monsters", this);
    monstersManager->setupTreeView();

    spellsManager = new FileTreeManager(ui->spells_treeView, QDir::currentPath() + "/spells", this);
    spellsManager->setupTreeView();

    itemsManager = new FileTreeManager(ui->item_treeView, QDir::currentPath() + "/items", this);
    itemsManager->setupTreeView();

    // Создание менеджера карт
    mapManager = new MapManager(ui->tabWidget, this);

    // Создание обработчиков контекстных меню
    new ContextMenuHandler(ui->cart_treeView, mapsManager->getModel(), this);
    new ContextMenuHandler(ui->monster_treeView, monstersManager->getModel(), this);
    new ContextMenuHandler(ui->spells_treeView, spellsManager->getModel(), this);
    new ContextMenuHandler(ui->item_treeView, itemsManager->getModel(), this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mapsManager;
    delete monstersManager;
    delete spellsManager;
    delete itemsManager;
    delete mapManager;
}

void MainWindow::setupSideMenu()
{
    // Создаем группу кнопок и добавляем кнопки
    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->monsters_pushButton);  // Кнопка "Бестиарий"
    buttonGroup->addButton(ui->spells_pushButton);    // Кнопка "Заклинания"
    buttonGroup->addButton(ui->item_pushButton);      // Кнопка "Предметы"
    buttonGroup->addButton(ui->cart_pushButton);      // Кнопка "Карты"
    buttonGroup->setExclusive(true);                  // Группа делает кнопки эксклюзивными
}

void MainWindow::setupTreeViews()
{
    // Файловые модели уже создаются в FileTreeManager
}

void MainWindow::setupConnections()
{
    connect(ui->cart_treeView, &QTreeView::doubleClicked, this, &MainWindow::onCartTreeViewDoubleClicked);
    connect(ui->monsters_pushButton, &QPushButton::released, this, &MainWindow::on_monsters_pushButton_released);
    connect(ui->spells_pushButton, &QPushButton::released, this, &MainWindow::on_spells_pushButton_released);
    connect(ui->item_pushButton, &QPushButton::released, this, &MainWindow::on_item_pushButton_released);
    connect(ui->cart_pushButton, &QPushButton::released, this, &MainWindow::on_cart_pushButton_released);
}

void MainWindow::on_monsters_pushButton_released()
{
    ui->extended_side_menu->setCurrentIndex(0); // Бестиарий
    ui->extended_side_menu->setVisible(true);
}

void MainWindow::on_spells_pushButton_released()
{
    ui->extended_side_menu->setCurrentIndex(1); // Заклинания
    ui->extended_side_menu->setVisible(true);
}

void MainWindow::on_item_pushButton_released()
{
    ui->extended_side_menu->setCurrentIndex(2); // Предметы
    ui->extended_side_menu->setVisible(true);
}

void MainWindow::on_cart_pushButton_released()
{
    ui->extended_side_menu->setCurrentIndex(3); // Карты
    ui->extended_side_menu->setVisible(true);
}

void MainWindow::onCartTreeViewDoubleClicked(const QModelIndex &index)
{
    // Получаем путь к файлу и передаем его менеджеру карт для открытия
    QString filePath = mapsManager->getModel()->filePath(index);
    mapManager->openMap(filePath);
}
