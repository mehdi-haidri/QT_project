/********************************************************************************
** Form generated from reading UI file 'departman.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPARTMAN_H
#define UI_DEPARTMAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_departman
{
public:
    QPushButton *pushButton_sil;
    QTableView *tableView;
    QLabel *label;
    QLineEdit *lineEdit_departman_id;
    QLabel *label_2;
    QLineEdit *lineEdit_departman_ad;
    QPushButton *pushButton_guncelle;
    QPushButton *pushButton_kaydet;

    void setupUi(QDialog *departman)
    {
        if (departman->objectName().isEmpty())
            departman->setObjectName("departman");
        departman->resize(890, 509);
        pushButton_sil = new QPushButton(departman);
        pushButton_sil->setObjectName("pushButton_sil");
        pushButton_sil->setGeometry(QRect(170, 250, 75, 24));
        tableView = new QTableView(departman);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(380, 50, 431, 381));
        label = new QLabel(departman);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 80, 141, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        lineEdit_departman_id = new QLineEdit(departman);
        lineEdit_departman_id->setObjectName("lineEdit_departman_id");
        lineEdit_departman_id->setEnabled(false);
        lineEdit_departman_id->setGeometry(QRect(190, 80, 113, 22));
        label_2 = new QLabel(departman);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 120, 111, 16));
        label_2->setFont(font);
        lineEdit_departman_ad = new QLineEdit(departman);
        lineEdit_departman_ad->setObjectName("lineEdit_departman_ad");
        lineEdit_departman_ad->setGeometry(QRect(190, 120, 113, 22));
        pushButton_guncelle = new QPushButton(departman);
        pushButton_guncelle->setObjectName("pushButton_guncelle");
        pushButton_guncelle->setGeometry(QRect(230, 210, 75, 24));
        pushButton_kaydet = new QPushButton(departman);
        pushButton_kaydet->setObjectName("pushButton_kaydet");
        pushButton_kaydet->setGeometry(QRect(100, 210, 75, 24));

        retranslateUi(departman);

        QMetaObject::connectSlotsByName(departman);
    } // setupUi

    void retranslateUi(QDialog *departman)
    {
        departman->setWindowTitle(QCoreApplication::translate("departman", "Dialog", nullptr));
        pushButton_sil->setText(QCoreApplication::translate("departman", "Sil", nullptr));
        label->setText(QCoreApplication::translate("departman", "Department ID:", nullptr));
        label_2->setText(QCoreApplication::translate("departman", "Department Ad:", nullptr));
        pushButton_guncelle->setText(QCoreApplication::translate("departman", "Update", nullptr));
        pushButton_kaydet->setText(QCoreApplication::translate("departman", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class departman: public Ui_departman {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPARTMAN_H
