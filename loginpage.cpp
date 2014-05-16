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
void LoginPage::setCurrentUser(const QString& email)
{
    currentUser->setEmail(email);
    currentUser->setFileName();
    currentUser->setStockFile();
    currentUser->loadUser();
    currentUser->loadStockList();
    updateAccountSummary();
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
    currentUser->saveUser();
    QMessageBox::information(this, "Logging Out", "You have successfully logged out.");
    this->close();
}

LoginPage::~LoginPage()
{
    delete currentUser;
    currentUser = NULL;
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
    stockSearchWindow->setCurrentUserSearch(currentUser); //pass the user pointer on to the next window

//the following connection connects the addto favorites button in the StockSearch class to the refresh button in loginClass
   QObject::connect(stockSearchWindow, SIGNAL(valueChanged(int)), this, SLOT(on_btnRefresh_clicked()));//when added to favorites button is pressed and signal is released
                                                                                                       //an updated version of the list will appear
                                                                                                       //on the loginPage
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
    double funds = currentUser->getUserFunds();
    currentUser->setUserFunds(funds - currentStock.getCost());
    updateAccountSummary();
    currentUser->saveStockList();     //save the stocks
    currentUser->saveUser();  //saves the user info


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
    Stock stockToSell(ui->lineEditSearchSymbol->text()); //creates stock object
    stockToSell.sell(ui->lineEditQuantity->text().toInt()); //sells the stock
    currentUser->userStockList->sellStock(stockToSell); //update map of stocks
    int numOfRows = ui->tableWidget->rowCount();
    for (int i = numOfRows; i > 0; i--)
    {
        ui->tableWidget->removeRow(i - 1);
    }
    addToTable(); //updates ui table
    double funds = currentUser->getUserFunds();
    currentUser->setUserFunds(funds + stockToSell.getCost());
    currentUser->saveStockList();     //save the stocks
    updateAccountSummary();

    currentUser->saveUser();   //saves the user info




    //stockTosell = ui->tableWidget->row()
    //int stockToSell = ui->tableWidget->row((ui->lineEditSearchSymbol->text));
}

void LoginPage::updateAccountSummary()
{
    currentUser->userStockList->setTotalGains();    //update total gains
    QString totalGains = QString::number(currentUser->userStockList->getTotalGains());
    if(currentUser->userStockList->getTotalGains() < 0)
    {
        ui->lineEdit_todaysLosses->setText(totalGains);
    }
    else
    {
        ui->lineEdit_TodaysGains->setText(totalGains);
    }
    currentUser->userStockList->setStockTotal();            //update the total value of stock investments
    QString stockTotalString = QString::number(currentUser->userStockList->getStockTotal()); //convert to string
    ui->lineEdit_TotalInvestments->setText(stockTotalString);       //write it to the Account summary ui
    QString userCash = QString::number(currentUser->getUserFunds());  //store available funds as string
    ui->lineEdit_TotalCash->setText(userCash);                      //set ui as the string declared above
    double totalNum = currentUser->getUserFunds() + currentUser->userStockList->getStockTotal();
    QString totalString = QString::number(totalNum);
    ui->lineEdit_TotalValue->setText(totalString);
}
