
#ifndef MANAGERMODULE_H
#define MANAGERMODULE_H

#include "basemodule.h"
#include <QMenu>
#include <QObject>
#include "Module/managerUI/managermodui_add.h"
#include "Module/managerUI/managermodui_alter.h"
#include "Module/managerUI/managermdui_free_confirm.h"
#include "Module/managerUI/managermdui_free_approve.h"

class ManagerModule : public BaseModule
{
    Q_OBJECT
public:
    explicit ManagerModule(QObject *parent = nullptr);

    QMenu *menu_manager;
    QAction *act_show_user;
    QAction *act_add_user;
    QAction *act_alter_user;
    QAction *act_del_user;


    QMenu *menu_attendance;
    QAction *act_free_confirm;
    QAction *act_free_approve;
    QAction *act_find_attend;



    ManagerModUI_add* add_func;
    ManagerModUI_alter* alter_func;

    ManagerMdUI_free_confirm* free_confirm_func;
    ManagerMdUI_free_approve* free_approve_func;
private:

    void module_init(void);

    void menu_init(void);

    void act_init(void);


public slots:


    void slot_add_user();
    void slot_show_user();
    void slot_alter_user();
    void slot_del_user();


    void slot_free_confirm();
    void slot_free_approve();
    void slot_find_attend();

};



#endif // MANAGERMODULE_H
