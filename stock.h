#ifndef STOCK_H
#define STOCK_H


#include<QString>
//Think about this user Finance friend class of user
class Stock
{
public:
    Stock();
    Stock(QString);
    bool buy( int);
    bool sell(int);
    bool isOwned();


private:
    int numOfShares;
    QString ticker;


};

#endif // STOCK_H
