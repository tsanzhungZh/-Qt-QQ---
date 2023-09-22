QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Interface/databaseaction.cpp \
    Interface/databaseoperator.cpp \
    Module/systemwindowview.cpp \
    Tools/globalkeeper.cpp \
    Tools/info.cpp \
    debug.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    Interface/databaseaction.h \
    Interface/databaseoperator.h \
    Module/systemwindowview.h \
    Tools/all_include.h \
    Tools/globalkeeper.h \
    Tools/info.h \
    debug.h \
    widget.h

FORMS += \
    Module/systemwindowview.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README \
    Tools/README
