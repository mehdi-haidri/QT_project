#include "departman.h"
#include "ui_departman.h"

departman::departman(QSqlDatabase veritabani, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::departman)
{

    this->parent=parent;

    ui->setupUi(this);
    parent->hide();
   sorgu = new QSqlQuery(veritabani);

    listele();
}

departman::~departman()
{

    delete ui;
}

void departman::listele()
{
    sorgu->prepare("select * from departments");
    if(!sorgu->exec()){
        QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Ok");
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

void departman::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_departman_id->setText(model->index(index.row(),0).data().toString());
    ui->lineEdit_departman_ad->setText(model->index(index.row(),1).data().toString());
}


void departman::on_pushButton_kaydet_clicked()
{
    sorgu->prepare("insert into departments(department_name) values(?)");
    sorgu->addBindValue(ui->lineEdit_departman_ad->text());

    if(!sorgu->exec()){
        QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Okay");
    }

    listele();
}


void departman::on_pushButton_guncelle_clicked()
{
    sorgu->prepare("update departments set department_name =? where department_id =?");
    sorgu->addBindValue(ui->lineEdit_departman_ad->text());
    sorgu->addBindValue(ui->lineEdit_departman_id->text().toInt());

    if(!sorgu->exec()){
        QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Okay");
    }

    listele();
}


void departman::on_pushButton_sil_clicked()
{
    sorgu->prepare("select * from stuff where department_id =?");
    sorgu->addBindValue(ui->lineEdit_departman_id->text().toInt());

    if(!sorgu->exec()){
        QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Okay");
    }

    int sayac=0;
    while(sorgu->next()){
        sayac++;
    }
    if(sayac>0){
        QMessageBox::critical(this,"Hata","The department cannot be deleted, there are people registered..","Okay");
        return;
    }
    else{
        sorgu->prepare("delete from departments where department_id=?");
        sorgu->addBindValue(ui->lineEdit_departman_id->text().toInt());
        if(!sorgu->exec()){
            QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Okay");
        }
    }

    listele();
}





void departman::on_departman_rejected()
{
    this->parent->show();

}

