#include "forgotpassworddialog.h"

#include <iostream>
using namespace std;

ForgotPasswordDialog::ForgotPasswordDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ForgotPasswordDialog)
{

    ui->setupUi(this);
}

ForgotPasswordDialog::~ForgotPasswordDialog()
{
    delete ui;
}

void ForgotPasswordDialog::on_btnSubPassRetrieve_clicked()
{
    if (ui->lineEditRetrieve->text() == "mprigmore1@gmail.com")
    {
         QMessageBox::information(this, "Password Retrieval", "Your password is: password");
    }
}
