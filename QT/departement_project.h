#ifndef DEPARTEMENT_PROJECT_H
#define DEPARTEMENT_PROJECT_H

#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlError>


namespace Ui {
class departement_project;
}

class departement_project : public QDialog
{
    Q_OBJECT

public:
    explicit departement_project(QSqlDatabase veritabani, QWidget *parent = nullptr);
    ~departement_project();

    void listele();
   ;

private slots:
    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::departement_project *ui;


    QSqlQuery *sorgu;

    QSqlQueryModel *model;
};



#endif // DEPARTEMENT_PROJECT_H
