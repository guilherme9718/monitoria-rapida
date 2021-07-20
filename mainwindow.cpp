#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Senha.h"
#include "cadastro.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
    return 0;
}
