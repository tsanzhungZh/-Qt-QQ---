#ifndef WORKERMDUI_ISSUE_REPORT_H
#define WORKERMDUI_ISSUE_REPORT_H

#include <QWidget>

namespace Ui {
class WorkerMdUI_issue_report;
}

class WorkerMdUI_issue_report : public QWidget
{
    Q_OBJECT

public:
    explicit WorkerMdUI_issue_report(QWidget *parent = nullptr);
    ~WorkerMdUI_issue_report();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WorkerMdUI_issue_report *ui;
};

#endif // WORKERMDUI_ISSUE_REPORT_H
