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

}
void SystemWindowView::mode_worker_init(){
    this->worker_mod = new WorkerModule(this);

    this->ui->menubar->addMenu(this->worker_mod->menu_owner_info);

    this->ui->toolBar->addAction(this->worker_mod->act_owner_find);
    this->ui->toolBar->addAction(this->worker_mod->act_owner_alter);
    this->ui->toolBar->addAction(this->worker_mod->act_owner_registered);
    this->ui->toolBar->addAction(this->worker_mod->act_owner_delete);




}
void SystemWindowView::mode_manager_init(){
    this->manager_mod = new ManagerModule(this);

    this->ui->menubar->addMenu(this->manager_mod->menu_manager);

    this->ui->toolBar->addAction(this->manager_mod->act_add_user);
    this->ui->toolBar->addAction(this->manager_mod->act_show_user);
    this->ui->toolBar->addAction(this->manager_mod->act_alter_user);
    this->ui->toolBar->addAction(this->manager_mod->act_del_user);


}
