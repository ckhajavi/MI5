#ifndef USER_H
#define USER_H

#include <QString>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include<Qmap>
#include<QStringList>
#include<stocklist.h>

using namespace std;


enum enumGender { MALE, FEMALE };

class User
{
public:
   friend class StockList;
    //default constructor
    //friend class NewUserSetup;
    User();
    ~User();
    StockList *userStockList; //list of stocks

    void setStockFile(); //sets the path to the where the stock list is held
    void setFileName(); //sets the path to where the user info is stored
    void setFileName(const QString&); //overloaded the above function
    bool setDirectory();    //sets the directory of the userInfo.
    bool loadUser();      //reads the user info from a text file, puts it into a Map and sets member variables to their corresponding values in the map
     bool loadStockList(); //reads the stockList from a text file, puts it into a Map and sets member variables to their corresponding values in the map
    void saveUser();       //reads the user info, in the form of a map to a text file
    bool saveStockList();  //reads the list of stocks, in the form of a map to a text file

    QString getFileName() const;
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
    void setUserFunds(double);


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
    double totalCostOfStocks(const StockList&);
    double getUserFunds() const;

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
    QMap<QString, QString> userMap; //holds the user information in a map, sorted by variable name. variable name is the key
    QStringList userArray; //holds the user info, until it is written to a the userMap. We aren't using this anymore actually
    QString fileName; //holds the path to the text file of where we are storing the user's info
    QString stockFile; //holds the path to the text file of where we are storing the list of stocks
    double userFunds;
};

#endif // USER_H
