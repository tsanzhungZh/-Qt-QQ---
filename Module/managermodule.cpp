
#include "managermodule.h"
#include "Tools/info.h"
#include <QAction>
extern Info info;

ManagerModule::ManagerModule(QObject *parent)
    : BaseModule{parent}
{
    this->module_init();
}
void ManagerModule::module_init(){
    this->act_init();
    this->menu_init();

}
void ManagerModule::menu_init(){
    this->menu_manager = new QMenu("worker manage");

    this->menu_manager->addAction(this->act_add_worker);
    this->menu_manager->addAction(this->act_show_worker);
    this->menu_manager->addAction(this->act_alter_worker);
    this->menu_manager->addAction(this->act_del_worker);
}
void ManagerModule::act_init(){

    this->act_add_worker = new QAction(QIcon(info.picture_path + "add.png"),"add worker");
    this->act_add_worker->setStatusTip(tr("add worker"));
    connect(act_add_worker,&QAction::triggered,this,&ManagerModule::slot_add_worker);

    this->act_show_worker = new QAction(QIcon(info.picture_path + "show.png"),"show worker");
    this->act_show_worker->setStatusTip(tr("show worker"));
    connect(act_show_worker,&QAction::triggered,this,&ManagerModule::slot_show_worker);

    this->act_alter_worker = new QAction(QIcon(info.picture_path + "attend.png"),"alter worker");
    this->act_alter_worker->setStatusTip(tr("alter worker"));
    connect(act_alter_worker,&QAction::triggered,this,&ManagerModule::slot_alter_worker);

    this->act_del_worker = new QAction(QIcon(info.picture_path + "free.png"),"del worker");
    this->act_del_worker->setStatusTip(tr("del worker"));
    connect(act_del_worker,&QAction::triggered,this,&ManagerModule::slot_del_worker);


}
void ManagerModule::slot_add_worker(){

}
void ManagerModule::slot_show_worker(){

}
void ManagerModule::slot_alter_worker(){

}
void ManagerModule::slot_del_worker(){

}









