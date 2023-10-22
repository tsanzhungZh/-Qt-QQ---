#include "managermdui_free_confirm.h"
#include "ui_managermdui_free_confirm.h"
#include <QMessageBox>
#include "Tools/globalkeeper.h"
ManagerMdUI_free_confirm::ManagerMdUI_free_confirm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerMdUI_free_confirm)
{
    ui->setupUi(this);
}

ManagerMdUI_free_confirm::~ManagerMdUI_free_confirm()
{
    delete ui;
}

void ManagerMdUI_free_confirm::on_pushButton_Done_clicked()
{
    QSqlTableModel* model;

    model = global_keeper->get_model();

    int row = model->rowCount();
    qint64 username = this->ui->lineEdit_username->text().toLongLong();
    QString name = this->ui->lineEdit_name->text();
    QString reason = this->ui->lineEdit_reason->text();
    QString backtime = this->ui->lineEdit_backtime->text();

    model->insertRow(row);

    model->setData(model->index(row,0),username);
    model->setData(model->index(row,1),name);
    model->setData(model->index(row,2),reason);
    model->setData(model->index(row,3),backtime);

    if(!model->submitAll()){
        QMessageBox::question(this,
                              tr("error"),
                              tr("error,please do again!"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    }
}

