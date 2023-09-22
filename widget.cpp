
#include "widget.h"
#include "ui_widget.h"
#include "Tools/all_include.h"
/*
 * @version 1.0
 * @author ztc
 * @date 2023/9/22
 * @description The login interface and login UI display and related business logic
 */



static void gk_init_systemwindowview(int mode);
extern GlobalKeeper* global_keeper;

//@since 1.0
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->load_login_mode();
}

Widget::~Widget()
{
    delete ui;
}
/* @funcname: load_login_mode
 * @brief: ����UI�����radioButton��һ��������
 * @param: void
 * @ret: void
 */
void Widget::load_login_mode(){
    this->login_mode_array = new QList<QRadioButton*>;


    this->login_mode_array->append(ui->radioButton_login_owner);
    this->login_mode_array->append(ui->radioButton_login_worker);
    this->login_mode_array->append(ui->radioButton_login_manager);

}
/* @funcname: get_login_mode
 * @brief: ����UI����radioButton��checkedѡ���ȡ��¼����UI�ĵ�¼ģʽ(worker/owner/manager)
 * @param: void
 * @ret: mode value by enum
 */
int Widget::get_login_mode(){

    if(this->login_mode_array->size()!=LOGIN_MODE_NUM){

        return e_error_mode;

    }else{
        int counter=0;
        for(auto x:*this->login_mode_array){

            if(x->isChecked()){

#ifdef DEBUG_FLAG
                qDebug()<<"iter : "<<counter<<"  "<<"mode : "<<x;
#endif

                return counter;
            }
            ++counter;
        }
    }
#ifdef DEBUG_FLAG
    qDebug()<<"not checked mode !";
#endif
    return e_error_mode;

}
/* @funcname: on_pushButton_login_login_clicked
 * @brief: UI��¼��ť�Ĳۣ���Ӧѡ��ͬģʽ�µ����ݿ��еĵ�¼��ϢУ��
 * @param: void
 * @ret: void
 */
void Widget::on_pushButton_login_login_clicked()
{
    int cur_mode = this->get_login_mode();
    //����ģʽ�ж�
    if(cur_mode==e_error_mode){

        QMessageBox::question(this,
                              tr("error"),
                              tr("running error , please check mode before enter!"),
                              QMessageBox::Ok | QMessageBox::Cancel,
                              QMessageBox::Ok);
        return;

    }else{
        //�����п�
        if(ui->lineEdit_login_username->text().isEmpty()||
            ui->lineEdit_login_password->text().isEmpty()){
            QMessageBox::question(this,
                                  tr("error"),
                                  tr("please input username or password!"),
                                  QMessageBox::Ok | QMessageBox::Cancel,
                                  QMessageBox::Ok);
            return;
        }

        //�Ա����ݿ����룬�˶���Ϣ
        QString db_password = global_keeper->database_action->
                select_usr_password(cur_mode,
                            ui->lineEdit_login_username->text().toLongLong());
        //�˶Գɹ������ϵͳ
        if(ui->lineEdit_login_password->text()==db_password){
            gk_init_systemwindowview(cur_mode);


        }else{
            QMessageBox::question(this,
                                  tr("password error"),
                                  tr("password error , please check username and password before login!"),
                                  QMessageBox::Ok | QMessageBox::Cancel,
                                  QMessageBox::Ok);


        }




    }

}
/* @funcname: gk_init_systemwindowview
 * @brief: ��ȫ�ֱ����߳�ʼ��ϵͳģ���UI
 * @param: mode
 * @ret: void
 */
void gk_init_systemwindowview(int mode){

    global_keeper->sys_win_view = new SystemWindowView(mode);
    global_keeper->sys_win_view->show();

}
