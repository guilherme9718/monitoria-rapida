#include "registroaluno.h"
#include "ui_registroaluno.h"
#include "senha.h"

RegistroAluno::RegistroAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistroAluno)
{
    ui->setupUi(this);
    RegistroAluno::setWindowTitle("Aluno");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

RegistroAluno::~RegistroAluno()
{
    delete ui;
}

void RegistroAluno::on_cadastrar_clicked()
{
    QString new_ra, new_nome, new_senha;
    new_ra = ui->ra->text();
    new_nome = ui->nome->text();
    new_senha = ui->senha->text();

    BancoDeDados::MySQLHandler* handler = BancoDeDados::MySQLHandler::getInstance();
    handler->adicionarAluno(new_ra, new_nome, new_senha);

    close();
    new Senha();

}

