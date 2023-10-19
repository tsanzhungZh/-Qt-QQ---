

#include <QApplication>

#include "Tools/all_include.h"

#include "Module/systemwindowview.h"
QString database_path = "C:/Users/ztc/Smart_Community.db";

static void load_globalkeeper(void);
static void gk_init_database_action(void);

GlobalKeeper *global_keeper;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    load_globalkeeper();
    gk_init_database_action();

    //Widget w;
    //w.show();

#ifdef DEBUG_GLOBALKEEPER
    //qDebug()<<global_keeper->database_action->select_usr_password(1,1379206136);
#endif
#ifdef DEBUG_SYS_VIEW
    SystemWindowView abc(2);
    abc.show();

    global_keeper->sys_win_view = &abc;
#endif







    return a.exec();

}

static void load_globalkeeper(void){

    global_keeper = new GlobalKeeper();
    return;

}
static void gk_init_database_action(void){

    global_keeper->database_action = new DataBaseAction(database_path);

    return;
}
