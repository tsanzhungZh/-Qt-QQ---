
#include "globalkeeper.h"

GlobalKeeper::GlobalKeeper(QObject *parent)
    : QObject{parent}
{

}

QSqlDatabase* GlobalKeeper::get_database(void){

    if(this->database){
        return this->database;
    }else{
        this->database = this->database_action->db_operater->get_database();
        return this->database;
    }


}
void GlobalKeeper::regist_model(QSqlTableModel* model){

    this->current_model = model;


}
void GlobalKeeper::regist_tableview(QTableView* tableview){

    this->current_tableview = tableview;


}
QSqlTableModel* GlobalKeeper::get_model(){

    return this->current_model;


}
QTableView* GlobalKeeper::get_tableview(void){

    return this->current_tableview;

}
