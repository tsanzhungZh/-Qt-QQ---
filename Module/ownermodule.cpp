
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

    //故障报修
    this->menu_issue_report = new QMenu("issue report");
    this->menu_issue_report->addAction(this->act_issue_report);
    this->menu_issue_report->addAction(this->act_issue_process);
    this->menu_issue_report->addAction(this->act_issue_evaluate);

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

    //故障报修
    this->act_issue_report = new QAction(QIcon(info.picture_path + "issuerepair.png"),"issue report");
    this->act_issue_report->setStatusTip(tr("issue report"));
    connect(act_issue_report,&QAction::triggered,this,&OwnerModule::slot_issue_report);

    this->act_issue_process = new QAction(QIcon(info.picture_path + "attend.jpg"),"issue process");
    this->act_issue_process->setStatusTip(tr("issue process"));
    connect(act_issue_process,&QAction::triggered,this,&OwnerModule::slot_issue_process);

    this->act_issue_evaluate = new QAction(QIcon(info.picture_path + "modify.jpg"),"issue evaluate");
    this->act_issue_evaluate->setStatusTip(tr("issue evaluate"));
    connect(act_issue_evaluate,&QAction::triggered,this,&OwnerModule::slot_issue_evaluate);

}
void OwnerModule::slot_parking_request(){
    this->md_parking_req = new OwnerMdUI_parking_req();
    this->md_parking_req->show();

}
void OwnerModule::slot_parking_show(){


    QString cur_table = "parking";

    //this->model = new QSqlTableModel(this,*global_keeper->get_database());
    this->model = new QSqlTableModel(this);
    this->table_view = new QTableView;
    //this->table_view->setModel(this->model);
    this->model->setTable(cur_table);
    //查询数据
    if(!this->model->select())
    {
        qDebug()<<"查询失败";
        return;
    }
    //this->model->setHeaderData(this->model->fieldIndex("username"),Qt::Horizontal,"password");
    this->table_view->setModel(this->model);

    static_cast<SystemWindowView*>(this->parent())->setCentralWidget(this->table_view);

    global_keeper->regist_model(model);
    global_keeper->regist_tableview(table_view);


}


void OwnerModule::slot_payment_select(){

}

void OwnerModule::slot_payment_self_service(){

}

void OwnerModule::slot_issue_report(){

}
void OwnerModule::slot_issue_process(){

}
void OwnerModule::slot_issue_evaluate(){

}
