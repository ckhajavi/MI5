#ifndef STOCKLIST_H
#define STOCKLIST_H
#include <QMap>
#include "stock.h"
#include "loginpage.h"
#include <QString>
#include <QTableWidget>



class StockList
{
public:
    friend class User;

    StockList();
    QMap<QString, Stock> *stockMap;
    ~StockList();
    bool setDirectory();
    bool saveStockList();
    bool loadStockList();


    void addStock(const Stock&);
    void deleteStock();
    //These are like update functions, updates their member variables
    void setTotalSpent(); //calculates how much was originally spent on buying price
    void setStockTotal(); //calculates how much total money is tied in stocks
    void setTotalGains();       //calculates how much has been lost or gained in stock investments
    void setTodaysGains();      //calculates the day's gains from opening price to current price.
    //write print function that writes to

    //get functions
    double getTotalSpent();
    double getStockTotal();
    double getTodaysGains();
    double getTotalGains();


private:
    double totalSpent; //total spent on stocks with bought for price;
    double stockTotal;
    double todaysGains;
    double totalGains;
    QString fileName;
};

#endif // STOCKLIST_H
