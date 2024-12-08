/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *extended_side_menu;
    QWidget *monster_page;
    QVBoxLayout *verticalLayout_3;
    QLabel *monster_label;
    QTreeView *monster_treeView;
    QWidget *spells_page;
    QVBoxLayout *verticalLayout_4;
    QLabel *spells_label;
    QTreeView *spells_treeView;
    QWidget *item_page;
    QVBoxLayout *verticalLayout_2;
    QLabel *item_label;
    QTreeView *item_treeView;
    QWidget *cart_page;
    QVBoxLayout *verticalLayout_5;
    QLabel *cart_label;
    QTreeView *cart_treeView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *monsters_pushButton;
    QPushButton *spells_pushButton;
    QPushButton *item_pushButton;
    QPushButton *cart_pushButton;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setContextMenuPolicy(Qt::ContextMenuPolicy::PreventContextMenu);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        extended_side_menu = new QStackedWidget(centralwidget);
        extended_side_menu->setObjectName("extended_side_menu");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(extended_side_menu->sizePolicy().hasHeightForWidth());
        extended_side_menu->setSizePolicy(sizePolicy);
        extended_side_menu->setMinimumSize(QSize(0, 0));
        extended_side_menu->setMaximumSize(QSize(200, 16777215));
        extended_side_menu->setSizeIncrement(QSize(0, 0));
        extended_side_menu->setBaseSize(QSize(0, 0));
        monster_page = new QWidget();
        monster_page->setObjectName("monster_page");
        verticalLayout_3 = new QVBoxLayout(monster_page);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        monster_label = new QLabel(monster_page);
        monster_label->setObjectName("monster_label");

        verticalLayout_3->addWidget(monster_label);

        monster_treeView = new QTreeView(monster_page);
        monster_treeView->setObjectName("monster_treeView");
        monster_treeView->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"    border: none; /* \320\225\321\201\320\273\320\270 \320\275\321\203\320\266\320\275\320\276 \321\203\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\274\320\272\320\270 */"));

        verticalLayout_3->addWidget(monster_treeView);

        extended_side_menu->addWidget(monster_page);
        spells_page = new QWidget();
        spells_page->setObjectName("spells_page");
        verticalLayout_4 = new QVBoxLayout(spells_page);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        spells_label = new QLabel(spells_page);
        spells_label->setObjectName("spells_label");

        verticalLayout_4->addWidget(spells_label);

        spells_treeView = new QTreeView(spells_page);
        spells_treeView->setObjectName("spells_treeView");
        spells_treeView->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"    border: none; /* \320\225\321\201\320\273\320\270 \320\275\321\203\320\266\320\275\320\276 \321\203\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\274\320\272\320\270 */"));

        verticalLayout_4->addWidget(spells_treeView);

        extended_side_menu->addWidget(spells_page);
        item_page = new QWidget();
        item_page->setObjectName("item_page");
        verticalLayout_2 = new QVBoxLayout(item_page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        item_label = new QLabel(item_page);
        item_label->setObjectName("item_label");

        verticalLayout_2->addWidget(item_label);

        item_treeView = new QTreeView(item_page);
        item_treeView->setObjectName("item_treeView");
        item_treeView->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"    border: none; /* \320\225\321\201\320\273\320\270 \320\275\321\203\320\266\320\275\320\276 \321\203\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\274\320\272\320\270 */"));

        verticalLayout_2->addWidget(item_treeView);

        extended_side_menu->addWidget(item_page);
        cart_page = new QWidget();
        cart_page->setObjectName("cart_page");
        verticalLayout_5 = new QVBoxLayout(cart_page);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        cart_label = new QLabel(cart_page);
        cart_label->setObjectName("cart_label");

        verticalLayout_5->addWidget(cart_label);

        cart_treeView = new QTreeView(cart_page);
        cart_treeView->setObjectName("cart_treeView");
        cart_treeView->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        cart_treeView->setStyleSheet(QString::fromUtf8("background: transparent;\n"
"    border: none; /* \320\225\321\201\320\273\320\270 \320\275\321\203\320\266\320\275\320\276 \321\203\320\261\321\200\320\260\321\202\321\214 \321\200\320\260\320\274\320\272\320\270 */"));

        verticalLayout_5->addWidget(cart_treeView);

        extended_side_menu->addWidget(cart_page);

        gridLayout->addWidget(extended_side_menu, 0, 1, 2, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        monsters_pushButton = new QPushButton(widget);
        monsters_pushButton->setObjectName("monsters_pushButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/monster"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        monsters_pushButton->setIcon(icon);
        monsters_pushButton->setIconSize(QSize(40, 40));
        monsters_pushButton->setCheckable(false);
        monsters_pushButton->setFlat(true);

        verticalLayout->addWidget(monsters_pushButton);

        spells_pushButton = new QPushButton(widget);
        spells_pushButton->setObjectName("spells_pushButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/magic"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        spells_pushButton->setIcon(icon1);
        spells_pushButton->setIconSize(QSize(40, 40));
        spells_pushButton->setFlat(true);

        verticalLayout->addWidget(spells_pushButton);

        item_pushButton = new QPushButton(widget);
        item_pushButton->setObjectName("item_pushButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Items"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        item_pushButton->setIcon(icon2);
        item_pushButton->setIconSize(QSize(40, 40));
        item_pushButton->setFlat(true);

        verticalLayout->addWidget(item_pushButton);

        cart_pushButton = new QPushButton(widget);
        cart_pushButton->setObjectName("cart_pushButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/cart"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        cart_pushButton->setIcon(icon3);
        cart_pushButton->setIconSize(QSize(40, 40));
        cart_pushButton->setFlat(true);

        verticalLayout->addWidget(cart_pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");

        gridLayout->addWidget(tabWidget, 0, 2, 2, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        extended_side_menu->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        monster_label->setText(QCoreApplication::translate("MainWindow", "\320\221\320\265\321\201\321\202\320\270\320\260\321\200\320\270\320\271", nullptr));
        spells_label->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\273\320\270\320\275\320\260\320\275\320\270\321\217", nullptr));
        item_label->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\320\274\320\265\321\202\321\213", nullptr));
        cart_label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\260\321\200\321\202\321\213", nullptr));
        monsters_pushButton->setText(QString());
        spells_pushButton->setText(QString());
        item_pushButton->setText(QString());
        cart_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
