#ifndef DUMMYFORDOWNLOAD_H
#define DUMMYFORDOWNLOAD_H

#include <QDialog>

namespace Ui {
class DummyForDownload;
}

class DummyForDownload : public QDialog
{
    Q_OBJECT

public:
    explicit DummyForDownload(QWidget *parent = 0);
    ~DummyForDownload();

    void ProgressBar();

private:
    Ui::DummyForDownload *ui;
};

#endif // DUMMYFORDOWNLOAD_H
