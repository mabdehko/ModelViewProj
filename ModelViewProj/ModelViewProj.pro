#-------------------------------------------------
#
# Project created by QtCreator 2014-08-31T12:29:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ModelViewProj
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    qcustomplot.cpp \
    dialogplot.cpp

HEADERS  += dialog.h \
    qcustomplot.h \
    dialogplot.h

FORMS    += dialog.ui \
    dialogplot.ui

RESOURCES += \
    MyResources.qrc
