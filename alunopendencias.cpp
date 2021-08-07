#include "alunopendencias.h"
#include "ui_alunopendencias.h"
#include "interfacealuno.h"
AlunoPendencias::AlunoPendencias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlunoPendencias)
{
    ui->setupUi(this);
    AlunoPendencias::setWindowTitle("Pendencias");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

AlunoPendencias::~AlunoPendencias()
{
    delete ui;
}

void AlunoPendencias::on_voltar_clicked()
{
    close();
    new InterfaceAluno();
}

