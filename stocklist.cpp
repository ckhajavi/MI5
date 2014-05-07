#include "stocklist.h"

StockList::StockList()
{
    stockMap = new QMap<QString, Stock>;
    totalSpent = 0;
    stockTotalValue= 0;
}

bool StockList::saveStockList()
{

}

bool StockList::loadStockList()
{

}

void StockList::addStock(const Stock& newStock)
{
    if (stockMap->contains(newStock.getTicker()) && newStock.isOwned())
    {
        Stock temp;
        temp = newStock + stockMap->value(newStock.getTicker());
        stockMap->insert(temp.getTicker(), temp);
    }
    else
    {
        stockMap->insert(newStock.getTicker(), newStock);
    }
    QMap<QString, Stock>::const_iterator i = stockMap->constBegin(); //using an iterator to iterate through the Map
    while (i != stockMap->constEnd()) {
        qDebug() << i.key() << " : " << i.value().getCost() << endl;
        ++i;
    }
}

double StockList::totalCost()
{
    double totalCost = 0;  //temp value to hold total spent
    QMap<QString, Stock>::const_iterator i = stockMap->constBegin(); //using an iterator to iterate through the Map
    while (i != stockMap->constEnd()) {
        totalCost = totalCost + i.value().getCost();
        ++i;
    }
    totalSpent = totalCost;  //change member variable
    return totalCost;
}

double StockList::stockTotal()
{
    double stockTotal = 0;
    QMap<QString, Stock>::const_iterator i = stockMap->constBegin(); //using an iterator to iterate through the Map
    while (i != stockMap->constEnd()) {
        stockTotal = stockTotal + i.value().getLatestPrice();
        ++i;
    }
    stockTotalValue = stockTotal;
    return stockTotal;
}

double StockList::totalGain()
{
    /*double totalGain = 0;
    QMap<QString, Stock>::const_iterator i = stockMap->constBegin(); //using an iterator to iterate through the Map
    while (i != stockMap->constEnd()) {
        totalGain = totalGain + ((i.value().getLatestPrice() - i.value().getCost())*i.value().getShares());
    }
    return totalGain;*/
    /*double gains = 0;
    double stockTotal = stockTotal();
    double totalCost = totalCost();
    gains = stockTotal - totalCost;
    return gains;*/
    return (stockTotal() - totalCost());

}

double StockList::todaysGains()
{
    double gains;
    QMap<QString, Stock>::const_iterator i = stockMap->constBegin(); //using an iterator to iterate through the Map
    while (i != stockMap->constEnd()) {
        gains = gains + i.value().getLatestPrice() - i.value().getOpenPrice();
        ++i;
    }
    return gains;
}

StockList::~StockList(){
    delete stockMap;
}
