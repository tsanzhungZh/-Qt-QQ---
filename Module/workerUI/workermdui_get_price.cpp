#include "workermdui_get_price.h"
#include "ui_workermdui_get_price.h"
#include <QMessageBox>
#include "Tools/globalkeeper.h"
extern GlobalKeeper* global_keeper;

WorkerMdUI_get_price::WorkerMdUI_get_price(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkerMdUI_get_price)
{
    ui->setupUi(this);

    this->model = global_keeper->get_model();
    this->table_view = global_keeper->get_tableview();




    this->ui->lineEdit_username->setText(this->model->record(0).value("username").toString());
    this->ui->lineEdit_house->setText(this->model->record(0).value("house_price").toString());
    this->ui->lineEdit_parking->setText(this->model->record(0).value("parking_price").toString());
    this->ui->lineEdit_repair->setText(this->model->record(0).value("repair_price").toString());
}

WorkerMdUI_get_price::~WorkerMdUI_get_price()
{
    delete ui;
}

void WorkerMdUI_get_price::on_pushButton_clicked()
{
    model->removeRow(0);
    model->submitAll();

    QMessageBox::question(this,
                          tr("OK"),
                          tr("Get price OK!"),
                          QMessageBox::Ok | QMessageBox::Cancel,
                          QMessageBox::Ok);





}

