#include "alunoagendarhr.h"
#include "ui_alunoagendarhr.h"
#include "interfacealuno.h"
AlunoAgendarHr::AlunoAgendarHr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlunoAgendarHr)
{
    ui->setupUi(this);
    AlunoAgendarHr::setWindowTitle("Agendamento");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

AlunoAgendarHr::~AlunoAgendarHr()
{
    delete ui;
}

void AlunoAgendarHr::on_voltar_clicked()
{
    close();
    new InterfaceAluno(this);
}

