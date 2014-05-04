#include "mainwindow.h"
//#include "DownloadManager.h"
#include <QApplication>
#include <QtSql>
#include <QtDebug>

int main(int argc, char *argv[])
{
    //QCoreApplication app(argc, argv);

    //DownloadManager manager;
    //QTimer::singleShot(0, &manager, SLOT(execute()));

    //app.exec();




    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
