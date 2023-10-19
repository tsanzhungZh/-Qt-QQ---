
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

    //业主管理
    this->menu_owner_info = new QMenu("owner manage");
    this->menu_owner_info->addAction(this->act_owner_find);
    this->menu_owner_info->addAction(this->act_owner_alter);
    this->menu_owner_info->addAction(this->act_owner_registered);
    this->menu_owner_info->addAction(this->act_owner_delete);

    //车位管理
    this->menu_parking_manage = new QMenu("owner manage");
    this->menu_parking_manage->addAction(this->act_show_parking_info);
    this->menu_parking_manage->addAction(this->act_add_parking_info);
    this->menu_parking_manage->addAction(this->act_modify_parking_info);
    this->menu_parking_manage->addAction(this->act_del_parking_info);
    this->menu_parking_manage->addAction(this->act_parking_rent);





}
void WorkerModule::act_init(){
    //业主管理
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



    //车位管理
    this->act_show_parking_info = new QAction(QIcon(info.picture_path + "carstation1.png"),"show parking");
    this->act_show_parking_info->setStatusTip(tr("show parking"));
    connect(act_show_parking_info,&QAction::triggered,this,&WorkerModule::slot_show_parking_info);

    this->act_add_parking_info = new QAction(QIcon(info.picture_path + "carstation.png"),"add parking");
    this->act_add_parking_info->setStatusTip(tr("add parking"));
    connect(act_add_parking_info,&QAction::triggered,this,&WorkerModule::slot_add_parking_info);

    this->act_del_parking_info = new QAction(QIcon(info.picture_path + "del_parking.jpg"),"del parking");
    this->act_del_parking_info->setStatusTip(tr("del parking"));
    connect(act_del_parking_info,&QAction::triggered,this,&WorkerModule::slot_del_parking_info);

    this->act_modify_parking_info = new QAction(QIcon(info.picture_path + "modify.jpg"),"modify parking");
    this->act_modify_parking_info->setStatusTip(tr("modify parking"));
    connect(act_modify_parking_info,&QAction::triggered,this,&WorkerModule::slot_modify_parking_info);

    this->act_parking_rent = new QAction(QIcon(info.picture_path + "paymanage.png"),"parking rent");
    this->act_parking_rent->setStatusTip(tr("parking rent"));
    connect(act_parking_rent,&QAction::triggered,this,&WorkerModule::slot_parking_rent);


}
void WorkerModule::slot_owner_find(){

}
void WorkerModule::slot_owner_alter(){

}
void WorkerModule::slot_owner_registered(){

}
void WorkerModule::slot_owner_delete(){

}
void WorkerModule::slot_show_parking_info(){

}
void WorkerModule::slot_add_parking_info(){

}
void WorkerModule::slot_modify_parking_info(){

}
void WorkerModule::slot_del_parking_info(){

}
void WorkerModule::slot_parking_rent(){

}
