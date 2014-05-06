#include "stock.h"
#include "stockList.h"


Stock::Stock()
{
    ticker = "";
    owned = false;
    numOfShares = 0;
    latestPrice = 0;
    changeInPrice = 0;
    openPrice = 0;
    todaysHigh = 0;
    todaysLow = 0;
    volume = 0;
    cost = 0;
}

//Overloaded
Stock::Stock(QString newTicker)
{
    ticker = newTicker;
    owned = false;
    numOfShares = 0;
    latestPrice = 0;
    changeInPrice = 0;
    openPrice = 0;
    todaysHigh = 0;
    todaysLow = 0;
    volume = 0;
    cost = 0;
}

Stock& Stock::operator=(const Stock& rightSide )
{
    if (this != &rightSide)
    {
        ticker = rightSide.ticker;
        owned = rightSide.owned;
        numOfShares = rightSide.numOfShares;
        latestPrice = rightSide.latestPrice;
        changeInPrice = rightSide.changeInPrice;
        openPrice = rightSide.openPrice;
        todaysHigh = rightSide.todaysHigh;
        todaysLow = rightSide.todaysLow;
        volume = rightSide.volume;
        cost = rightSide.cost;
    }
    return *this;
}

Stock operator+(const Stock& leftSide, const Stock& rightSide)
{
    Stock temp;
    temp.ticker = rightSide.ticker;
    temp.owned = true;
    temp.numOfShares = rightSide.numOfShares + leftSide.numOfShares;
    temp.changeInPrice = rightSide.changeInPrice;
    temp.todaysHigh = rightSide.todaysHigh;
    temp.todaysLow = rightSide.todaysLow;
    temp.volume = rightSide.volume;
    temp.cost = rightSide.cost + leftSide.cost;

    return temp;
}

void Stock::buy(int shares)
{
    owned = true;
    numOfShares = shares;
    //add to stock list

    QFile file("stockInfo.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);         //opening file
    QTextStream in(&file);                                    //starting a stream reading from the file we set in setFileName function
    QString line;
    QStringList temp;
    while(!in.atEnd())
    {
        line = in.readLine();
        line = line.remove(QRegExp("\""));//reading each line of text file, goes until a return is found
        temp = line.split(",");

    }
    for(int i = 0; i < temp.size(); ++i)
    {
        qDebug() << temp.value(i) << endl;
    }
    qDebug() <<temp.size() << endl;
    qDebug() << temp.value(0) << " " << temp.value(7) << endl;

    if (ticker == "")
    {
        ticker = temp.value(0);
    }
    latestPrice = temp.value(1).toDouble();
    date = temp.value(2);
    time = temp.value(3);
    changeInPrice = temp.value(4).toDouble();
    openPrice = temp.value(5).toDouble();
    todaysHigh = temp.value(6).toDouble();
    todaysLow = temp.value(7).toDouble();
    volume = temp.value(8).toDouble();

    cost = latestPrice*shares;

}

bool Stock::isOwned() const
{
    return owned;
}

double Stock::getCost()const
{
    return cost;
}

double Stock::getLatestPrice()const
{
    return latestPrice;
}

QString Stock::getTicker() const
{
    return ticker;
}





