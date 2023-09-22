
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QList>
#include <QRadioButton>
#include "debug.h"
#include "Tools/info.h"
#include <QMessageBox>
#define LOGIN_MODE_NUM 3
/*
 * @version 1.0
 * @author ztc
 * @date 2023/9/22
 * @description The login interface and login UI display and related business logic
 */

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


/* @description the login class
 * @since 1.0
 */
class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_login_login_clicked();

private:
    Ui::Widget *ui;

    QList<QRadioButton*> *login_mode_array;

    void load_login_mode(void);

    int get_login_mode(void);
};

#endif // WIDGET_H
