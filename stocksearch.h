#ifndef STOCKSEARCH_H
#define STOCKSEARCH_H

#include <QDialog>
#include <fstream>
#include <iostream>
#include <string>
#include "DownloadManager.h"
#include "dummyfordownload.h"
class User;

using namespace std;

namespace Ui {
class StockSearch;
}

class StockSearch : public QDialog
{
    Q_OBJECT

public:
    explicit StockSearch(QWidget *parent = 0);
    void setCurrentUser(User*);

    StockSearch(QUrl&);
    void setCurrentUserSearch(User* theUser);
     Ui::StockSearch *ui;

    ~StockSearch();
signals:
    void valueChanged(int);

private slots:
    void on_btnAddFavorites_clicked();

    void on_btnClose_clicked();

    void parseData();

    void on_btnFind_clicked();

private:

    DummyForDownload *dummyWindow;
    User *currentUser;

};

#endif // STOCKSEARCH_H
