
#ifndef WORKERMODULE_H
#define WORKERMODULE_H

#include "basemodule.h"
#include <QMenu>
#include <QObject>


class WorkerModule : public BaseModule
{
    Q_OBJECT
public:
    explicit WorkerModule(QObject *parent = nullptr);

    QMenu *menu_owner_info;

    QAction *act_owner_find;
    QAction *act_owner_alter;
    QAction *act_owner_registered;
    QAction *act_owner_delete;

private:

    void module_init(void);

    void menu_init(void);

    void act_init(void);

public slots:
    void slot_owner_find();
    void slot_owner_alter();
    void slot_owner_registered();
    void slot_owner_delete();

};

#endif // WORKERMODULE_H
