#include "cadastro.h"
#include "ui_cadastro.h"
#include "registroaluno.h"
#include "registromonitor.h"

Cadastro::Cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cadastro)
{
    ui->setupUi(this);

}

Cadastro::~Cadastro()
{
    delete ui;
}


void Cadastro::on_aluno_clicked()
{
    close();
    RegistroAluno* aluno = new RegistroAluno(this);
    aluno->show();
}



void Cadastro::on_monitor_clicked()
{
    close();
    RegistroMonitor* monitor = new RegistroMonitor(this);
    monitor->show();
}

