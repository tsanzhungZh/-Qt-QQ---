#include "managermodui_alter.h"
#include "ui_managermodui_alter.h"
#include "Tools/globalkeeper.h"
#include "Tools/info.h"
extern GlobalKeeper* global_keeper;

ManagerModUI_alter::ManagerModUI_alter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagerModUI_alter)
{
    ui->setupUi(this);
    this->show();

    init_ui_info();


}

ManagerModUI_alter::~ManagerModUI_alter()
{
    delete ui;
}
void ManagerModUI_alter::init_ui_info(){
    this->model = global_keeper->get_model();
    this->table_view = global_keeper->get_tableview();


    this->cur_index = this->table_view->currentIndex();




    this->ui->lineEdit_username->setText(this->model->record(cur_index.row()).value("username").toString());
    this->ui->lineEdit_password->setText(this->model->record(cur_index.row()).value("password").toString());
    this->ui->lineEdit_telephone->setText(this->model->record(cur_index.row()).value("telephone").toString());

    if(e_Yes==this->model->record(cur_index.row()).value("ismanager").toInt()){
        this->ui->radioButton_checkedmanager->setChecked(e_Yes);
        this->ui->radioButton_uncheckedmanager->setChecked(e_No);
    }else{
        this->ui->radioButton_checkedmanager->setChecked(e_No);
        this->ui->radioButton_uncheckedmanager->setChecked(e_Yes);
    }



}

void ManagerModUI_alter::on_pushButton_cancel_clicked()
{
    delete this;
}


void ManagerModUI_alter::on_pushButton_alter_clicked()
{

    qint64 username = ui->lineEdit_username->text().toLongLong();
    if(0 == username){
        QMessageBox::question(this,
                              tr("error"),
                              tr("error,please input username by number but not include letter!"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
        return;

    }
    if(!checked_is_empty()){
        QMessageBox::question(this,
                              tr("error"),
                              tr("empty, please input info before add"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    }else{

        int row = this->cur_index.row();

        qint64 username = this->ui->lineEdit_username->text().toLongLong();
        QString password = this->ui->lineEdit_password->text();
        QString telephone = this->ui->lineEdit_telephone->text();
        int ismanager;
        if(this->ui->radioButton_checkedmanager->isChecked()||this->ui->radioButton_checkedmanager->isChecked()){
            ismanager = this->ui->radioButton_checkedmanager->isChecked()?1:0;
        }
        if(0 == username){
            QMessageBox::question(this,
                                  tr("error"),
                                  tr("error,please input username by number but not include letter!"),
                                  QMessageBox::Ok | QMessageBox::Cancel,
                                  QMessageBox::Ok);
            return;

        }



        model->setData(model->index(row,0),username);
        model->setData(model->index(row,1),password);
        model->setData(model->index(row,2),telephone);
        model->setData(model->index(row,3),ismanager);

        if(!model->submitAll()){
            QMessageBox::question(this,
                                  tr("error"),
                                  tr("error,please do again!"),
                                  QMessageBox::Ok | QMessageBox::Cancel,
                                  QMessageBox::Ok);
        }




    }










}

bool ManagerModUI_alter::checked_is_empty(void){

    bool flag = ((this->ui->radioButton_checkedmanager->isChecked() ||
                  this->ui->radioButton_uncheckedmanager->isChecked() ) &&
                 !this->ui->lineEdit_username->text().isEmpty() &&
                 !this->ui->lineEdit_password->text().isEmpty() &&
                 !this->ui->lineEdit_telephone->text().isEmpty());

    return flag;

}
