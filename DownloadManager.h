#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QStringList>
#include <QTimer>
#include <QUrl>
#include <iostream>

#include <stdio.h>

using namespace std;

class DownloadManager: public QObject
{   
    Q_OBJECT
    QNetworkAccessManager manager;
    QList<QNetworkReply *> currentDownloads;

public:
    DownloadManager();
    void doDownload(const QUrl &url);
    QString saveFileName(const QUrl &url);
    bool saveToDisk(const QString &filename, QIODevice *data);
    void flushDownload();

    bool canProceed();

public slots:
    void execute();
    void downloadFinished(QNetworkReply *reply);
};

#endif // DOWNLOADMANAGER_H
