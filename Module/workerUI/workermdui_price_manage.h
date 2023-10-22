#ifndef WORKERMDUI_PRICE_MANAGE_H
#define WORKERMDUI_PRICE_MANAGE_H

#include <QWidget>
#include <QModelIndex>
namespace Ui {
class WorkerMdUI_price_manage;
}

class WorkerMdUI_price_manage : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerMdUI_price_manage(QWidget *parent = nullptr);
    ~WorkerMdUI_price_manage();
    QModelIndex cur_index;
private slots:
    void on_pushButton_clicked();

private:
    Ui::WorkerMdUI_price_manage *ui;
};

#endif // WORKERMDUI_PRICE_MANAGE_H
