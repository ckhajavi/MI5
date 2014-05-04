#include "forgotpassworddialog.h"

#include <iostream>
using namespace std;

ForgotPasswordDialog::ForgotPasswordDialog(QWidget *parent) : QDialog(parent), ui(new Ui::ForgotPasswordDialog)
{

    ui->setupUi(this);
    delete ui;
}

ForgotPasswordDialog::~ForgotPasswordDialog()
{
    delete ui;
}

void ForgotPasswordDialog::on_btnSubPassRetrieve_clicked()
{
    QMessageBox::information(this, "Password Retrieval", "You're an asshole for forgetting your passowrd!");
}
