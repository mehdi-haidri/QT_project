#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personel.h"
#include "departman.h"
#include "departement_project.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    veritabani.setDatabaseName("C:/Users/mehdi/desktop/QT_project/QT/personel.db");
    if(!veritabani.open()){
        ui->statusbar->showMessage("Could not connect to database.");
    }
    else{
        ui->statusbar->showMessage("Connection to database");
    }

    model_1 = new QSqlTableModel(this); // Set parent to ensure proper cleanup
    model_1->setTable("departments");
    model_1->select();

    ui->tableView_department->setModel(model_1);
    ui->tableView_department->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView_department->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
     ui->tableView_department->viewport()->setStyleSheet("QAbstractScrollArea { align:center; }");
    ui->tableView_department->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_department->setStyleSheet(
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

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tableView_department_clicked(const QModelIndex &index)
{
    // Tiklanan satirdaki veri alinir.
    QString departman = model_1->index(index.row(), 0).data().toString();
    int departmanNumarasi = departman.toInt();
    QSqlQuery sorgu;
    sorgu.prepare("SELECT * FROM stuff WHERE department_id=?");
    sorgu.addBindValue(departmanNumarasi);
    sorgu.exec();

    model_2 = new QSqlQueryModel();
    model_2->setQuery(sorgu);
    ui->tableView_personal->setModel(model_2);

    ui->tableView_personal->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView_personal->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tableView_personal->viewport()->setStyleSheet("QAbstractScrollArea { align:center; }");
    ui->tableView_personal->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_personal->setStyleSheet(
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


void MainWindow::on_pushButton_department_ekrani_clicked()
{
    departman *dep = new departman(veritabani,this);


    dep->show();


}


void MainWindow::on_pushButton_personel_ekrani_clicked()
{
    personel *per = new personel(veritabani,this);
    per->show();

}





void MainWindow::on_departement_project_clicked()
{
    departement_project *pro = new departement_project(veritabani);
    pro->show();
}

