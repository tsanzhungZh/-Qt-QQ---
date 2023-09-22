
#ifndef GLOBALKEEPER_H
#define GLOBALKEEPER_H


#include <QObject>
#include "Interface/databaseaction.h"
#include "Module/systemwindowview.h"
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
