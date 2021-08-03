#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "senha.h"
#include "cadastro.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    handler = BancoDeDados::MySQLHandler::getInstance();
    this->ra = "";
    ui->setupUi(this);
    MainWindow::setWindowTitle("Login");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   ra = ui->lineEdit->text();
   if(ra_cadastrado(ra)){
       hide();
       Senha* senha = new Senha(this);
       senha->show();
   }
   else{
       hide();
       Cadastro* cadastro = new Cadastro(this);
       cadastro->show();
   }
}

bool MainWindow::ra_cadastrado(QString r){
    //retorna 1 se está no sistema 0 se nao
    QVector<Aluno*> alunos = handler->coletarAluno();
    std::cout << "aluno_qtd = " << alunos.size() << std::endl;
    for(int i=0; i < alunos.size(); i++) {
        std::cout << alunos[i]->ra << std::endl;
        if(alunos[i]->ra == r.toInt()) {
            return 1;
        }
    }

    return 0;
}
