#include "dummyfordownload.h"
#include "ui_dummyfordownload.h"

DummyForDownload::DummyForDownload(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DummyForDownload)
{
    ui->setupUi(this);

    ProgressBar();
}

void DummyForDownload::ProgressBar()
{
    int percentValue = 0;
    for (int i = 0; i < 10100; i++)
    {
        if (i % 100 == 0)
        {
             ui->progressBar->setValue(percentValue);
             percentValue++;
        }
    }
}

DummyForDownload::~DummyForDownload()
{
    delete ui;
}
