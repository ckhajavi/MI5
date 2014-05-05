#include "stock.h"
#include <QString>

Stock::Stock()
{
    ticker = "";
    owned = false;
    numOfShares = 0;
    currentPrice = 0;
    changeInPrice = 0;
    openPrice = 0;
    todayHigh = 0;
    todayLow = 0;
    volume = 0;
}

//Overloaded
Stock::Stock(QString newTicker)
{
    ticker = newTicker;
    owned = false;
    numOfShares = 0;
    currentPrice = 0;
    changeInPrice = 0;
    openPrice = 0;
    todayHigh = 0;
    todayLow = 0;
    volume = 0;
}

double Stock::buy(int shares, double price)
{
    owned = true;
    numOfShares = shares;
    double cost;
    currentPrice = price;
    cost = shares*price;
    //add to stock list
    return cost;
}

bool Stock::isOwned()
{
    return owned;
}

void Stock::addToFavorites()
{
    //add to stock list
}




