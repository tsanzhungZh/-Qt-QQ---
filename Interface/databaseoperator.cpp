
#include "Interface/databaseoperator.h"
#include "debug.h"


DataBaseOperator::DataBaseOperator(QString path,QObject *parent)
    : QObject{parent}
{
    if(!path.isEmpty()){
        this->DataBasePath = path;
    }
    this->init_Database();
#ifdef DATABASE_OPERATER
    qDebug()<<"EDataBaseOperator:"<<"1";
#endif
}

void DataBaseOperator::init_Database()
{

    this->Res = new QList<QMap<QString, QVariant>>;

    this->DataBase = QSqlDatabase::addDatabase("QSQLITE");//连接名为E_CHAT_CONNECTION
    this->DataBase.setDatabaseName(this->DataBasePath);
    if(!this->DataBase.open()){
        QMessageBox::warning(0,"error",DataBase.lastError().text());
        return;
    }

    this->Query = new QSqlQuery(this->DataBase);

}
QList<QMap<QString, QVariant>> *DataBaseOperator::SELECT(QString table,QString targets,QString filter)
{

    if(!this->Res->isEmpty()) this->Res->clear();
    QString str;
    if(filter.size()==0){//不设置过滤器
        str = QString("SELECT %1 FROM %2;").arg(targets).arg(table);

    }
    else{//设置过滤器
        str = QString("SELECT %1 FROM %2 WHERE %3;").arg(targets).arg(table).arg(filter);
    }
#ifdef DATABASE_OPERATER
    qDebug()<<"EDataBaseOperator:"<<str;
#endif
    this->Query->exec(str);

    while(this->Query->next()){//遍历所有记录
        QMap<QString, QVariant> record;
        //遍历所有字段
#ifdef DATABASE_OPERATER
        qDebug()<<"EDataBaseOperator:"<<"find record!";
#endif
        for(int i=0;i<this->Query->record().count();i++){//sqlQuery.record().value(i)

            QString fieldName = this->Query->record().fieldName(i);
            QVariant value = this->Query->record().value(i);
            record[fieldName] = value;
        }
        this->Res->append(record);
    }

    return Res;
}
void DataBaseOperator::INSERT(QString table,QString values,QString column)
{
    QString str;
    if(column.size()==0){//不指定字段，即直接按顺序录入值。
        str = QString("INSERT INTO %1 VALUES (%2)").arg(table).arg(values);
    }
    else{
        str = QString("INSERT INTO %1 (%2) VALUES (%3)").arg(table).arg(column).arg(values);
    }
#ifdef DATABASE_OPERATER
    qDebug()<<"EDataBaseOperator:"<<str;
#endif
    this->Query->exec(str);


}
void DataBaseOperator::UPDATE(QString table,QMap<QString,QVariant> map,QString filter)
{
    QString str;
    QString targetChange="";


    QMap<QString,QVariant>::const_iterator it = map.constBegin();
    int counter=0;
    while (it != map.constEnd())
    {
#ifdef DATABASE_OPERATER
        qDebug()<<it.key()<<it.value().toString();
#endif
        targetChange += counter?",":"" + QString("%1 = %2").arg(it.key()).arg("\'"+it.value().toString()+"\'");
        ++it;
        counter=1;
    }


    str = QString("UPDATE %1 SET ").arg(table) + targetChange + QString(" WHERE %1").arg(filter);

#ifdef DATABASE_OPERATER
    qDebug()<<"EDataBaseOperator:"<<str;
#endif

    this->Query->exec(str);

}
void DataBaseOperator::DELETE(QString table,QString filter)
{
    QString str;

    if(filter.size()==0){
        str = QString("DELETE FROM %1").arg(table);
    }
    else{
        str = QString("DELETE FROM %1 WHERE %2").arg(table).arg(filter);
    }
#ifdef DATABASE_OPERATER
    qDebug()<<"EDataBaseOperator:"<<str;
#endif
    this->Query->exec(str);


}
QSqlDatabase* DataBaseOperator::get_database(){

    return &this->DataBase;

}
