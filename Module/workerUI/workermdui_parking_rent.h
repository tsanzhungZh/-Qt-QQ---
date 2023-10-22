#ifndef WORKERMDUI_PARKING_RENT_H
#define WORKERMDUI_PARKING_RENT_H

#include <QWidget>

namespace Ui {
class WorkerMdUI_parking_rent;
}

class WorkerMdUI_parking_rent : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerMdUI_parking_rent(QWidget *parent = nullptr);
    ~WorkerMdUI_parking_rent();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WorkerMdUI_parking_rent *ui;
};

#endif // WORKERMDUI_PARKING_RENT_H
