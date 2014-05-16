#-------------------------------------------------
#
# Project created by QtCreator 2014-03-24T23:28:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VDMS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newusersetup.cpp \
    forgotpassworddialog.cpp \
    loginpage.cpp \
    user.cpp \
    DownloadManager.cpp \
    stocksearch.cpp \
    stock.cpp \
    stocklist.cpp \
    dummyfordownload.cpp

HEADERS  += mainwindow.h \
    newusersetup.h \
    forgotpassworddialog.h \
    loginpage.h \
    user.h \
    DownloadManager.h \
    stocksearch.h \
    stock.h \
    stocklist.h \
    dummyfordownload.h

FORMS    += mainwindow.ui \
    newusersetup.ui \
    forgotpassworddialog.ui \
    loginpage.ui \
    stocksearch.ui \
    dummyfordownload.ui
