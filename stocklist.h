#ifndef STOCKLIST_H
#define STOCKLIST_H
#include <QMap>
#include "stock.h"
#include "loginpage.h"
#include <QString>
#include <QTableWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>



class StockList
{
public:
    friend class User;

    StockList();
    QMap<QString, Stock> *stockMap; //stock objects held in a map
    ~StockList();

    void addStock(const Stock&);//called when user buys a stock.
    void deleteStock(const Stock&);//deletes a stock from the userMap
    bool sellStock(Stock&); //updates the list when a stock is sold.  Checks to see if stock is owned and if the number of shares user owns
    //                        is more than the number of shares user is trying to sell. parameter is the stock user wants to sell

    //These are like update functions, updates their member variables
    void setTotalSpent(); //calculates how much was originally spent on buying price, sets totalSpent
    void setStockTotal(); //calculates how much total money is tied in stocks, sets stockTotal
    void setTotalGains();       //calculates how much has been lost or gained in stock investments, sets totalGains
    void setTodaysGains();      //calculates the day's gains from opening price to current price, sets todaysGains
    //write print function that writes to

    //get functions
    double getTotalSpent();
    double getStockTotal();
    double getTodaysGains();
    double getTotalGains();


private:
    double totalSpent; //total spent on stocks at time of purchase
    double stockTotal; //total value of investments
    double todaysGains; //how much was gained today, = opening price - latest price of all the stocks
    double totalGains; //calculates how much was gained/lost by investments = stockTotal - totalSpent
};

#endif // STOCKLIST_H
