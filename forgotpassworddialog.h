#ifndef FORGOTPASSWORDDIALOG_H
#define FORGOTPASSWORDDIALOG_H

#include <QDialog>
# include "ui_forgotpassworddialog.h"
# include <QtCore>
# include <QtGui>
#include <QMessageBox>

namespace Ui {
class ForgotPasswordDialog;
}

class ForgotPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ForgotPasswordDialog(QWidget *parent = 0);
    ~ForgotPasswordDialog();

private slots:
    void on_btnSubPassRetrieve_clicked();

private:
    Ui::ForgotPasswordDialog *ui;
};

#endif // FORGOTPASSWORDDIALOG_H
