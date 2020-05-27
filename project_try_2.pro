QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller.cpp \
    Images.cpp \
    Utility.cpp \
    botwindow.cpp \
    client.cpp \
    finalwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    menuwindow.cpp \
    server.cpp \
    project/src/Board.cpp \
    project/src/Bot.cpp \
    project/src/Player.cpp

HEADERS += \
    Client.h \
    Controller.h \
    Defines.h \
    Images.h \
    Utility.h \
    botwindow.h \
    finalwindow.h \
    mainwindow.h \
    menuwindow.h \
    Server.h \
    project/include/Board.h \
    project/include/Player.h \
    project/include/Bot.h \
    project/include/ShipPlacement.h

FORMS += \
    botwindow.ui \
    finalwindow.ui \
    mainwindow.ui \
    menuwindow.ui

RESOURCES += res.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
