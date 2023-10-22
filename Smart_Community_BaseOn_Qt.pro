QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Interface/databaseaction.cpp \
    Interface/databaseoperator.cpp \
    Interface/tablemodelaction.cpp \
    Module/basemodule.cpp \
    Module/managerUI/managermdui_free_approve.cpp \
    Module/managerUI/managermdui_free_confirm.cpp \
    Module/managerUI/managermodui_add.cpp \
    Module/managerUI/managermodui_alter.cpp \
    Module/managermodule.cpp \
    Module/ownerUI/ownermdui_parking_req.cpp \
    Module/ownermodule.cpp \
    Module/systemwindowview.cpp \
    Module/workerUI/workermdui_add_owner.cpp \
    Module/workerUI/workermdui_get_price.cpp \
    Module/workerUI/workermdui_parking_add.cpp \
    Module/workerUI/workermdui_parking_rent.cpp \
    Module/workerUI/workermdui_price_manage.cpp \
    Module/workermodule.cpp \
    Tools/globalkeeper.cpp \
    Tools/info.cpp \
    debug.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    Interface/databaseaction.h \
    Interface/databaseoperator.h \
    Interface/tablemodelaction.h \
    Module/basemodule.h \
    Module/managerUI/managermdui_free_approve.h \
    Module/managerUI/managermdui_free_confirm.h \
    Module/managerUI/managermodui_add.h \
    Module/managerUI/managermodui_alter.h \
    Module/managermodule.h \
    Module/ownerUI/ownermdui_parking_req.h \
    Module/ownermodule.h \
    Module/systemwindowview.h \
    Module/workerUI/workermdui_add_owner.h \
    Module/workerUI/workermdui_get_price.h \
    Module/workerUI/workermdui_parking_add.h \
    Module/workerUI/workermdui_parking_rent.h \
    Module/workerUI/workermdui_price_manage.h \
    Module/workermodule.h \
    Tools/all_include.h \
    Tools/globalkeeper.h \
    Tools/info.h \
    debug.h \
    widget.h

FORMS += \
    Module/managerUI/managermdui_free_approve.ui \
    Module/managerUI/managermdui_free_confirm.ui \
    Module/managerUI/managermodui_add.ui \
    Module/managerUI/managermodui_alter.ui \
    Module/ownerUI/ownermdui_parking_req.ui \
    Module/systemwindowview.ui \
    Module/workerUI/workermdui_add_owner.ui \
    Module/workerUI/workermdui_get_price.ui \
    Module/workerUI/workermdui_parking_add.ui \
    Module/workerUI/workermdui_parking_rent.ui \
    Module/workerUI/workermdui_price_manage.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README \
    Tools/README \
    image/add.png \
    image/addcarstation.png \
    image/addhouse.png \
    image/attend.jpg \
    image/attend.png \
    image/attend1.png \
    image/carstation.htm \
    image/carstation.png \
    image/carstation1.png \
    image/confirm.jpg \
    image/confirm1.jpg \
    image/confirm1.png \
    image/confirm2.png \
    image/del.png \
    image/deladdcarstation.png \
    image/free.jpg \
    image/free.png \
    image/free1.png \
    image/houses.png \
    image/issuerepair.png \
    image/issueshow.png \
    image/pay.png \
    image/paymanage.png \
    image/price.png \
    image/rentcarstation.png \
    image/show.png \
    image/windows.jpg

RESOURCES += \
    resouce.qrc
