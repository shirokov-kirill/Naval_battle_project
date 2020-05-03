######################################################################
# Automatically generated by qmake (3.1) Thu Mar 26 19:34:54 2020
######################################################################

TEMPLATE = app
TARGET = client
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
QT += widgets
QT += network
HEADERS += mainwindow.h \
    Controller.h \
    Defines.h \
    Images.h \
    Model.h \
    Utility.h \
    ../../project/include/Player.h \
    ../../project/include/Board.h \
    ../../project/include/ShipPlacement.h
FORMS += mainwindow_2.ui
SOURCES += main.cpp mainwindow.cpp \
    Controller.cpp \
    Images.cpp \
    Utility.cpp \
    ../../project/src/Board.cpp \
    ../../project/src/Player.cpp
RESOURCES += res.qrc