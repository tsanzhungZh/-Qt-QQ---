#ifndef OWNERMDUI_PARKING_REQ_H
#define OWNERMDUI_PARKING_REQ_H

#include <QWidget>

namespace Ui {
class OwnerMdUI_parking_req;
}

class OwnerMdUI_parking_req : public QWidget
{
    Q_OBJECT

public:
    explicit OwnerMdUI_parking_req(QWidget *parent = nullptr);
    ~OwnerMdUI_parking_req();

private:
    Ui::OwnerMdUI_parking_req *ui;

public slots:
    void slot_add();

private slots:
    void on_pushButton_clicked();
};

#endif // OWNERMDUI_PARKING_REQ_H
