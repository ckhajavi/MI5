#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "newusersetup.h"
#include "forgotpassworddialog.h"
#include "loginpage.h"

#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <string>
#include <iostream>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btnNewUser_clicked();

    void on_btnForgotPass_clicked();

    void on_btnLogIn_clicked();

    void on_btnExit_clicked();

    void on_btnLogIn_pressed();

private:
    Ui::MainWindow *ui;
    NewUserSetup *newUser;
    ForgotPasswordDialog *forgotPasswordWindow;
    LoginPage *myLoginDialog;
};

#endif // MAINWINDOW_H
