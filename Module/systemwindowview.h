#ifndef SYSTEMWINDOWVIEW_H
#define SYSTEMWINDOWVIEW_H

#include <QMainWindow>

namespace Ui {
class SystemWindowView;
}

class SystemWindowView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemWindowView(int mode,QWidget *parent = nullptr);
    ~SystemWindowView();

private:
    Ui::SystemWindowView *ui;
};

#endif // SYSTEMWINDOWVIEW_H
