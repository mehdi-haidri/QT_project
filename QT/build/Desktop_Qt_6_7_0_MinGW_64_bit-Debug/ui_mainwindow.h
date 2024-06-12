/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView_department;
    QTableView *tableView_personal;
    QLabel *label_departmanlar;
    QLabel *label_personeller;
    QPushButton *pushButton_personel_ekrani;
    QPushButton *pushButton_department_ekrani;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(618, 594);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView_department = new QTableView(centralwidget);
        tableView_department->setObjectName("tableView_department");
        tableView_department->setGeometry(QRect(80, 50, 451, 192));
        tableView_personal = new QTableView(centralwidget);
        tableView_personal->setObjectName("tableView_personal");
        tableView_personal->setGeometry(QRect(80, 290, 451, 192));
        label_departmanlar = new QLabel(centralwidget);
        label_departmanlar->setObjectName("label_departmanlar");
        label_departmanlar->setGeometry(QRect(90, 30, 101, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_departmanlar->setFont(font);
        label_personeller = new QLabel(centralwidget);
        label_personeller->setObjectName("label_personeller");
        label_personeller->setGeometry(QRect(90, 270, 101, 16));
        label_personeller->setFont(font);
        pushButton_personel_ekrani = new QPushButton(centralwidget);
        pushButton_personel_ekrani->setObjectName("pushButton_personel_ekrani");
        pushButton_personel_ekrani->setGeometry(QRect(490, 510, 111, 24));
        pushButton_department_ekrani = new QPushButton(centralwidget);
        pushButton_department_ekrani->setObjectName("pushButton_department_ekrani");
        pushButton_department_ekrani->setGeometry(QRect(360, 510, 111, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 618, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_departmanlar->setText(QCoreApplication::translate("MainWindow", "Departmanlar", nullptr));
        label_personeller->setText(QCoreApplication::translate("MainWindow", "Personeller", nullptr));
        pushButton_personel_ekrani->setText(QCoreApplication::translate("MainWindow", "Personel Ekran\304\261", nullptr));
        pushButton_department_ekrani->setText(QCoreApplication::translate("MainWindow", "Departman Ekran\304\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
