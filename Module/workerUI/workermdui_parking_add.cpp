#include "workermdui_parking_add.h"
#include "ui_workermdui_parking_add.h"
#include <QMessageBox>
#include "Tools/globalkeeper.h"
extern GlobalKeeper* global_keeper;
WorkerMdUI_parking_add::WorkerMdUI_parking_add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkerMdUI_parking_add)
{
    ui->setupUi(this);
}

WorkerMdUI_parking_add::~WorkerMdUI_parking_add()
{
    delete ui;
}

void WorkerMdUI_parking_add::on_pushButton_clicked()
{
    QSqlTableModel* model;

    model = global_keeper->get_model();

    int row = model->rowCount();
    QString car_id = this->ui->lineEdit_car_id->text();
    QString name = this->ui->lineEdit_name->text();
    QString station_type = this->ui->radioButton_onground->isChecked()?"地上":"地下";
    QString station_size = this->ui->radioButton_big->isChecked()?"大":"小";
    QString if_charge = this->ui->radioButton_yes->isChecked()?"可以充电":"不可充电";

                                                                 qint64 carstation_id = this->ui->lineEdit->text().toLongLong();

    model->insertRow(row);

    model->setData(model->index(row,0),carstation_id);
    model->setData(model->index(row,1),1);
    model->setData(model->index(row,2),123);
    model->setData(model->index(row,3),car_id);
    model->setData(model->index(row,4),station_type);
    model->setData(model->index(row,5),station_size);
    model->setData(model->index(row,6),if_charge);
    model->setData(model->index(row,7),name);

    if(!model->submitAll()){
        QMessageBox::question(this,
                              tr("error"),
                              tr("error,please do again!"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    }
}

