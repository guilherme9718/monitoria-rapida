#include "Senha.h"
#include "ui_Senha.h"

Senha::Senha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Senha)
{
    ui->setupUi(this);
}

Senha::~Senha()
{
    delete ui;
}
