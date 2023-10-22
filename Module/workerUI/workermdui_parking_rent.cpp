#include "workermdui_parking_rent.h"
#include "ui_workermdui_parking_rent.h"
#include <QMessageBox>
WorkerMdUI_parking_rent::WorkerMdUI_parking_rent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkerMdUI_parking_rent)
{
    ui->setupUi(this);
}

WorkerMdUI_parking_rent::~WorkerMdUI_parking_rent()
{
    delete ui;
}

void WorkerMdUI_parking_rent::on_pushButton_clicked()
{
    QMessageBox::question(this,
                          tr("OK"),
                          tr("rent OK!"),
                          QMessageBox::Ok | QMessageBox::Cancel,
                          QMessageBox::Ok);
}

