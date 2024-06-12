#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QMessageBox>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{

    ui->setupUi(this);


    veritabani.setDatabaseName("C:/Users/mehdi/desktop/QT_project/QT/personel.db");
    if(!veritabani.open()){
        QMessageBox::about(this,"Could not connect to database.","ddd");
    }
    else{


    }





}

login::~login()
{
    delete ui;
    veritabani.close();
}

void login::on_pushButton_clicked()
{

    QSqlQuery sorgu ;
    sorgu.prepare("SELECT * FROM chef where name=? and password=?");
    sorgu.addBindValue(ui->lineEdit_name->text());
    sorgu.addBindValue(ui->lineEdit_password->text());
    int count = 0 ;
    sorgu.exec();
        while(sorgu.next()){
        count++;
    }

    if(count>0){
        veritabani.close();
        MainWindow *w = new MainWindow() ;
        hide();
        w->show();

    }
    else{
        QMessageBox::about(this,ui->lineEdit_name->text(),sorgu.lastError().text());
    }

}

