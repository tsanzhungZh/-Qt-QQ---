#include "workermdui_add_owner.h"
#include "ui_workermdui_add_owner.h"
#include <QMessageBox>
#include "Tools/globalkeeper.h"

WorkerMdUI_add_owner::WorkerMdUI_add_owner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkerMdUI_add_owner)
{
    ui->setupUi(this);
}

WorkerMdUI_add_owner::~WorkerMdUI_add_owner()
{
    delete ui;
}

void WorkerMdUI_add_owner::on_pushButton_clicked()
{
    QSqlTableModel* model;

    model = global_keeper->get_model();

    int row = model->rowCount();

    qint64 username = this->ui->lineEdit_username->text().toLongLong();
    QString name = this->ui->lineEdit_name->text();
    QString telephone = this->ui->lineEdit_telephone->text();
    QString password = this->ui->lineEdit_password->text();
    QString address = this->ui->lineEdit_address->text();




    qint64 carstation_id = this->ui->lineEdit_username->text().toLongLong();

    model->insertRow(row);

    model->setData(model->index(row,0),username);
    model->setData(model->index(row,1),name);
    model->setData(model->index(row,2),telephone);
    model->setData(model->index(row,3),address);

    if(!model->submitAll()){
        QMessageBox::question(this,
                              tr("error"),
                              tr("error,please do again!"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    }
}

