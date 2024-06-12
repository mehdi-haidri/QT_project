/********************************************************************************
** Form generated from reading UI file 'personel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONEL_H
#define UI_PERSONEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_personel
{
public:
    QTableView *tableView;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_personel_no;
    QLineEdit *lineEdit_personel_ad;
    QLineEdit *lineEdit_personel_soyad;
    QPushButton *pushButton_kaydet;
    QPushButton *pushButton_degistir;
    QPushButton *pushButton_sil;
    QLineEdit *lineEdit_departman_no;
    QLabel *label_7;

    void setupUi(QDialog *personel)
    {
        if (personel->objectName().isEmpty())
            personel->setObjectName("personel");
        personel->resize(915, 443);
        tableView = new QTableView(personel);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(310, 40, 551, 341));
        groupBox = new QGroupBox(personel);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 30, 271, 281));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 60, 101, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 111, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 30, 121, 16));
        lineEdit_personel_no = new QLineEdit(groupBox);
        lineEdit_personel_no->setObjectName("lineEdit_personel_no");
        lineEdit_personel_no->setEnabled(false);
        lineEdit_personel_no->setGeometry(QRect(130, 30, 113, 22));
        lineEdit_personel_ad = new QLineEdit(groupBox);
        lineEdit_personel_ad->setObjectName("lineEdit_personel_ad");
        lineEdit_personel_ad->setGeometry(QRect(130, 60, 113, 22));
        lineEdit_personel_soyad = new QLineEdit(groupBox);
        lineEdit_personel_soyad->setObjectName("lineEdit_personel_soyad");
        lineEdit_personel_soyad->setGeometry(QRect(130, 90, 113, 22));
        pushButton_kaydet = new QPushButton(groupBox);
        pushButton_kaydet->setObjectName("pushButton_kaydet");
        pushButton_kaydet->setGeometry(QRect(30, 180, 75, 24));
        pushButton_degistir = new QPushButton(groupBox);
        pushButton_degistir->setObjectName("pushButton_degistir");
        pushButton_degistir->setGeometry(QRect(170, 180, 75, 24));
        pushButton_sil = new QPushButton(groupBox);
        pushButton_sil->setObjectName("pushButton_sil");
        pushButton_sil->setGeometry(QRect(100, 230, 75, 24));
        lineEdit_departman_no = new QLineEdit(groupBox);
        lineEdit_departman_no->setObjectName("lineEdit_departman_no");
        lineEdit_departman_no->setGeometry(QRect(130, 120, 113, 22));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 120, 121, 16));

        retranslateUi(personel);

        QMetaObject::connectSlotsByName(personel);
    } // setupUi

    void retranslateUi(QDialog *personel)
    {
        personel->setWindowTitle(QCoreApplication::translate("personel", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("personel", "Personal", nullptr));
        label->setText(QCoreApplication::translate("personel", "Personal Ad:", nullptr));
        label_2->setText(QCoreApplication::translate("personel", "Personal Soyad:", nullptr));
        label_3->setText(QCoreApplication::translate("personel", "Personal No:", nullptr));
        pushButton_kaydet->setText(QCoreApplication::translate("personel", "Save", nullptr));
        pushButton_degistir->setText(QCoreApplication::translate("personel", "Change", nullptr));
        pushButton_sil->setText(QCoreApplication::translate("personel", "Sil", nullptr));
        label_7->setText(QCoreApplication::translate("personel", "Department No:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class personel: public Ui_personel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONEL_H
