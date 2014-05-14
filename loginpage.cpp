#include "loginpage.h"
#include "user.h"

using namespace std;

LoginPage::LoginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    currentUser = new User;
}
void LoginPage::setCurrentUser(User* theUser)
{
    currentUser->setEmail(theUser->getEmail());
    currentUser = theUser;  //set adresses equal to each other
    currentUser->userStockList->setTodaysGains();    //set todays gains
    QString todaysGains = QString::number(currentUser->userStockList->getTodaysGains());
    if(currentUser->userStockList->getTodaysGains() < 0)
    {
        ui->lineEdit_todaysLosses->setText(todaysGains);
    }
    else
    {
        ui->lineEdit_TodaysGains->setText(todaysGains);
    }
    currentUser->userStockList->setStockTotal();            //set the total value of stock investments
    QString stockTotalString = QString::number(currentUser->userStockList->getStockTotal()); //convert to string
    ui->lineEdit_TotalInvestments->setText(stockTotalString);       //write it to the Account summary ui
    QString userCash = QString::number(currentUser->getUserFunds());
    ui->lineEdit_TotalCash->setText(userCash);

}


void LoginPage::addToTable()
{
    int rowNumber = 0;
    QMap<QString, Stock>::const_iterator i = currentUser->userStockList->stockMap->constBegin(); //using an iterator to iterate through the Map
    while (i != currentUser->userStockList->stockMap->constEnd())
    {
        ui->tableWidget->insertRow(rowNumber);
        ui->tableWidget->setItem(rowNumber, 0, new QTableWidgetItem(i.value().getTicker()));
        ui->tableWidget->setItem(rowNumber, 1, new QTableWidgetItem(QString::number(i.value().getShares())));
        ui->tableWidget->setItem(rowNumber, 2, new QTableWidgetItem(QString::number(i.value().getLatestPrice())));
        ui->tableWidget->setItem(rowNumber, 3, new QTableWidgetItem(i.value().getDate()));
        ui->tableWidget->setItem(rowNumber, 4, new QTableWidgetItem(i.value().getTime()));
        ui->tableWidget->setItem(rowNumber, 5, new QTableWidgetItem(QString::number(i.value().getChangeInPrice())));
        ui->tableWidget->setItem(rowNumber, 6, new QTableWidgetItem(QString::number(i.value().getOpenPrice())));
        ui->tableWidget->setItem(rowNumber, 7, new QTableWidgetItem(QString::number(i.value().getTodaysHigh())));
        ui->tableWidget->setItem(rowNumber, 8, new QTableWidgetItem(QString::number(i.value().getTodaysLow())));
        ui->tableWidget->setItem(rowNumber, 9, new QTableWidgetItem(QString::number(i.value().getVolume())));
        i++;
        rowNumber++;
    }
}

void LoginPage::logOut()
{
    currentUser->saveStockList();
    QMessageBox::information(this, "Logging Out", "You have successfully logged out.");
    this->close();
}

LoginPage::~LoginPage()
{
    delete currentUser;
    delete ui;
}

void LoginPage::on_btnLogOut1_clicked()
{
    logOut();
}

void LoginPage::on_btnLogOut2_clicked()
{
    logOut();
}

void LoginPage::on_btnSearch_clicked()
{
    stockSearchWindow = new StockSearch(this);
    stockSearchWindow->setCurrentUserSearch(currentUser);

   QObject::connect(stockSearchWindow, SIGNAL(valueChanged(int)), this, SLOT(addToTable()));//when add to favorites button is pressed
                                                                                                       //an updated version of the list will appear
                                                                                                       //on the previous window
    //forgotPasswordWindow->show();
     stockSearchWindow->exec();

}

void LoginPage::on_btnLogOut3_clicked()
{
    logOut();
}

void LoginPage::on_btnLogOut4_clicked()
{
    logOut();
}

void LoginPage::on_btnCalculate_clicked()
{
    QString stockSymbol = ui->lineEditSearchSymbol->text();
    QString baseURL = "http://download.finance.yahoo.com/d/quotes.txt?s=";
    QString urlFormatting = "&f=sl1d1t1c1ohgv&e=.txt";

    QUrl thisURL = (QUrl) (baseURL + stockSymbol + urlFormatting);
    DownloadManager manager;
    manager.doDownload(thisURL);

    //This dummy window has to open in order to download Data from YahooFinance...Click EXIT once immediately.
    dummyWindow = new DummyForDownload(this);
    dummyWindow->exec();
    dummyWindow->close();

    //**************************************************************************

    ifstream fileReader; //("stockInfo.txt");
    fileReader.open("stockInfo.txt");

    string input;
    string charToReplace;
    string tempVar;
    QString quantityOfShares;
    double purchasePrice;

    quantityOfShares = ui->lineEditQuantity->text();
    qDebug() << quantityOfShares; // temp output
    cout << quantityOfShares.toDouble() << endl; //temp output

    getline(fileReader, input);
    cout << input << endl;
    fileReader.close();

    //Removes all double quotes from string we pulled from YahooFinance
    charToReplace = "\"";
    for (int i = 0; i < 6; i++)
    {
        input.replace(input.find(charToReplace), charToReplace.length(), "");
    }

    //Replaces all commas' with spaces.
    charToReplace = ",";
    for (int i = 0; i < 8; i++)
    {
        input.replace(input.find(charToReplace), charToReplace.length(), " ");
    }
    cout << input << endl;

    input.erase(0, input.find(" ") + 1); //Deleting stock symbol name from string.
    cout << input << endl;

    tempVar = input.substr(0, input.find(" ")); //Getting price per share.
    cout << tempVar << endl;

    cout << atof(tempVar.c_str()) << endl;

    purchasePrice = (atof(tempVar.c_str()) * quantityOfShares.toDouble());
    cout << purchasePrice;

    QString myQString = QString::number(purchasePrice); //Writing stock symbol to window.
    ui->lineEditCalculatePurchase->setText(myQString);
}

void LoginPage::on_btnReset_clicked()
{
    ui->lineEditSearchSymbol->clear();
    ui->lineEditQuantity->clear();
    ui->lineEditCalculatePurchase->clear();
}

void LoginPage::on_btnBuyShares_clicked()
{
    Stock currentStock(ui->lineEditSearchSymbol->text());
    currentStock.buy(ui->lineEditQuantity->text().toInt());
    currentUser->userStockList->addStock(currentStock);

    int numOfRows = ui->tableWidget->rowCount();
    for (int i = numOfRows; i > 0; i--)
    {
        ui->tableWidget->removeRow(i - 1);
    }
    addToTable(); //adds stock to ui table
    currentUser->saveStockList();     //save the stocks
    QString stockTotalString = QString::number(currentUser->userStockList->getStockTotal());//updates the total value of investments
    ui->lineEdit_TotalInvestments->setText(stockTotalString);
    currentUser->setUserFunds(currentUser->getUserFunds() - currentStock.getCost()); //update the available cash for user.
     QString cash = QString::number(currentUser->getUserFunds());
    ui->lineEdit_TotalCash->setText(cash);


}

void LoginPage::on_btnRefresh_clicked()
{
    int numOfRows = ui->tableWidget->rowCount();
    for (int i = numOfRows; i > 0; i--)
    {
        ui->tableWidget->removeRow(i - 1);
    }
    addToTable();
    qDebug() << "got here"<<endl;
}

void LoginPage::on_btnRemoveStock_clicked()
{
    int rowToRemove = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(rowToRemove);
}

void LoginPage::on_btnSellShares_clicked()
{
    Stock stockToSell(ui->lineEditSearchSymbol->text());
    stockToSell.sell(ui->lineEditQuantity->text().toInt());
    currentUser->userStockList->sellStock(stockToSell); //update map of stocks
    int numOfRows = ui->tableWidget->rowCount();
    for (int i = numOfRows; i > 0; i--)
    {
        ui->tableWidget->removeRow(i - 1);
    }
    addToTable(); //updates ui table
    currentUser->saveStockList();     //save the stocks
    QString stockTotalString = QString::number(currentUser->userStockList->getStockTotal());//updates the total value of investments
    ui->lineEdit_TotalInvestments->setText(stockTotalString);
    currentUser->setUserFunds(currentUser->getUserFunds() + stockToSell.getSoldFor()*stockToSell.getShares());
    QString cash = QString::number(currentUser->getUserFunds());
    ui->lineEdit_TotalCash->setText(cash);




    //stockTosell = ui->tableWidget->row()
    //int stockToSell = ui->tableWidget->row((ui->lineEditSearchSymbol->text));
}
