
#ifndef MANAGERMODULE_H
#define MANAGERMODULE_H

#include "basemodule.h"
#include <QMenu>
#include <QObject>
#include "Module/managerUI/managermodui_add.h"
#include "Module/managerUI/managermodui_alter.h"

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

    ManagerModUI_add* add_func;
    ManagerModUI_alter* alter_func;

private:

    void module_init(void);

    void menu_init(void);

    void act_init(void);


public slots:
    void slot_add_user();
    void slot_show_user();
    void slot_alter_user();
    void slot_del_user();

};



#endif // MANAGERMODULE_H
