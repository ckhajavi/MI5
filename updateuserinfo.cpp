#include "updateuserinfo.h"
#include "ui_updateuserinfo.h"

UpDateUserInfo::UpDateUserInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpDateUserInfo)
{
    ui->setupUi(this);
    currentUser = new User;
}
void UpDateUserInfo::setCurrentUser(const QString& email)
{
    currentUser->setEmail(email);
    currentUser->setFileName();
    currentUser->loadUser();
}

UpDateUserInfo::~UpDateUserInfo()
{
    delete currentUser;
    delete ui;
}

void UpDateUserInfo::on_pushButton_clicked()
{
    currentUser->setAddr1(ui->lineEdit_address1->text());
    currentUser->setAddr2(ui->lineEdit_address2->text());
    currentUser->setCountry(ui->lineEdit_country->text());
    currentUser->setPassword(ui->lineEdit_password->text());
    currentUser->saveUser();
    this->close();
}
