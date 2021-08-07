#include "interfaceorientador.h"
#include "ui_interfaceorientador.h"
#include "login.h"
#include "orientadorpendencias.h"
InterfaceOrientador::InterfaceOrientador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InterfaceOrientador)
{
    ui->setupUi(this);
    InterfaceOrientador::setWindowTitle("Orientador");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

InterfaceOrientador::~InterfaceOrientador()
{
    delete ui;
}

void InterfaceOrientador::on_voltar_clicked()
{
    close();
    new Login(this);
}


void InterfaceOrientador::on_pendencias_clicked()
{
    close();
    new OrientadorPendencias(this);
}

