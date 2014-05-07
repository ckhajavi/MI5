#ifndef STOCKLIST_H
#define STOCKLIST_H
#include <QMap>
#include"stock.h"
#include <QString>


class StockList
{
public:
    friend class User;

    StockList();
    ~StockList();
    void addStock(const Stock&);
    void deleteStock();
    double totalCost(); //calculates how much was originally spent on buying price
    double stockTotal(); //calculates how much total money is tied in stocks
    double totalGain();       //calculates how much has been lost or gained in stock investments
    double todaysGains();      //calculates the day's gains from opening price to current price.
    bool saveStockList();
    bool loadStockList();





private:
    QMap<QString, Stock> *stockMap;
    double totalSpent; //total spent on stocks with bought for price;
    double stockTotalValue;
};

#endif // STOCKLIST_H
