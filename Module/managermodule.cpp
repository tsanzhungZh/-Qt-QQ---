
#include "managermodule.h"
#include "Tools/info.h"
#include "Tools/globalkeeper.h"
#include <QAction>
extern Info info;
extern GlobalKeeper *global_keeper;
ManagerModule::ManagerModule(QObject *parent)
    : BaseModule(parent)
{
    this->module_init();


    slot_show_user();
}
void ManagerModule::module_init(){
    this->act_init();
    this->menu_init();

}
void ManagerModule::menu_init(){
    //usermanage
    this->menu_manager = new QMenu("user manage");

    this->menu_manager->addAction(this->act_add_user);
    this->menu_manager->addAction(this->act_show_user);
    this->menu_manager->addAction(this->act_alter_user);
    this->menu_manager->addAction(this->act_del_user);


    //attendance manage
    this->menu_attendance = new QMenu("attendance manage");
    this->menu_attendance->addAction(this->act_free_confirm);
    this->menu_attendance->addAction(this->act_free_approve);
    this->menu_attendance->addAction(this->act_find_attend);


}
void ManagerModule::act_init(){
    //usermanage
    this->act_add_user = new QAction(QIcon(info.picture_path + "add.png"),"add user");
    this->act_add_user->setStatusTip(tr("add user"));
    connect(act_add_user,&QAction::triggered,this,&ManagerModule::slot_add_user);

    this->act_show_user = new QAction(QIcon(info.picture_path + "show.png"),"show user");
    this->act_show_user->setStatusTip(tr("show user"));
    connect(act_show_user,&QAction::triggered,this,&ManagerModule::slot_show_user);

    this->act_alter_user = new QAction(QIcon(info.picture_path + "attend.png"),"alter user");
    this->act_alter_user->setStatusTip(tr("alter user"));
    connect(act_alter_user,&QAction::triggered,this,&ManagerModule::slot_alter_user);

    this->act_del_user = new QAction(QIcon(info.picture_path + "free.png"),"del user");
    this->act_del_user->setStatusTip(tr("del user"));
    connect(act_del_user,&QAction::triggered,this,&ManagerModule::slot_del_user);



    //attendance manage
    this->act_free_confirm = new QAction(QIcon(info.picture_path + "free.jpg"),"free confirm");
    this->act_free_confirm->setStatusTip(tr("free confirm"));
    connect(act_free_confirm,&QAction::triggered,this,&ManagerModule::slot_free_confirm);

    this->act_free_approve = new QAction(QIcon(info.picture_path + "approve.jpg"),"free approve");
    this->act_free_approve->setStatusTip(tr("free approve"));
    connect(act_free_approve,&QAction::triggered,this,&ManagerModule::slot_free_approve);

    this->act_find_attend = new QAction(QIcon(info.picture_path + "find.jpg"),"find attend");
    this->act_find_attend->setStatusTip(tr("find attend"));
    connect(act_find_attend,&QAction::triggered,this,&ManagerModule::slot_find_attend);



}
void ManagerModule::slot_add_user(){
    this->add_func = new ManagerModUI_add;
    this->reload_model();
}
void ManagerModule::slot_show_user(){

    QString cur_table = "worker_login";

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
void ManagerModule::slot_alter_user(){
    this->alter_func = new ManagerModUI_alter;
    this->reload_model();
}
void ManagerModule::slot_del_user(){
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

    this->reload_model();

}

void ManagerModule::slot_free_confirm(){

}
void ManagerModule::slot_free_approve(){

}
void ManagerModule::slot_find_attend(){

}





