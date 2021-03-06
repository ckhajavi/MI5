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
    void buy(int);
    double sell(int);

    //setter functions
    void setAsOwned(bool);
    void setTicker( const QString&);
    void setNumOfShares(int);
    void setDate(const QString&);
    void setTime(const QString&);
    void setLatestPrice(double);
    void setChangeInPrice(double);
    void setOpenPrice(double);
    void setTodaysHigh(double);
    void setTodaysLow(double);
    void setVolume(double);

    //get functions
    bool isOwned();
    QString getTicker() const;
    int getShares() const;
    QString getDate() const;
    QString getTime() const;
    double getLatestPrice() const;
    double getChangeInPrice() const;
    double getOpenPrice() const;
    double getTodaysHigh() const;
    double getTodaysLow() const;
    double getVolume()const;

private:
    int numOfShares;
    bool owned;
    QString ticker;
    QString date;
    QString time;
    double latestPrice;
    double changeInPrice;
    double openPrice;
    double todaysHigh;
    double todaysLow;
    double volume;

    double cost;



};

#endif // STOCK_H
