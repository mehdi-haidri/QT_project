#include "personel.h"
#include "ui_personel.h"

personel::personel(QSqlDatabase veritabani, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personel)
{
    this->parent= parent;
    ui->setupUi(this);
    parent->hide();
    sorgu = new QSqlQuery(veritabani);
    listele();
}

personel::~personel()
{
    delete ui;
}

void personel::listele()
{
    sorgu->prepare("SELECT * FROM stuff");
    if(!sorgu->exec()){
        QMessageBox::critical(this,"even",sorgu->lastError().text(),"Ok");
        return;
    }

    model = new QSqlQueryModel();
    model->setQuery(*sorgu);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView->viewport()->setStyleSheet("QAbstractScrollArea { align:center; }");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setStyleSheet(
        "QTableView {"
        "    background-color: #f0f0f0;"
        "    alternate-background-color: #e0e0e0;"
        "    gridline-color: #d0d0d0;"
        "    font: 14px 'Arial';"
        "    selection-background-color: #a0a0a0;"
        "    selection-color: #ffffff;"
        "}"
        "QHeaderView::section {"
        "    background-color: #d0d0d0;"
        "    color: #000000;"
        "    padding: 4px;"
        "    font-weight: bold;"
        "    border: 1px solid #c0c0c0;"
        "}"
        "QTableView::item {"
        "    border: 1px solid #d0d0d0;"
        "    padding: 4px;"
        "color: #000000;"
        "}"
        );
}

void personel::on_pushButton_kaydet_clicked()
{
    sorgu->prepare("insert into stuff(stuff_name, stuff_last_name, department_id,password) values(?,?,?,?)");
    sorgu->addBindValue(ui->lineEdit_personel_ad->text());
    sorgu->addBindValue(ui->lineEdit_personel_soyad->text());
    sorgu->addBindValue(ui->lineEdit_departman_no->text().toInt());
    sorgu->addBindValue(ui->password->text());

    if(!sorgu->exec()){
        QMessageBox::critical(this,"even",sorgu->lastError().text(),"Okay");
    }

    listele();
}


void personel::on_pushButton_degistir_clicked()
{
    sorgu->prepare("update stuff set stuff_name=?,stuff_last_name=?,department_id=?,password=? where stuff_id=?");
    sorgu->addBindValue(ui->lineEdit_personel_ad->text());
    sorgu->addBindValue(ui->lineEdit_personel_soyad->text());
    sorgu->addBindValue(ui->lineEdit_departman_no->text().toInt());
    sorgu->addBindValue(ui->password->text());
    sorgu->addBindValue(ui->lineEdit_personel_no->text().toInt());

    if(!sorgu->exec()){
        QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Okay");
    }

    listele();
}


void personel::on_pushButton_sil_clicked()
{
    sorgu->prepare("delete from stuff where stuff_id=?");
    sorgu->addBindValue(ui->lineEdit_personel_no->text().toInt());

    if(!sorgu->exec()){
        QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Okay");
    }

    listele();
}


void personel::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_personel_no->setText(model->index(index.row(),0).data().toString());
    ui->lineEdit_personel_ad->setText(model->index(index.row(),1).data().toString());
    ui->lineEdit_personel_soyad->setText(model->index(index.row(),2).data().toString());
    ui->lineEdit_departman_no->setText(model->index(index.row(),3).data().toString());
}

void personel::on_personel_rejected()
{
    this->parent->show();
}

