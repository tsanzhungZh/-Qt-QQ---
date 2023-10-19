
#include "managermodule.h"
#include "Tools/info.h"
#include "Tools/globalkeeper.h"
#include <QAction>
#include "ownermodule.h"

extern Info info;
extern GlobalKeeper *global_keeper;

OwnerModule::OwnerModule(QObject *parent)
    : BaseModule{parent}
{

    this->module_init();

}
void OwnerModule::module_init(){
    this->act_init();
    this->menu_init();

}
void OwnerModule::menu_init(){
    //业主车位
    this->menu_my_parking = new QMenu("my parking");
    this->menu_my_parking->addAction(this->act_parking_request);
    this->menu_my_parking->addAction(this->act_parking_show);



}
void OwnerModule::act_init(){


    //业主车位
    this->act_parking_request = new QAction(QIcon(info.picture_path + "addcarstation.png"),"parking request");
    this->act_parking_request->setStatusTip(tr("parking request"));
    connect(act_parking_request,&QAction::triggered,this,&OwnerModule::slot_parking_request);

    this->act_parking_show = new QAction(QIcon(info.picture_path + "find.jpg"),"parking show");
    this->act_parking_show->setStatusTip(tr("parking show"));
    connect(act_parking_show,&QAction::triggered,this,&OwnerModule::slot_parking_show);


}
void OwnerModule::slot_parking_request(){



}
void OwnerModule::slot_parking_show(){



}
