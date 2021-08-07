#include "login.h"
#include "ui_login.h"
#include "senha.h"
#include "cadastro.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    handler = BancoDeDados::MySQLHandler::getInstance();
    this->ra = "";
    Login::setWindowTitle("Login");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_clicked()
{
    ra = ui->lineEdit->text();
    if(ra_cadastrado(ra)){
        close();
        new Senha(this);
    }
    else{
        close();
        new Cadastro(this);
    }
}

bool Login::ra_cadastrado(QString r){
    //retorna 1 se está no sistema 0 se nao
    QVector<Aluno*> alunos = handler->coletarAluno();
    std::cout << "aluno_qtd = " << alunos.size() << std::endl;
    for(int i=0; i < alunos.size(); i++) {
        std::cout << alunos[i]->ra << std::endl;
        if(alunos[i]->ra == r.toInt()) {
            return 1;
        }
    }
    return 1;
}
