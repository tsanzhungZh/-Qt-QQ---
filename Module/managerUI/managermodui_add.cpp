#include "managermodui_add.h"
#include "ui_managermodui_add.h"
#include <QMessageBox>
#include "Tools/globalkeeper.h"

extern GlobalKeeper* global_keeper;
ManagerModUI_add::ManagerModUI_add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerModUI_add)
{
    ui->setupUi(this);
    this->show();
}

ManagerModUI_add::~ManagerModUI_add()
{
    delete ui;
}
bool ManagerModUI_add::checked_is_empty(void){

    bool flag = ((this->ui->radioButton_checkedmanager->isChecked() ||
                this->ui->radioButton_uncheckedmanager->isChecked() ) &&
                !this->ui->lineEdit_username->text().isEmpty() &&
                !this->ui->lineEdit_password->text().isEmpty() &&
                !this->ui->lineEdit_telephone->text().isEmpty());


    return flag;


}

void ManagerModUI_add::on_pushButton_add_clicked()
{
    QSqlTableModel* model;
    if(!checked_is_empty()){
        QMessageBox::question(this,
                              tr("error"),
                              tr("empty, please input info before add"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    }else{

        model = global_keeper->get_model();

        int row = model->rowCount();
        qint64 username = this->ui->lineEdit_username->text().toLongLong();
        QString password = this->ui->lineEdit_password->text();
        QString telephone = this->ui->lineEdit_telephone->text();

        if(0 == username){
            QMessageBox::question(this,
                                  tr("error"),
                                  tr("error,please input username by number but not include letter!"),
                                  QMessageBox::Ok | QMessageBox::Cancel,
                                  QMessageBox::Ok);
            return;

        }

        model->insertRow(row);

        model->setData(model->index(row,0),username);
        model->setData(model->index(row,1),password);
        if(!model->submitAll()){
            QMessageBox::question(this,
                                  tr("error"),
                                  tr("error,please do again!"),
                                  QMessageBox::Ok | QMessageBox::Cancel,
                                  QMessageBox::Ok);
        }
    }
}
void ManagerModUI_add::on_pushButton_cancel_clicked()
{
    delete this;
}

