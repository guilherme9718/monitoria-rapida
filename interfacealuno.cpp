#include "interfacealuno.h"
#include "ui_interfacealuno.h"
#include "login.h"
#include "alunoagendarhr.h"
#include "alunopendencias.h"
InterfaceAluno::InterfaceAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InterfaceAluno)
{
    ui->setupUi(this);
    InterfaceAluno::setWindowTitle("Aluno");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

InterfaceAluno::~InterfaceAluno()
{
    delete ui;
}

void InterfaceAluno::on_agendar_clicked()
{
    close();
    new AlunoAgendarHr();
}


void InterfaceAluno::on_voltar_clicked()
{
    close();
    new Login();
}



void InterfaceAluno::on_pendencias_clicked()
{
    close();
    new AlunoPendencias();
}

