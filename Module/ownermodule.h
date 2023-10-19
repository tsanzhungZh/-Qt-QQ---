
#ifndef OWNERMODULE_H
#define OWNERMODULE_H

#include "basemodule.h"

#include <QObject>


class OwnerModule : public BaseModule
{
    Q_OBJECT
public:
    explicit OwnerModule(QObject *parent = nullptr);


    QMenu *menu_my_parking;
    QAction *act_parking_request;
    QAction *act_parking_show;




private:

    void module_init(void);
    void menu_init(void);
    void act_init(void);

public slots:
    void slot_parking_request();

    void slot_parking_show();





};

#endif // OWNERMODULE_H
