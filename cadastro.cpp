#include "cadastro.h"
#include "ui_cadastro.h"
#include "registroaluno.h"
#include "registrarmonitor.h"

Cadastro::Cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cadastro)
{
    ui->setupUi(this);
    Cadastro::setWindowTitle("Cadastro");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();

}

Cadastro::~Cadastro()
{
    delete ui;
}


void Cadastro::on_aluno_clicked()
{
    close();
    new RegistroAluno();
}



void Cadastro::on_monitor_clicked()
{
    close();
    new RegistrarMonitor();
}

