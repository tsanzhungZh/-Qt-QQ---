#ifndef MANAGERMODUI_ADD_H
#define MANAGERMODUI_ADD_H

#include <QWidget>

namespace Ui {
class ManagerModUI_add;
}

class ManagerModUI_add : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerModUI_add(QWidget *parent = nullptr);
    ~ManagerModUI_add();

    bool checked_is_empty(void);
private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::ManagerModUI_add *ui;
};

#endif // MANAGERMODUI_ADD_H
