#include "loginpage.h"
#include <dummyfordownload.h>
#include <QDebug>
using namespace std;

LoginPage::LoginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

void LoginPage::logOut()
{
    QMessageBox::information(this, "Logging Out", "You have successfully logged out.");
    this->close();
}

LoginPage::~LoginPage()
{
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
    //QTimer tT;
    //QEventLoop q;


    QString stockSymbol = ui->lineEditSearchSymbol->text();
    QString baseURL = "http://download.finance.yahoo.com/d/quotes.txt?s=";
    QString urlFormatting = "&f=sl1d1t1c1ohgv&e=.txt";

    QUrl thisURL = (QUrl) (baseURL + stockSymbol + urlFormatting);
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

    //**************************************************************************

    ifstream fileReader; //("stockInfo.txt");
    fileReader.open("stockInfo.txt");

    string input;
    string charToReplace;
    string tempVar;
    QString quantityOfShares;

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

   // cout << (tempVar * quantityOfShares.toDouble());
}
