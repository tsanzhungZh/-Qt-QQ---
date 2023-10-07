
#include "Tools/info.h"
#include "Tools/globalkeeper.h"
#include <QAction>
#include "workermodule.h"
extern Info info;
extern GlobalKeeper *global_keeper;
WorkerModule::WorkerModule(QObject *parent)
    : BaseModule{parent}
{
    this->module_init();
}
void WorkerModule::module_init(){
    this->act_init();
    this->menu_init();

}



void WorkerModule::menu_init(){
    this->menu_owner_info = new QMenu("owner manage");

    this->menu_owner_info->addAction(this->act_owner_find);
    this->menu_owner_info->addAction(this->act_owner_alter);
    this->menu_owner_info->addAction(this->act_owner_registered);
    this->menu_owner_info->addAction(this->act_owner_delete);
}
void WorkerModule::act_init(){

    this->act_owner_find = new QAction(QIcon(info.picture_path + "find.jpg"),"owner find");
    this->act_owner_find->setStatusTip(tr("add user"));
    connect(act_owner_find,&QAction::triggered,this,&WorkerModule::slot_owner_find);

    this->act_owner_alter = new QAction(QIcon(info.picture_path + "modify.jpg"),"owner modify");
    this->act_owner_alter->setStatusTip(tr("show user"));
    connect(act_owner_alter,&QAction::triggered,this,&WorkerModule::slot_owner_alter);

    this->act_owner_registered = new QAction(QIcon(info.picture_path + "confirm.jpg"),"owner registered");
    this->act_owner_registered->setStatusTip(tr("alter user"));
    connect(act_owner_registered,&QAction::triggered,this,&WorkerModule::slot_owner_registered);

    this->act_owner_delete = new QAction(QIcon(info.picture_path + "del.png"),"owner delete");
    this->act_owner_delete->setStatusTip(tr("del user"));
    connect(act_owner_delete,&QAction::triggered,this,&WorkerModule::slot_owner_delete);


}
void WorkerModule::slot_owner_find(){

}
void WorkerModule::slot_owner_alter(){

}
void WorkerModule::slot_owner_registered(){

}
void WorkerModule::slot_owner_delete(){

}
