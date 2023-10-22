#ifndef WORKERMDUI_GET_PRICE_H
#define WORKERMDUI_GET_PRICE_H

#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>
namespace Ui {
class WorkerMdUI_get_price;
}

class WorkerMdUI_get_price : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerMdUI_get_price(QWidget *parent = nullptr);
    ~WorkerMdUI_get_price();
    QSqlTableModel  *model;
    QTableView *table_view;
private slots:
    void on_pushButton_clicked();

private:
    Ui::WorkerMdUI_get_price *ui;
};

#endif // WORKERMDUI_GET_PRICE_H
