#include "workermdui_price_manage.h"
#include "ui_workermdui_price_manage.h"
#include <QSqlTableModel>
#include <QMessageBox>
#include "Tools/globalkeeper.h"
extern GlobalKeeper* global_keeper;
WorkerMdUI_price_manage::WorkerMdUI_price_manage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkerMdUI_price_manage)
{
    ui->setupUi(this);
    this->cur_index = global_keeper->get_tableview()->currentIndex();
}

WorkerMdUI_price_manage::~WorkerMdUI_price_manage()
{
    delete ui;
}

void WorkerMdUI_price_manage::on_pushButton_clicked()
{
    int row = this->cur_index.row();

    QSqlTableModel* model = global_keeper->get_model();


    int house = this->ui->lineEdit_house_price->text().toInt();
    int parking = this->ui->lineEdit_house_price->text().toInt();
    int repair = this->ui->lineEdit_house_price->text().toInt();

    model->setData(model->index(0,1),house);
    model->setData(model->index(0,2),parking);
    model->setData(model->index(0,3),repair);

    if(!model->submitAll()){
        QMessageBox::question(this,
                              tr("error"),
                              tr("error,please do again!"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    }
}

