
#ifndef OWNERMODULE_H
#define OWNERMODULE_H

#include "basemodule.h"

#include <QObject>


class OwnerModule : public BaseModule
{
    Q_OBJECT
public:
    explicit OwnerModule(QObject *parent = nullptr);

    //业主车位管理
    QMenu *menu_my_parking;
    QAction *act_parking_request;
    QAction *act_parking_show;

    //业主缴费
    QMenu *menu_payment_manage;
    QAction *act_payment_select;
    QAction *act_payment_self_service;

    //故障报修
    QMenu *menu_issue_report;
    QAction *act_issue_report;
    QAction *act_issue_process;
    QAction *act_issue_evaluate;

private:

    void module_init(void);
    void menu_init(void);
    void act_init(void);

public slots:

    void slot_parking_request();
    void slot_parking_show();


    void slot_payment_select();
    void slot_payment_self_service();


    void slot_issue_report();
    void slot_issue_process();
    void slot_issue_evaluate();




};

#endif // OWNERMODULE_H
