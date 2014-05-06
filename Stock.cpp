#include "stock.h"
#include <QString>

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

bool Stock::isOwned()
{
    return owned;
}






