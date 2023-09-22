
#ifndef INFO_H
#define INFO_H

#include <QString>
#include <QList>
enum login_mode_enum{

    e_owner = 0x0,
    e_worker,
    e_manager,
    e_error_mode ,
};




#if 0
typedef struct login_mode_db_tablename_st{

    QString owner = "owner_login";
    QString worker = "worker_login";
    QString manager = "manager_login";

}login_mode_db_tablename_t;
#endif




/* @funcname: get_xmode_login_db_tablename
 * @brief: 根据指定模式(worker/owner/manager)选择对应的登录界面的数据库表名
 * @param: mode
 * @ret: table name
 */
QString get_xmode_login_db_tablename(int xmode);

class Info
{
public:
    Info();
    QString picture_path = ":/image/";
};

#endif // INFO_H
