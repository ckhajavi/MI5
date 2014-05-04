#include "dummyfordownload.h"
#include "ui_dummyfordownload.h"

DummyForDownload::DummyForDownload(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DummyForDownload)
{
    ui->setupUi(this);
}

DummyForDownload::~DummyForDownload()
{
    delete ui;
}
