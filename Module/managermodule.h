
#ifndef MANAGERMODULE_H
#define MANAGERMODULE_H

#include "basemodule.h"
#include <QMenu>
#include <QObject>


class ManagerModule : public BaseModule
{
    Q_OBJECT
public:
    explicit ManagerModule(QObject *parent = nullptr);

    QMenu *menu_manager;

    QAction *act_show_worker;
    QAction *act_add_worker;
    QAction *act_alter_worker;
    QAction *act_del_worker;


private:
    void module_init(void);

    void menu_init(void);

    void act_init(void);


public slots:
    void slot_add_worker();
    void slot_show_worker();
    void slot_alter_worker();
    void slot_del_worker();

};

#endif // MANAGERMODULE_H
