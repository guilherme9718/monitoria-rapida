#include "interfacemonitor.h"
#include "ui_interfacemonitor.h"

Interfacemonitor::Interfacemonitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interfacemonitor)
{
    ui->setupUi(this);
}

Interfacemonitor::~Interfacemonitor()
{
    delete ui;
}
