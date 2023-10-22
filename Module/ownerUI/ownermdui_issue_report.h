#ifndef OWNERMDUI_ISSUE_REPORT_H
#define OWNERMDUI_ISSUE_REPORT_H

#include <QWidget>

namespace Ui {
class OwnerMdUI_issue_report;
}

class OwnerMdUI_issue_report : public QWidget
{
    Q_OBJECT

public:
    explicit OwnerMdUI_issue_report(QWidget *parent = nullptr);
    ~OwnerMdUI_issue_report();

private slots:
    void on_pushButton_clicked();

private:
    Ui::OwnerMdUI_issue_report *ui;
};

#endif // OWNERMDUI_ISSUE_REPORT_H
