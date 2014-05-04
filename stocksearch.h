#ifndef STOCKSEARCH_H
#define STOCKSEARCH_H

#include <QDialog>
#include <fstream>
#include <iostream>
#include <string>
#include "DownloadManager.h"
#include "dummyfordownload.h"

using namespace std;

namespace Ui {
class StockSearch;
}

class StockSearch : public QDialog
{
    Q_OBJECT

public:
    explicit StockSearch(QWidget *parent = 0);

    StockSearch(QUrl&);

    ~StockSearch();

private slots:
    void on_btnAddFavorites_clicked();

    void on_btnClose_clicked();

    void parseData();

    void on_btnFind_clicked();

private:
    Ui::StockSearch *ui;
    DummyForDownload *dummyWindow;

};

#endif // STOCKSEARCH_H
