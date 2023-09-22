#ifndef SYSTEMWINDOWVIEW_H
#define SYSTEMWINDOWVIEW_H

#include <QMainWindow>
#include "Module/managermodule.h"
#include "QToolBar"
#include "QMenuBar"

namespace Ui {
class SystemWindowView;
}

class SystemWindowView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SystemWindowView(int mode,QWidget *parent = nullptr);
    ~SystemWindowView();

    ManagerModule *manager_mod;


    QMenuBar *menubar;
    QToolBar *toolbar;

    void add_menu(QMenu* menu);

    void add_tool(QAction* action);

private:

    Ui::SystemWindowView *ui;

    void load_window_bar(void);

    void load_xmode_part(int mode);

    void mode_owner_init();
    void mode_worker_init();
    void mode_manager_init();



};

#endif // SYSTEMWINDOWVIEW_H
