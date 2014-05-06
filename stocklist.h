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
    double calculateTotalSpent();//calculates how much was originally spent on buying price
    double calculateStockTotalValue();





private:
    QMap<QString, Stock> *stockMap;
    double totalSpent; //total spent on stocks with bought for price;
    double stockTotalValue;
};

#endif // STOCKLIST_H
