
#ifndef DATABASEOPERATOR_H
#define DATABASEOPERATOR_H


#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QVariant>
#include <QList>
#include <QSqlRecord>
#include <QMap>
class DataBaseOperator : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseOperator(QString path,QObject *parent = nullptr);
    QSqlQuery *Query;


    QList<QMap<QString, QVariant>> *Res;//执行完sql语句后的返回值，二维向量


    //几个封装好的sql简单语句，设计到多个targets的时候注意使用","分割
    /*
     *
     *
     * SELECT  targets 要寻找的目标值，缺省为全部，filter：过滤器，指定某条件作为相应的过滤器
     *
     * INSERT  values:多个值，之间需要加逗号分割，column：指定的列格式，需要同前面的值的顺序对应
     *
     * UPDATE  map：一个表，key是要加入的列的名字，value是对应列名下的值。使用filter指定哪一个记录
     * 会使用该map作为参数
     *
     * DELETE  filter设置过滤器，直接清除指定过滤器的记录
     */
    QList<QMap<QString, QVariant>> *SELECT(QString table,QString targets = "*",QString filter = "");
    void INSERT(QString table,QString values,QString column = "");//不指定字段时注意插入的值顺序需要一致
    void UPDATE(QString table,QMap<QString,QVariant> map,QString filter);
    void DELETE(QString table,QString filter="");
private:
    QSqlDatabase DataBase;
    QString DataBasePath;

    void init_Database();


signals:

};

#endif // EDATABASEOPERATOR_H
