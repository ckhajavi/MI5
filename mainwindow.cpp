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
    delete currentUser;
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
    currentUser->loadUser();                                 // loads user info from text file and populates the objects variables with values
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
        myLoginDialog->exec();
        myLoginDialog->setCurrentUser(currentUser);//open the next window
        qDebug() << password;
    }
    else
    {
        // change into a dialogue box when anyone gets the chance
        QMessageBox::information(this, "Login Failed", "Sorry wrong user name/ password combination");
        qDebug() << "Sorry wrong user name/ password combination" <<endl;
        qDebug() << password;
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
