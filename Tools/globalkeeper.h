
#ifndef GLOBALKEEPER_H
#define GLOBALKEEPER_H
/*
 * @version 1.0
 * @author ztc
 * @date 2023/9/22
 * @description The global class and  for convenient manage
 */

#include <QObject>
#include "Interface/databaseaction.h"
#include "Module/systemwindowview.h"


//È«¾ÖÎ¬³ÖÆ÷
class GlobalKeeper : public QObject
{
    Q_OBJECT
public:
    explicit GlobalKeeper(QObject *parent = nullptr);
    DataBaseAction* database_action;
    SystemWindowView* sys_win_view;
signals:

};

#endif // GLOBALKEEPER_H
