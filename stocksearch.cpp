#include "stocksearch.h"
#include "ui_stocksearch.h"
#include "user.h"

using namespace std;

StockSearch::StockSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StockSearch)
{
    ui->setupUi(this);
    //this might have to be a deep copy
    currentUser = new User;
}

StockSearch::~StockSearch()
{
    delete ui;
}

void StockSearch::on_btnAddFavorites_clicked()
{

}

void StockSearch::on_btnClose_clicked()
{
    this->close();
}

//Parses YahooFinance Data.
void StockSearch::parseData()
{
    ifstream fileReader; //("stockInfo.txt");
    fileReader.open("stockInfo.txt");

    string input;
    string charToReplace;

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

    //Writing data to StockSearchWindow.
    string tempVar;

    tempVar = input.substr(0, input.find(" ")); //Getting stock symbol.
    cout << tempVar << endl;

    QString myQString = QString::fromStdString(tempVar); //Writing stock symbol to window.
    ui->lblCompanyName->setText(myQString);

    input.erase(0, input.find(" ") + 1); //Deleting stock symbol name from string.
    cout << input << endl;

    //**************************************************************************************
    tempVar = input.substr(0, input.find(" ")); //Getting price per share.
    cout << tempVar << endl;

    myQString = QString::fromStdString(tempVar); //Writing price per share to window.
    ui->txtPricePerShare->setText(myQString);

    input.erase(0, input.find(" ") + 1); //Deleting price per share from string.
    cout << input << endl;

    //***************************************************************************************
    tempVar = input.substr(0, input.find(" ")); //Getting date.
    cout << tempVar << endl;

    myQString = QString::fromStdString(tempVar); //Writing date to window.
    ui->txtDate->setText(myQString);

    input.erase(0, input.find(" ") + 1); //Deleting date from string.
    cout << input << endl;

    //***************************************************************************************
    tempVar = input.substr(0, input.find(" ")); //Getting time.
    cout << tempVar << endl;

    myQString = QString::fromStdString(tempVar); //Writing time to window.
    ui->txtTime->setText(myQString);

    input.erase(0, input.find(" ") + 1); //Deleting time from string.
    cout << input << endl;

    //****************************************************************************************
    tempVar = input.substr(0, input.find(" ")); //Getting change.
    cout << tempVar << endl;

    myQString = QString::fromStdString(tempVar); //Writing change to window.
    ui->txtChange->setText(myQString);

    input.erase(0, input.find(" ") + 1); //Deleting change from string.
    cout << input << endl;

    //****************************************************************************************
    tempVar = input.substr(0, input.find(" ")); //Getting openning price.
    cout << tempVar << endl;

    myQString = QString::fromStdString(tempVar); //Writing opening price to window.
    ui->txtOpeningPrice->setText(myQString);

    input.erase(0, input.find(" ") + 1); //Deleting opening price from string.
    cout << input << endl;

    //****************************************************************************************
    tempVar = input.substr(0, input.find(" ")); //Getting today's high.
    cout << tempVar << endl;

    myQString = QString::fromStdString(tempVar); //Writing today's high to window.
    ui->txtTodaysHigh->setText(myQString);

    input.erase(0, input.find(" ") + 1); //Deleting today's high from string.
    cout << input << endl;

    //****************************************************************************************
    tempVar = input.substr(0, input.find(" ")); //Getting today's low.
    cout << tempVar << endl;

    myQString = QString::fromStdString(tempVar); //Writing today's low to window.
    ui->txtTodaysLow->setText(myQString);

    input.erase(0, input.find(" ") + 1); //Deleting today's low from string.
    cout << input << endl;

    //****************************************************************************************
    tempVar = input.substr(0, input.find(" ")); //Getting volume (todays total trades).
    cout << tempVar << endl;

    myQString = QString::fromStdString(tempVar); //Writing volume to window.
    ui->txtVolume->setText(myQString);

    input.erase(0, input.find(" ") + 1); //Deleting volume from string.
    cout << input << endl;
}

//Downloads all the data from YahooFinance.
void StockSearch::on_btnFind_clicked()
{
    //QTimer tT;
    //QEventLoop q;


    QString input = ui->lineEditSearch->text();
    QString baseURL = "http://download.finance.yahoo.com/d/quotes.txt?s=";
    QString urlFormatting = "&f=sl1d1t1c1ohgv&e=.txt";

    QUrl thisURL = (QUrl) (baseURL + input + urlFormatting);
    DownloadManager manager;
    manager.doDownload(thisURL);

    //tT.start(3000);
    //q.processEvents();
    //q.exec();
    //q.wakeUp();

    //q.exit(0);

    //This dummy window has to open in order to download Data from YahooFinance...Click EXIT once immediately.
    dummyWindow = new DummyForDownload(this);
    dummyWindow->exec();
    dummyWindow->close();

    parseData();
}
