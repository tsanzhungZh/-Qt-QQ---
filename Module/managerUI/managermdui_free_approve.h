#ifndef MANAGERMDUI_FREE_APPROVE_H
#define MANAGERMDUI_FREE_APPROVE_H

#include "qtableview.h"
#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class ManagerMdUI_free_approve;
}

class ManagerMdUI_free_approve : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerMdUI_free_approve(QWidget *parent = nullptr);
    ~ManagerMdUI_free_approve();
    QSqlTableModel *model;
    QTableView *table_view;

    QModelIndex cur_index;
private slots:
    void on_pushButton_clicked();

private:
    Ui::ManagerMdUI_free_approve *ui;
};

#endif // MANAGERMDUI_FREE_APPROVE_H
