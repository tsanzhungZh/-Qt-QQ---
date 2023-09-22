#include "systemwindowview.h"
#include "ui_systemwindowview.h"

SystemWindowView::SystemWindowView(int mode,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SystemWindowView)
{
    ui->setupUi(this);
}

SystemWindowView::~SystemWindowView()
{
    delete ui;
}
