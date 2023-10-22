#ifndef MANAGERMDUI_FREE_CONFIRM_H
#define MANAGERMDUI_FREE_CONFIRM_H

#include <QWidget>

namespace Ui {
class ManagerMdUI_free_confirm;
}

class ManagerMdUI_free_confirm : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerMdUI_free_confirm(QWidget *parent = nullptr);
    ~ManagerMdUI_free_confirm();

private slots:
    void on_pushButton_Done_clicked();

private:
    Ui::ManagerMdUI_free_confirm *ui;
};

#endif // MANAGERMDUI_FREE_CONFIRM_H
