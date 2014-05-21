 #include "user.h"


User::User()
//: age(""), birthMonth(""), birthYear(""), birthDay(""), gender(MALE)
{
    userFunds = 10000;
}

bool User::setDirectory(){

    QDir directory;
    fileName = directory.homePath();
    fileName.append("/VDMS_USER");
    QDir directoryTemp(fileName);
    if (!directoryTemp.exists())
    {
        directory.mkdir(fileName);
        return true;
    }
    else
        return false;
}

void User::setFileName()
{
    QDir directory;
    fileName = directory.homePath();
    fileName.append("/VDMS_USER");
    QDir directoryTemp(fileName);
    QString fileNameTemp = fileName;     //temporary string to store fileName
    fileNameTemp.append("/");
    fileNameTemp.append(email);
    QDir directory2(fileNameTemp);
    //directory.setPath(fileNameTemp);
    if (!directoryTemp.exists())        //if there is no VDMS file folder
    {
        directoryTemp.mkdir(fileName);
             //Make VDMS file folder
       //fileName.append("/");
       //fileName.append(email);            // name of user subfolder is userInfo
        //fileName.append(".txt");
       //directory.setPath(fileNameTemp);
       directory2.mkdir(fileNameTemp);
       fileName = fileNameTemp;
       fileName.append("/userInfo.txt");
       //make a folder named after user's email
        //fileName.append("/userInfo.txt");   //set the member variable "fileName" to /.../VDMS_USER/userEmail/userInfo.txt
    }
    else if(directoryTemp.exists() && !directory2.exists() ) // if the main application folder exists but user folder does not
    {
        directory2.mkdir(fileNameTemp);
        fileName = fileNameTemp;
        fileName.append("/userInfo.txt"); //make user email name of user folder
    }
    else
    {
        fileName = fileNameTemp;
        fileName.append("/userInfo.txt");
    }

    qDebug() << fileName;
    
}

//overloaded setfileName
void User::setFileName(const QString& currentEmail)
{
    QDir directory;
    fileName = directory.homePath();
    fileName.append("/VDMS_USER");
    directory.mkdir(fileName);
    fileName.append("/");
    fileName.append(currentEmail);
    fileName.append(".txt");
    qDebug() << fileName;
}

bool User::loadUser()
{
    QFile file(fileName);
    if (!file.exists())
    {
       //wrongFile = new wrongFileDialog();
       //wrongFile -> show();
       //wrongFile->exec();
        //qDebug() << "sorry not found" << endl;
        return false;
    }
    else
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);         //opening file
        QTextStream in(&file);                                    //starting a stream reading from the file we set in setFileName function
        QString line;
        QStringList temp;
        while(!in.atEnd())
        {
            line = in.readLine();                               //reading each line of text file, goes until a return is found
            temp = line.split(" : ");                           //split each line into a list of Qstrings
            userMap.insert(temp.value(0), temp.value(1));       //insert each item in Qstring list into our Map of user info
            temp.value(0) = "";                                 //reset the Qstring to have nothing in
            temp.value(1) = "";
        }
        file.close();
        QMap<QString, QString>::const_iterator i = userMap.constBegin(); //using an iterator to iterate through the Map
        while (i != userMap.constEnd()) {
            qDebug() << i.key() << " : " << i.value() << endl;
            ++i;
        }
        //setting all variables to their corresponding values in the map of user info
        userName = userMap.value("userName");
        plainTextPassword = userMap.value("plainTextPassword");
        fName = userMap.value("fName");
        mName = userMap.value("mName");
        lName = userMap.value("lName");
        age = userMap.value("age");
        DOB = userMap.value("DOB");
        plainTextSSN =userMap.value("plainTextSSN");
        addr1 = userMap.value("addr1");
        addr2 = userMap.value("addr2");
        city = userMap.value("city");
        country = userMap.value("country");
        email = userMap.value("email");
        securityAnswer1 = userMap.value("securityAnswer1");
        securityAnswer2 = userMap.value("securityAnswer2");
        return true;
    }

}

void User::saveUser()
{
        qDebug() << fileName;
        QFile file(fileName);
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&file);
        QMap<QString, QString>::const_iterator i = userMap.constBegin();
        while (i != userMap.constEnd()) {
            out << i.key() << " : " << i.value() << endl;
            ++i;
        }
        file.close();

}

void User::setUserName(const QString& newUserName )
{
    userName = newUserName;
    userMap.insert("userName", userName);
}

void User::setPassword(const QString& newPassword)
{
    plainTextPassword = newPassword;
    userMap.insert("plainTextPassword", plainTextPassword);
}

void User::setFName(const QString& newFname )
{
    fName = newFname;
    userMap.insert("fName", fName);
}

void User::setMName(const QString& newMname)
{
    mName = newMname;
    userMap.insert("mName", mName);
}

void User::setLName( const QString& newLname)
{
    lName = newLname;
    userMap.insert("lName", lName);
}

void User::setCellPhone(const QString & newCell)
{
    cellPhone = newCell;
   // userMap.insert();
}

void User::setHomePhone(const QString & newHomePhone)
{
    homePhone = newHomePhone;
   // userMap.insert();
}

void User::setWorkPhone(const QString & newWorkPhone)
{
    workPhone = newWorkPhone;
    //userMap.insert();
}

void User::setAge(const QString & newAge)
{
    age = newAge;
    userMap.insert("age",age);
}

void User::setDOB(const QString & newDOB)
{
    DOB = newDOB;
    userMap.insert("DOB", DOB);
}

void User::setSSN(const QString & newSSN)
{
    plainTextSSN = newSSN;
    userMap.insert("plainTextSSN", plainTextSSN);
}

void User::setAddr1(const QString & newAddr1)
{
    addr1 = newAddr1;
    userMap.insert("addr1", addr1);
}

void User::setAddr2(const QString & newAddr2)
{
    addr2 = newAddr2;
    userMap.insert("addr2", addr2);
}

void User::setCity(const QString & newCity)
{
    city = newCity;
    userMap.insert("city", city);
}

void User::setState(const QString & newState)
{
    state = newState;
}

void User::setCountry(const QString& newCountry)
{
    country = newCountry;
    userMap.insert("country", country);

}

void User::setEmail(const QString& newEmail)
{
    email = newEmail;
    userMap.insert("email", email);
}

void User::setSecurityQuestion1( const QString& newSecurityQ)
{
    securityQuestion1 = newSecurityQ;
}

void User::setSecurityQuestion2(const QString& newSecurityQ)
{
    securityQuestion2 = newSecurityQ;
}

void User::setSecurityAnswer1(const QString& newSecurityA)
{
    securityAnswer1 = newSecurityA;
    userMap.insert("securityAnswer1",securityAnswer1);
}

void User::setSecurityAnswer2(const QString& newSecurityA)
{
    securityAnswer2 = newSecurityA;
    userMap.insert("securityAnswer2", securityAnswer2);
}

void User::setGender(const enumGender& newGender)
{
    gender = newGender;
}

double User::setUserFunds(int& newUserFunds)
{
    userFunds = newUserFunds;
}

//get methods
QString User::getUserName() const
{

    return userName;
}
QString User::getFName() const
{
    return fName;
}

QString User::getMName() const
{
    return mName;
}

QString User::getLName() const
{
    return lName;
}

QString User::getCellPhone() const
{
    return cellPhone;
}

QString User::getHomePhone() const
{
    return homePhone;
}

QString User::getWorkPhone() const
{
    return workPhone;
}

QString User::getAge() const
{
    return age;
}


QString User::getDOB() const
{
    return DOB;
}

QString User::getLastFourSSN() const
{
    return plainTextSSN;
}

QString User::getAddr1() const
{
    return addr1;
}

QString User::getAddr2() const
{
    return addr2;
}
QString User::getCity() const
{
    return city;
}

QString User::getState() const
{
    return state;
}

QString User::getCountry() const
{
    return country;
}

QString User::getEmail() const
{
    return email;
}

QString User::getSecurityQuestion1() const
{
    return securityQuestion1;
}

QString User::getSecurityAnswer1() const
{
    return securityAnswer1;
}

QString User::getSecurityQuestion2() const
{
    return securityQuestion2;
}

QString User::getSecurityAnswer2() const
{
    return securityAnswer2;
}

enumGender User::getGender() const
{
    return gender;
}

QString User::getPassword() const
{
    return plainTextPassword;
}

double User::getUserFunds() const
{
    return userFunds;
}
