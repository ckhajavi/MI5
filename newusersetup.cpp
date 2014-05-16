#include "newusersetup.h"
#include "ui_newusersetup.h"

NewUserSetup::NewUserSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUserSetup)
{
    ui->setupUi(this);
}

bool NewUserSetup::validate()
{
    //check to see if info matches input wanted still need to implement
    QPalette palette = ui->lineEdit_password->palette();
    palette.setColor(QPalette::Base, QColor(255,0,0));
    QPalette palette2 = ui->lineEdit_email->palette();
    palette2.setColor(QPalette::Base, QColor(255,0,0)); //Red
    int count = 0; //counts the number of errors
    if (ui->lineEdit_password->text() != ui->lineEdit_checkPassword->text())
    {
        ui->lineEdit_password->setPalette(palette);
        ui->lineEdit_checkPassword->setPalette(palette);
        ++count;
    }
    if(ui->lineEdit_email->text() != ui->lineEdit_checkEmail->text())
    {
        ui->lineEdit_email->setPalette(palette2);
        ui->lineEdit_checkEmail->setPalette(palette2);
        ++count;
    }
    if (ui->lineEdit_password->text() == "")
    {
        ui->lineEdit_password->setPalette(palette);
        ++count;
    }
    if(ui->lineEdit_email->text() == "")
    {
        ui->lineEdit_email->setPalette(palette2);
        ++count;
    }
    if( count > 0)
    {
        return false;
    }
    else
        return true;
}

NewUserSetup::~NewUserSetup()
{
    delete ui;
}

void NewUserSetup::on_pushButton1_clicked()
{
    //combo boxes are commented out, need to figure out how to grab text from combo box, also combo boxes produce an error on Mac OSX
    //reset the lineEdits to the color white
    QPalette palette = ui->lineEdit_password->palette();
    palette.setColor(QPalette::Base, QColor(255,255,255));
    ui->lineEdit_password->setPalette(palette);
    ui->lineEdit_checkPassword->setPalette(palette);
    QPalette palette2 = ui->lineEdit_email->palette();
    palette2.setColor(QPalette::Base, QColor(255,255,255)); //Red
    ui->lineEdit_email->setPalette(palette2);
    ui->lineEdit_checkEmail->setPalette(palette2);

    User currentUser;
    if (validate())
    {
        currentUser.setPassword(ui->lineEdit_password->text());
        currentUser.setFName( ui->lineEdit_fName->text());
        currentUser.setMName(ui-> lineEdit_mName ->text());
        currentUser.setLName(ui ->lineEdit_lName ->text());
        currentUser.setAddr1(ui-> lineEdit_addr1->text());
        currentUser.setAddr2(ui-> lineEdit_addr2->text());
        currentUser.setAge(ui->lineEdit_age->text());
        currentUser.setCellPhone(ui->lineEdit_cellPhone->text());
        currentUser.setCity(ui->lineEdit_city->text());
        //currentUser.setState(ui->comboBox_state->text());
        currentUser.setCountry(ui->lineEdit_country ->text());
        currentUser.setDOB(ui->lineEdit_DOB->text());
        currentUser.setEmail(ui->lineEdit_email->text());
        //currentUser.setGender(ui->);
        currentUser.setSecurityAnswer1(ui->lineEdit_securityAnswer1->text());
        currentUser.setSecurityAnswer2(ui->lineEdit_securityAnswer2->text());
        //currentUser.setSecurityQuestion2(ui->comboBox_securityQuestion2);
        //currentUser.setSecurityQuestion1(ui->comboBox_securityQuestion1->text());
        currentUser.setSSN(ui->lineEdit_plainTextSSN->text());
        currentUser.setUserFunds(10000);
        currentUser.setFileName();
        currentUser.saveUser();
    }
    else
    {
        qDebug() << "correct the fields in red" <<endl;
    }

}
