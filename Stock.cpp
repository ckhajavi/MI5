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

double Stock::buy(int shares)
{
    owned = true;
    numOfShares = shares;
    double cost;
    //add to stock list

    QFile file("stockInfo.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);         //opening file
    QTextStream in(&file);                                    //starting a stream reading from the file we set in setFileName function
    QString line;
    QStringList temp;
    while(!in.atEnd())
    {
        line = in.readLine();                               //reading each line of text file, goes until a return is found
        temp = line.split(" ");
    }
    for(int i = 0; i < temp.size(); ++i)
    {
        qDebug() << temp.value(i);
    }

    if (ticker == "")
    {
        ticker = temp.value(0);
    }
    currentPrice = temp.value(1).toDouble();
    date = temp.value(2);
    time = temp.value(3);
    changeInPrice = temp.value(4).toDouble();
    openPrice = temp.value(5).toDouble();
    todayHigh = temp.value(6).toDouble();
    todayLow = temp.value(7).toDouble();
    volume = temp.value(8).toDouble();

    cost = currentPrice*shares;
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




