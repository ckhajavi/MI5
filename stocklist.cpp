#include "stocklist.h"

StockList::StockList()
{
    stockMap = new QMap<QString, Stock>;
    totalSpent = 0;
    stockTotalValue= 0;
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

double StockList::calculateTotalSpent()
{
    double totalCost = 0;  //temp value to hold total spent
    QMap<QString, Stock>::const_iterator i = stockMap->constBegin(); //using an iterator to iterate through the Map
    while (i != stockMap->constEnd()) {
        totalCost = totalCost + i.value().getCost();
    }
    totalSpent = totalCost;  //change member variable
    return totalCost;
}

double StockList::calculateStockTotalValue()
{
    double totalWorth = 0;
    QMap<QString, Stock>::const_iterator i = stockMap->constBegin(); //using an iterator to iterate through the Map
    while (i != stockMap->constEnd()) {
        totalWorth = totalWorth + i.value().getLatestPrice();
    }
    stockTotalValue = totalWorth;
    return totalWorth;
}
StockList::~StockList(){
    delete stockMap;
}
