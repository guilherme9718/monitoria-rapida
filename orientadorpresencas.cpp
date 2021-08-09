#include "orientadorpresencas.h"
#include "ui_orientadorpresencas.h"
#include "interfaceorientador.h"
OrientadorPresencas::OrientadorPresencas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrientadorPresencas)
{
    ui->setupUi(this);
    OrientadorPresencas::setWindowTitle("Presencas");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

OrientadorPresencas::~OrientadorPresencas()
{
    delete ui;
}

void OrientadorPresencas::on_voltar_clicked()
{
    close();
    new InterfaceOrientador();
}

