#ifndef UPDATEUSERINFO_H
#define UPDATEUSERINFO_H

#include <QDialog>
#include "user.h"
#include <QString>

namespace Ui {
class UpDateUserInfo;
}

class UpDateUserInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UpDateUserInfo(QWidget *parent = 0);
    void setCurrentUser(const QString&);
    ~UpDateUserInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UpDateUserInfo *ui;
    User *currentUser;
};

#endif // UPDATEUSERINFO_H
