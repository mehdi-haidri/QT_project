#include "departement_project.h"
#include "ui_departement_project.h"

departement_project::departement_project(QSqlDatabase veritabani, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::departement_project)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(veritabani);

    listele();
}

void departement_project::listele()
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

void departement_project::on_tableView_clicked(const QModelIndex &index)
{
    ui->ID->setText(model->index(index.row(),0).data().toString());
    ui->AD->setText(model->index(index.row(),1).data().toString());
    if(model->index(index.row(),2).data().toString()==""){
         ui->current_project->setText("no project");
    }
    else
    ui->current_project->setText(model->index(index.row(),2).data().toString());
}


departement_project::~departement_project()
{
    delete ui;
}

void departement_project::on_pushButton_clicked()
{
    if(ui->new_project->text()!=""){
        sorgu->prepare("update departments set project = ? where department_id = ?");
        sorgu->addBindValue(ui->new_project->text());
        sorgu->addBindValue(ui->ID->text());
        if(!sorgu->exec()){
            QMessageBox::critical(this,"Hata",sorgu->lastError().text(),"Ok");
            return;
        }

        ui->current_project->setText(ui->new_project->text());
        ui->new_project->setText("");

        listele();


    }
}

