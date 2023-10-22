#include "managermdui_free_approve.h"
#include "ui_managermdui_free_approve.h"
#include <QMessageBox>
#include "Tools/globalkeeper.h"

ManagerMdUI_free_approve::ManagerMdUI_free_approve(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerMdUI_free_approve)
{
    ui->setupUi(this);



    this->model = global_keeper->get_model();
    this->table_view = global_keeper->get_tableview();


    this->cur_index = this->table_view->currentIndex();

    this->ui->lineEdit_name->setText(this->model->record(cur_index.row()).value("name").toString());
    this->ui->lineEdit_reason->setText(this->model->record(cur_index.row()).value("reason").toString());
    this->ui->lineEdit_backtime->setText(this->model->record(cur_index.row()).value("backtime").toString());



}

ManagerMdUI_free_approve::~ManagerMdUI_free_approve()
{
    delete ui;
}

void ManagerMdUI_free_approve::on_pushButton_clicked()
{
    QSqlTableModel* model;

    model = global_keeper->get_model();

    int row = this->table_view->currentIndex().row();
    QString if_approve = this->ui->radioButton_yes->isChecked()?"批准":"不批准";


    model->setData(model->index(row,0),if_approve);
    model->setData(model->index(row,1),"已审批");


    if(!model->submitAll()){
        QMessageBox::question(this,
                              tr("error"),
                              tr("error,please do again!"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    }
}

