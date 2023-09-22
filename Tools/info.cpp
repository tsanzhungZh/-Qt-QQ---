
#include "info.h"
#include "debug.h"
#include "qdebug.h"
QList<QString> login_mode_db_tablename_arry = {
    "owner_login",
    "worker_login",
    "manager_login"
};


Info::Info()
{

}


/* @funcname: get_xmode_login_db_tablename
 * @brief: 根据指定模式(worker/owner/manager)选择对应的登录界面的数据库表名
 * @param: mode
 * @ret: table name
 */
QString get_xmode_login_db_tablename(int xmode){

    qDebug()<<"get_xmode_login_db_table mode : "<<xmode;

    if(xmode>0 && xmode<=3){

        return login_mode_db_tablename_arry[xmode];

    }else{
        return "";
    }
}
