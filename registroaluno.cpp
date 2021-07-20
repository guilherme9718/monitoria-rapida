#include "registroaluno.h"
#include "ui_registroaluno.h"
#include "senha.h"

RegistroAluno::RegistroAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistroAluno)
{
    ui->setupUi(this);
}

RegistroAluno::~RegistroAluno()
{
    delete ui;
}

void RegistroAluno::on_cadastrar_clicked()
{
    close();
    Senha* senha = new Senha(this);
    senha->show();
}

