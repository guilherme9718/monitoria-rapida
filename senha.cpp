#include "senha.h"
#include "ui_senha.h"

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
