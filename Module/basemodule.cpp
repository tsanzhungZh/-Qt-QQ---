
#include "Module/basemodule.h"
#include "debug.h"
BaseModule::BaseModule(QObject *parent)
    : QObject{parent}
{

}
void BaseModule::basemod_init(){




}
void BaseModule::reload_model(void){

    if(!this->model->select())
    {
#ifdef DEBUG_UNIT_DATABASE
        qDebug()<<"in \"basemodule.h\"reload_model :reload model error!";
#endif
        return;
    }

    //this->model->setHeaderData(this->model->fieldIndex("username"),Qt::Horizontal,"password");
    this->table_view->repaint();

}
