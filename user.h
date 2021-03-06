#ifndef USER_H
#define USER_H

#include <QString>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDir>
//#include"wrongfiledialog.h"
//#include "addfilepath.h"
#include <QDebug>
#include<Qmap>
#include<QStringList>
#include"stocklist.h"

using namespace std;


enum enumGender { MALE, FEMALE };

class User
{
public:
   friend class StockList;
    //default constructor
    //friend class NewUserSetup;
    User();

    void setFileName();
    void setFileName(const QString&);
    bool loadUser();
    void saveUser();
    //set functions
    void setUserName(const QString&);
    void setPassword(const QString&);
    void setFName(const QString&);
    void setMName(const QString&);
    void setLName( const QString&);
    void setCellPhone(const QString&);
    void setHomePhone(const QString&);
    void setWorkPhone(const QString&);
    void setAge(const QString&);
    void setDOB(const QString&);
    void setSSN(const QString&);
    void setAddr1(const QString&);
    void setAddr2(const QString&);
    void setCity(const QString&);
    void setState(const QString&);
    void setCountry(const QString&);
    void setEmail(const QString&);
    void setSecurityQuestion1( const QString&);
    void setSecurityQuestion2(const QString&);
    void setSecurityAnswer1(const QString&);
    void setSecurityAnswer2(const QString&);
    void setGender(const enumGender&);

    //get methods
    QString getUserName() const;
    QString getFName() const;
    QString getMName() const;
    QString getLName() const;
    QString getCellPhone() const;
    QString getHomePhone() const;
    QString getWorkPhone() const;
    QString getAge() const;
    QString getDOB() const;
    //string getBirthMonth() const;
    //string getBirthYear() const;
   // string getBirthDay() const;
    QString getLastFourSSN() const;
    QString getAddr1() const;
    QString getAddr2() const;
    QString getCity() const;
    QString getState() const;
    QString getCountry() const;
    QString getEmail() const;
    QString getSecurityQuestion1() const;
    QString getSecurityAnswer1() const;
    QString getSecurityQuestion2() const;
    QString getSecurityAnswer2() const;
    QString getPassword() const;
    enumGender getGender() const;

private:
    QString userName;
    QString plainTextPassword;

    QString fName, mName, lName;
    QString cellPhone, homePhone, workPhone;
    QString age;
    QString DOB;
    //QString birthMonth, birthYear, birthDay;
    QString plainTextSSN;
    QString addr1;
    QString addr2;
    QString city;
    QString state;
    QString country;
    QString email;
    QString securityQuestion1;
    QString securityAnswer1;
    QString securityQuestion2;
    QString securityAnswer2;
    enumGender gender;
    QMap<QString, QString> userMap;

    QStringList userArray;
    //wrongFileDialog *wrongFile;
    QString fileName;

};

#endif // USER_H
