#ifndef STOCK_H
#define STOCK_H


#include<QString>
#include "loginpage.h"

//Think about this user Finance friend class of user
class Stock
{
public:
    Stock();
    Stock(QString);
    double buy(int, double);
    double sell(int);
    bool isOwned();
    void addToFavorites();

private:
    int numOfShares;
    QString ticker;
    bool owned;
    double currentPrice;
    double changeInPrice;
    double openPrice;
    double todayHigh;
    double todayLow;
    double volume;
};

#endif // STOCK_H
