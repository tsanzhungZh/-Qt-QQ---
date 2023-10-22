
#ifndef WORKERMODULE_H
#define WORKERMODULE_H

#include "basemodule.h"
#include <QMenu>
#include <QObject>
#include "workerUI/workermdui_add_owner.h"
#include "workerUI/workermdui_parking_add.h"
#include "workerUI/workermdui_parking_rent.h"
#include "workerUI/workermdui_price_manage.h"
#include"workerUI/workermdui_get_price.h"
class WorkerModule : public BaseModule
{
    Q_OBJECT
public:
    explicit WorkerModule(QObject *parent = nullptr);

    //业主管理
    QMenu *menu_owner_info;
    QAction *act_owner_find;
    QAction *act_owner_alter;
    QAction *act_owner_registered;
    QAction *act_owner_delete;


    //车位管理
    QMenu *menu_parking_manage;
    QAction *act_show_parking_info;
    QAction *act_add_parking_info;
    QAction *act_modify_parking_info;
    QAction *act_del_parking_info;
    QAction *act_parking_rent;

    //缴费管理
    QMenu *menu_payment_manage;
    QAction *act_price_manage;
    QAction *act_payment_select;
    QAction *act_get_payment;

    //故障查询和维护
    QMenu *menu_issue_manage;
    QAction *act_issue_select;
    QAction *act_issue_repair;

    WorkerMdUI_add_owner* regist_new_owner_func;
    WorkerMdUI_parking_add* add_parking_func;
    WorkerMdUI_parking_rent* rent_parking_func;
    WorkerMdUI_price_manage* price_manage;
    WorkerMdUI_get_price* get_price_func;




private:

    void module_init(void);

    void menu_init(void);

    void act_init(void);

public slots:
    //业主管理
    void slot_owner_find();
    void slot_owner_alter();
    void slot_owner_registered();
    void slot_owner_delete();

    //车位管理
    void slot_show_parking_info();
    void slot_add_parking_info();
    void slot_modify_parking_info();
    void slot_del_parking_info();
    void slot_parking_rent();

    //缴费管理
    void slot_price_manage();
    void slot_payment_select();
    void slot_get_payment();


    //故障维护
    void slot_issue_select();
    void slot_issue_repair();

};

#endif // WORKERMODULE_H
