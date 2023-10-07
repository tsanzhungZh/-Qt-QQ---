
#ifndef BASEMODULE_H
#define BASEMODULE_H


#include <QObject>
#include <QSqlTableModel>
#include <QTableView>



QT_BEGIN_NAMESPACE
namespace Ui { class BaseModUI; }
QT_END_NAMESPACE
/* @description the base module , and the son of managermodule , workermodule and ownermudule
 * this provide
 * @since 1.01
 * @verson
 * 1.01  provide the database sql table and model
 */
class BaseModule : public QObject
{
    Q_OBJECT
public:
    explicit BaseModule(QObject *parent = nullptr);
    //‘§¿¿±Ì
    QSqlTableModel  *model;
    QTableView *table_view;


    void reload_model(void);

private:
    void basemod_init();

signals:

};


#endif // BASEMODULE_H
