#include "registrar.h"
#include "ui_registrar.h"

Registrar::Registrar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registrar)
{
    ui->setupUi(this);
}

Registrar::~Registrar()
{
    delete ui;
}
