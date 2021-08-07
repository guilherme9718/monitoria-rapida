#include "senha.h"
#include "ui_senha.h"
#include "interfacemonitor.h"
#include "interfacealuno.h"
#include "interfaceorientador.h"
#include "login.h"
Senha::Senha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Senha)
{
    ui->setupUi(this);
    Senha::setWindowTitle("Senha");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

Senha::~Senha()
{
    delete ui;
}

void Senha::on_login_clicked()
{
    close();
    new InterfaceOrientador(this);
}


void Senha::on_voltar_clicked()
{
    close();
    new Login(this);
}

