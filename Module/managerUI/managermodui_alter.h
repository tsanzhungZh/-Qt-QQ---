#ifndef MANAGERMODUI_ALTER_H
#define MANAGERMODUI_ALTER_H

#include "qtableview.h"
#include <QWidget>
#include <QSqlTableModel>
namespace Ui {
class ManagerModUI_alter;
}

class ManagerModUI_alter : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerModUI_alter(QWidget *parent = nullptr);
    ~ManagerModUI_alter();
    QSqlTableModel *model;
    QTableView *table_view;

    QModelIndex cur_index;

    bool checked_is_empty(void);
private slots:
    void on_pushButton_cancel_clicked();


    void on_pushButton_alter_clicked();

private:
    void init_ui_info(void);

    Ui::ManagerModUI_alter *ui;
};

#endif // MANAGERMODUI_ALTER_H
