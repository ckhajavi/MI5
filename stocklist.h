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
    void addStock(const Stock&);
    void deleteStock();
    void buyStock();



private:
    QMap<QString, Stock> *stockMap;
    double totalSpent;

};

#endif // STOCKLIST_H
