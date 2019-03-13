/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *help_action;
    QWidget *centralWidget;
    QGraphicsView *view1;
    QGraphicsView *view2;
    QGraphicsView *view3;
    QPushButton *sel1;
    QPushButton *sel2;
    QPushButton *sel3;
    QPushButton *push1;
    QPushButton *push2;
    QPushButton *push3;
    QLabel *count;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(616, 411);
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        MainWindow->setFont(font);
        help_action = new QAction(MainWindow);
        help_action->setObjectName(QString::fromUtf8("help_action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        view1 = new QGraphicsView(centralWidget);
        view1->setObjectName(QString::fromUtf8("view1"));
        view1->setGeometry(QRect(30, 70, 161, 192));
        view2 = new QGraphicsView(centralWidget);
        view2->setObjectName(QString::fromUtf8("view2"));
        view2->setGeometry(QRect(230, 70, 161, 192));
        view3 = new QGraphicsView(centralWidget);
        view3->setObjectName(QString::fromUtf8("view3"));
        view3->setGeometry(QRect(430, 70, 161, 192));
        sel1 = new QPushButton(centralWidget);
        sel1->setObjectName(QString::fromUtf8("sel1"));
        sel1->setGeometry(QRect(30, 30, 161, 31));
        sel2 = new QPushButton(centralWidget);
        sel2->setObjectName(QString::fromUtf8("sel2"));
        sel2->setGeometry(QRect(230, 30, 161, 31));
        sel3 = new QPushButton(centralWidget);
        sel3->setObjectName(QString::fromUtf8("sel3"));
        sel3->setGeometry(QRect(430, 30, 161, 31));
        push1 = new QPushButton(centralWidget);
        push1->setObjectName(QString::fromUtf8("push1"));
        push1->setGeometry(QRect(30, 280, 161, 31));
        push2 = new QPushButton(centralWidget);
        push2->setObjectName(QString::fromUtf8("push2"));
        push2->setGeometry(QRect(230, 280, 161, 31));
        push3 = new QPushButton(centralWidget);
        push3->setObjectName(QString::fromUtf8("push3"));
        push3->setGeometry(QRect(430, 280, 161, 31));
        count = new QLabel(centralWidget);
        count->setObjectName(QString::fromUtf8("count"));
        count->setGeometry(QRect(560, 330, 35, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 616, 18));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(help_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tower of Hanoi", nullptr));
        help_action->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\272 \320\270\320\263\321\200\320\260\321\202\321\214?", nullptr));
        sel1->setText(QApplication::translate("MainWindow", "SELECT TOP", nullptr));
        sel2->setText(QApplication::translate("MainWindow", "SELECT TOP", nullptr));
        sel3->setText(QApplication::translate("MainWindow", "SELECT TOP", nullptr));
        push1->setText(QApplication::translate("MainWindow", "PUSH", nullptr));
        push2->setText(QApplication::translate("MainWindow", "PUSH", nullptr));
        push3->setText(QApplication::translate("MainWindow", "PUSH", nullptr));
        count->setText(QApplication::translate("MainWindow", "0", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
