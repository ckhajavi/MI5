#include "DownloadManager.h"

DownloadManager::DownloadManager()
{
    //Creates a connection from signal in sender object to functor, and returns a handle to the connection
    connect(&manager, SIGNAL(finished(QNetworkReply*)), SLOT(downloadFinished(QNetworkReply*)));
}

void DownloadManager::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

    currentDownloads.append(reply);
}

QString DownloadManager::saveFileName(const QUrl &url)
{
/*
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "stockinfo";

    // already exists, don't overwrite
    if (QFile::exists(basename))
    {
        //removes the ".txt" from the end of the basename
        basename.chop(4);

        //Increments through to find an available file name
        int i = 1;
        while (QFile::exists(basename + QString::number(i) + ".txt"))
        {
            ++i;
        }

        //Adds on the proper number and file extension to the file
        basename += QString::number(i) + ".txt";
    }

    return basename;
*/
    return "stockInfo.txt";
}

bool DownloadManager::saveToDisk(const QString &filename, QIODevice *data)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        fprintf(stderr, "Could not open %s for writing: %s\n",
                qPrintable(filename),
                qPrintable(file.errorString()));
        return false;
    }

    file.write(data->readAll());
    file.close();

    return true;
}

//Not used, but kept in case we want to simulate multi-threading
void DownloadManager::execute()
{
    QStringList args = QCoreApplication::instance()->arguments();
    args.takeFirst();           // skip the first argument, which is the program's name
    if (args.isEmpty())
    {
        /*
        printf("Qt Download example - downloads all URLs in parallel\n"
               "Usage: download url1 [url2... urlN]\n"
               "\n"
               "Downloads the URLs passed in the command-line to the local directory\n"
               "If the target file already exists, a .0, .1, .2, etc. is appended to\n"
               "differentiate.\n");
               */
        QCoreApplication::instance()->quit();
        return;
    }

    foreach (QString arg, args) {
        QUrl url = QUrl::fromEncoded(arg.toLocal8Bit());
        doDownload(url);
    }
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error())
    {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
        fflush(stderr);
    }
    else
    {
        QString filename = saveFileName(url);
        //Does the actually downloading
        if (saveToDisk(filename, reply))
        {
            //Prints out status of the download
            fprintf(stdout, "Download of %s succeded (saved to %s)\n",
                    url.toEncoded().constData(),
                    qPrintable(filename));
            fflush(stdout);
        }
    }

    //cout << currentDownloads.empty() << endl;
    currentDownloads.removeAll(reply);
    //cout << currentDownloads.empty() << endl;
    reply->deleteLater();
}

bool DownloadManager::canProceed()
{
    return (currentDownloads.empty() == 1);
}
