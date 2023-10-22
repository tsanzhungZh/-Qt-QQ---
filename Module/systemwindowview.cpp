#include "systemwindowview.h"
#include "ui_systemwindowview.h"
#include "Tools/all_include.h"
SystemWindowView::SystemWindowView(int mode,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemWindowView)
{
    ui->setupUi(this);
    this->cur_mode_id = mode;
    if(this->cur_mode_id > e_manager || this->cur_mode_id < e_owner){
        QMessageBox::question(this,
                              tr("error"),
                              tr("load error! enter mode is out of range(0~2)").arg(mode),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
        delete this;
        return;

    }
    this->load_window_bar();
    this->load_xmode_part(mode);


}

SystemWindowView::~SystemWindowView()
{
    delete ui;
}
void SystemWindowView::load_window_bar(void){

    this->toolbar = this->ui->toolBar;
    this->menubar = this->ui->menubar;

}
void SystemWindowView::load_xmode_part(int mode){
    switch (mode) {
    case e_owner:
        this->mode_owner_init();
        break;
    case e_worker:
        this->mode_worker_init();
        break;
    case e_manager:
        this->mode_manager_init();
        break;
    default:
        QMessageBox::question(this,
                              tr("error"),
                              tr("load error! enter mode is out of range(0~2)").arg(mode),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
        break;
    }
    return;

}
void SystemWindowView::mode_owner_init(){
    this->owner_mod = new OwnerModule(this);

    //车位管理
    this->ui->menubar->addMenu(this->owner_mod->menu_my_parking);
    this->ui->toolBar->addAction(this->owner_mod->act_parking_request);
    this->ui->toolBar->addAction(this->owner_mod->act_parking_show);
    this->ui->toolBar->addSeparator();
    //业主缴费
    this->ui->menubar->addMenu(this->owner_mod->menu_payment_manage);
    this->ui->toolBar->addAction(this->owner_mod->act_payment_select);
    this->ui->toolBar->addAction(this->owner_mod->act_payment_self_service);
    this->ui->toolBar->addSeparator();
    //故障报修
    this->ui->menubar->addMenu(this->owner_mod->menu_issue_report);
    this->ui->toolBar->addAction(this->owner_mod->act_issue_report);
    this->ui->toolBar->addAction(this->owner_mod->act_issue_process);
    this->ui->toolBar->addAction(this->owner_mod->act_issue_evaluate);
}
void SystemWindowView::mode_worker_init(){
    this->worker_mod = new WorkerModule(this);

    //业主管理
    this->ui->menubar->addMenu(this->worker_mod->menu_owner_info);
    this->ui->toolBar->addAction(this->worker_mod->act_owner_find);
    this->ui->toolBar->addAction(this->worker_mod->act_owner_alter);
    this->ui->toolBar->addAction(this->worker_mod->act_owner_registered);
    this->ui->toolBar->addAction(this->worker_mod->act_owner_delete);
    this->ui->toolBar->addSeparator();
    //车位管理
    this->ui->menubar->addMenu(this->worker_mod->menu_parking_manage);
    this->ui->toolBar->addAction(this->worker_mod->act_show_parking_info);
    this->ui->toolBar->addAction(this->worker_mod->act_add_parking_info);
    this->ui->toolBar->addAction(this->worker_mod->act_modify_parking_info);
    this->ui->toolBar->addAction(this->worker_mod->act_del_parking_info);
    this->ui->toolBar->addAction(this->worker_mod->act_parking_rent);
    this->ui->toolBar->addSeparator();
    //缴费管理
    this->ui->menubar->addMenu(this->worker_mod->menu_payment_manage);
    this->ui->toolBar->addAction(this->worker_mod->act_price_manage);
    this->ui->toolBar->addAction(this->worker_mod->act_payment_select);
    this->ui->toolBar->addAction(this->worker_mod->act_get_payment);
    this->ui->toolBar->addSeparator();

    //故障维护
    this->ui->menubar->addMenu(this->worker_mod->menu_issue_manage);
    this->ui->toolBar->addAction(this->worker_mod->act_issue_select);
    this->ui->toolBar->addAction(this->worker_mod->act_issue_repair);
}
void SystemWindowView::mode_manager_init(){
    this->manager_mod = new ManagerModule(this);

    //用户管理
    this->ui->menubar->addMenu(this->manager_mod->menu_manager);
    this->ui->toolBar->addAction(this->manager_mod->act_add_user);
    this->ui->toolBar->addAction(this->manager_mod->act_show_user);
    this->ui->toolBar->addAction(this->manager_mod->act_alter_user);
    this->ui->toolBar->addAction(this->manager_mod->act_del_user);
    this->ui->toolBar->addSeparator();
    //请假审批制度
    this->ui->menubar->addMenu(this->manager_mod->menu_attendance);
    this->ui->toolBar->addAction(this->manager_mod->act_free_confirm);
    this->ui->toolBar->addAction(this->manager_mod->act_free_approve);
    this->ui->toolBar->addAction(this->manager_mod->act_find_attend);






}
