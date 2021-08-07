#include "horariosmonitor.h"
#include "ui_horariosmonitor.h"

Horariosmonitor::Horariosmonitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Horariosmonitor)
{
    ui->setupUi(this);
}

Horariosmonitor::~Horariosmonitor()
{
    delete ui;
}
