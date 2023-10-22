#ifndef WORKERMDUI_PARKING_ADD_H
#define WORKERMDUI_PARKING_ADD_H

#include <QWidget>

namespace Ui {
class WorkerMdUI_parking_add;
}

class WorkerMdUI_parking_add : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerMdUI_parking_add(QWidget *parent = nullptr);
    ~WorkerMdUI_parking_add();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WorkerMdUI_parking_add *ui;
};

#endif // WORKERMDUI_PARKING_ADD_H
