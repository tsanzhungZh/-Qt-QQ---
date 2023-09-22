
#ifndef DATABASEACTION_H
#define DATABASEACTION_H


#include <QObject>
#include "Interface/databaseoperator.h"



class DataBaseAction : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseAction(QString Path,QObject *parent = nullptr);

    //select user password
    QString select_usr_password(int mode,qint64 usrname);
    DataBaseOperator *db_operater;
private:



private slots:

signals:

};




#endif // DATABASEACTION_H
