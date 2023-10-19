
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

    //业主缴费
    this->menu_payment_manage = new QMenu("payment manage");
    this->menu_payment_manage->addAction(this->act_payment_select);
    this->menu_payment_manage->addAction(this->act_payment_self_service);



}
void OwnerModule::act_init(){


    //业主车位
    this->act_parking_request = new QAction(QIcon(info.picture_path + "addcarstation.png"),"parking request");
    this->act_parking_request->setStatusTip(tr("parking request"));
    connect(act_parking_request,&QAction::triggered,this,&OwnerModule::slot_parking_request);

    this->act_parking_show = new QAction(QIcon(info.picture_path + "find.jpg"),"parking show");
    this->act_parking_show->setStatusTip(tr("parking show"));
    connect(act_parking_show,&QAction::triggered,this,&OwnerModule::slot_parking_show);


    //业主缴费
    this->act_payment_select = new QAction(QIcon(info.picture_path + "paymanage.png"),"payment select");
    this->act_payment_select->setStatusTip(tr("payment select"));
    connect(act_payment_select,&QAction::triggered,this,&OwnerModule::slot_payment_select);

    this->act_payment_self_service = new QAction(QIcon(info.picture_path + "price.png"),"payment self service");
    this->act_payment_self_service->setStatusTip(tr("payment self service"));
    connect(act_payment_self_service,&QAction::triggered,this,&OwnerModule::slot_payment_self_service);

}
void OwnerModule::slot_parking_request(){



}
void OwnerModule::slot_parking_show(){



}


void OwnerModule::slot_payment_select(){

}

void OwnerModule::slot_payment_self_service(){

}
