#include "ownermdui_parking_req.h"
#include "ui_ownermdui_parking_req.h"
#include <QMessageBox>
#include "Tools/globalkeeper.h"
extern GlobalKeeper* global_keeper;
OwnerMdUI_parking_req::OwnerMdUI_parking_req(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnerMdUI_parking_req)
{
    ui->setupUi(this);
}

OwnerMdUI_parking_req::~OwnerMdUI_parking_req()
{
    delete ui;
}
void OwnerMdUI_parking_req::slot_add(){



}

void OwnerMdUI_parking_req::on_pushButton_clicked()
{
    QSqlTableModel* model;

    model = global_keeper->get_model();

    int row = model->rowCount();
    QString car_id = this->ui->lineEdit_car_id->text();
    QString name = this->ui->lineEdit_name->text();
    QString station_type = this->ui->radioButton_onground->isChecked()?"����":"����";
    QString station_size = this->ui->radioButton_big->isChecked()?"��":"С";
    QString if_charge = this->ui->radioButton_yes->isChecked()?"���Գ��":"���ɳ��";

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

