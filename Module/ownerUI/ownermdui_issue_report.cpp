#include "ownermdui_issue_report.h"
#include "ui_ownermdui_issue_report.h"
#include <QMessageBox>
#include "Tools/globalkeeper.h"
extern GlobalKeeper* global_keeper;
OwnerMdUI_issue_report::OwnerMdUI_issue_report(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnerMdUI_issue_report)
{
    ui->setupUi(this);
}

OwnerMdUI_issue_report::~OwnerMdUI_issue_report()
{
    delete ui;
}

void OwnerMdUI_issue_report::on_pushButton_clicked()
{
    QSqlTableModel* model;

    model = global_keeper->get_model();

    int row = model->rowCount();
    qint64 username = this->ui->lineEdit_username->text().toLongLong();
    QString reason = this->ui->lineEdit_reason->text();
    QString desc = this->ui->lineEdit_descrip->text();
    QString time = this->ui->lineEdit_time->text();

    model->insertRow(row);

    model->setData(model->index(row,0),username);
    model->setData(model->index(row,1),reason);
    model->setData(model->index(row,2),desc);
    model->setData(model->index(row,3),time);


    if(!model->submitAll()){
        QMessageBox::question(this,
                              tr("error"),
                              tr("error,please do again!"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
    }
}

