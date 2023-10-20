#ifndef WORKERMDUI_ADD_OWNER_H
#define WORKERMDUI_ADD_OWNER_H

#include <QWidget>

namespace Ui {
class WorkerMdUI_add_owner;
}

class WorkerMdUI_add_owner : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerMdUI_add_owner(QWidget *parent = nullptr);
    ~WorkerMdUI_add_owner();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WorkerMdUI_add_owner *ui;
};

#endif // WORKERMDUI_ADD_OWNER_H
