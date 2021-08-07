#include "orientadorpendencias.h"
#include "ui_orientadorpendencias.h"
#include "interfaceorientador.h"

OrientadorPendencias::OrientadorPendencias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrientadorPendencias)
{
    ui->setupUi(this);
    OrientadorPendencias::setWindowTitle("Orientador");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

OrientadorPendencias::~OrientadorPendencias()
{
    delete ui;
}


void OrientadorPendencias::on_voltar_clicked()
{
    close();
    new InterfaceOrientador(this);
}

