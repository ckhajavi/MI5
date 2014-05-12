#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentUser = new User;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Creates new user window
void MainWindow::on_btnNewUser_clicked()
{
    newUser = new NewUserSetup(this);
    //newUser->show(); //can open multiple windows
    newUser->exec();

    //
}

//Creates forgot password window
void MainWindow::on_btnForgotPass_clicked()
{
    forgotPasswordWindow = new ForgotPasswordDialog(this);
    //forgotPasswordWindow->show();
    forgotPasswordWindow->exec();
}

//Creates Main Login page after Logging in
void MainWindow::on_btnLogIn_clicked()
{
                                        // create an User object (it's empty right now)
    currentUser->setFileName(ui->lineEditUserName->text());  //sets the path to where the user info is saved
    currentUser->loadUser();
    currentUser->setStockFile();    // loads user info from text file and populates the objects variables with values
    currentUser->loadStockList();
    QString password = currentUser->getPassword();           // create a variable password and set it equal to user's password
    //check to see if password matches
    if( !currentUser->loadUser())
    {
        QMessageBox::information(this, "Login Failed", "sorry could not find user");
        qDebug() << "sorry could not find user" <<endl;
    }
    else if(ui->lineEditPassword->text() == password)
    {

        myLoginDialog = new LoginPage(this);
        myLoginDialog->setCurrentUser(currentUser);
        myLoginDialog->exec();
        //open the next window
        qDebug() << password;
    }
    else
    {
        QMessageBox::information(this, "Login Failed", "Sorry wrong user name/ password combination");
    }

}

void MainWindow::on_btnExit_clicked()
{
    this->close();
}

void MainWindow::on_btnLogIn_pressed()
{
    on_btnLogIn_clicked();
}
