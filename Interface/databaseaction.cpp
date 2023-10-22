
#include "databaseaction.h"
#include "Tools/info.h"



DataBaseAction::DataBaseAction(QString Path,QObject *parent)
    : QObject{parent}
{
    this->db_operater = new DataBaseOperator(Path);

}

QString DataBaseAction::select_usr_password(int mode,qint64 username){

    QString Key = "username";
    QString Value = "password";

    QList<QMap<QString, QVariant>> *res;
    QString tablename = get_xmode_login_db_tablename(mode);

    res = this->db_operater->SELECT(tablename,Value,QString(Key+" = %1").arg(username));
    if(res == nullptr) return "";
    if(res->size()==0){
        return "";
    }
    else{
        return res->back().value(Value).toString();
    }


}
