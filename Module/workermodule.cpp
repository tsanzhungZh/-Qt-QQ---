
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
    this->menu_parking_manage = new QMenu("parking manage");
    this->menu_parking_manage->addAction(this->act_show_parking_info);
    this->menu_parking_manage->addAction(this->act_add_parking_info);
    this->menu_parking_manage->addAction(this->act_modify_parking_info);
    this->menu_parking_manage->addAction(this->act_del_parking_info);
    this->menu_parking_manage->addAction(this->act_parking_rent);

    //管理员的费用管理
    this->menu_payment_manage = new QMenu("payment manage");
    this->menu_payment_manage->addAction(this->act_price_manage);
    this->menu_payment_manage->addAction(this->act_payment_select);
    this->menu_payment_manage->addAction(this->act_get_payment);

    //故障查询和维护
    this->menu_issue_manage = new QMenu("issue manage");
    this->menu_issue_manage->addAction(this->act_issue_select);
    this->menu_issue_manage->addAction(this->act_issue_repair);



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



    //工作人员的缴费管理
    this->act_price_manage = new QAction(QIcon(info.picture_path + "price.png"),"price manage");
    this->act_price_manage->setStatusTip(tr("parking rent"));
    connect(act_price_manage,&QAction::triggered,this,&WorkerModule::slot_price_manage);

    this->act_payment_select = new QAction(QIcon(info.picture_path + "pay.png"),"payment select");
    this->act_payment_select->setStatusTip(tr("payment select"));
    connect(act_payment_select,&QAction::triggered,this,&WorkerModule::slot_payment_select);

    this->act_get_payment = new QAction(QIcon(info.picture_path + "paymanage.png"),"get payment");
    this->act_get_payment->setStatusTip(tr("get payment"));
    connect(act_get_payment,&QAction::triggered,this,&WorkerModule::slot_get_payment);


    //工作人员故障查询和维护
    this->act_issue_select = new QAction(QIcon(info.picture_path + "issueshow.png"),"issue select");
    this->act_issue_select->setStatusTip(tr("issue select"));
    connect(act_issue_select,&QAction::triggered,this,&WorkerModule::slot_issue_select);

    this->act_issue_repair = new QAction(QIcon(info.picture_path + "issuerepair.png"),"issue select");
    this->act_issue_repair->setStatusTip(tr("issue repair"));
    connect(act_issue_repair,&QAction::triggered,this,&WorkerModule::slot_issue_repair);




}
void WorkerModule::slot_owner_find(){

    QString cur_table = "houseowner";

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
    this->model->setHeaderData(this->model->fieldIndex("username"),Qt::Horizontal,"password");
    this->table_view->setModel(this->model);

    static_cast<SystemWindowView*>(this->parent())->setCentralWidget(this->table_view);

    global_keeper->regist_model(model);
    global_keeper->regist_tableview(table_view);
}
void WorkerModule::slot_owner_alter(){






}
void WorkerModule::slot_owner_registered(){
    this->regist_new_owner_func = new WorkerMdUI_add_owner;
    this->regist_new_owner_func->show();
}
void WorkerModule::slot_owner_delete(){

}
void WorkerModule::slot_show_parking_info(){

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
void WorkerModule::slot_add_parking_info(){
    this->add_parking_func = new WorkerMdUI_parking_add;
    this->add_parking_func->show();
}
void WorkerModule::slot_modify_parking_info(){

}
void WorkerModule::slot_del_parking_info(){

    int curRow = this->table_view->currentIndex().row();


    int ret = QMessageBox::warning(static_cast<SystemWindowView*>(this->parent()),tr("delete current user"),tr("are you sure ?"),
                                   QMessageBox::Yes,QMessageBox::No);

    if(ret == QMessageBox::Yes){
        qDebug()<<"Yes delete";
        model->removeRow(curRow);
        model->submitAll();


    }else{
        qDebug()<<"No delete";
        model->revertAll();
    }

    this->slot_show_parking_info();

}
void WorkerModule::slot_parking_rent(){
    this->rent_parking_func = new WorkerMdUI_parking_rent;
    this->rent_parking_func->show();
}

void WorkerModule::slot_price_manage(){

    QString cur_table = "price";

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

    this->price_manage = new WorkerMdUI_price_manage;
    this->price_manage->show();

}
void WorkerModule::slot_payment_select(){

}
void WorkerModule::slot_get_payment(){

    QString cur_table = "price_record";

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


    this->get_price_func = new WorkerMdUI_get_price;
    this->get_price_func->show();
}

void WorkerModule::slot_issue_select(){
    QString cur_table = "issue";

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
    this->issue_report = new WorkerMdUI_issue_report;
    this->issue_report->show();
}
void WorkerModule::slot_issue_repair(){

}
