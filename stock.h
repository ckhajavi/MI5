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
    double buy(int);
    double sell(int);
    bool isOwned();
    void addToFavorites();

private:
    int numOfShares;
    bool owned;
    QString ticker;
    QString date;
    QString time;
    double currentPrice;
    double changeInPrice;
    double openPrice;
    double todayHigh;
    double todayLow;
    double volume;



};

#endif // STOCK_H
