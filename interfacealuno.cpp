#include "interfacealuno.h"
#include "ui_interfacealuno.h"
#include "mainwindow.h"

InterfaceAluno::InterfaceAluno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InterfaceAluno)
{
    ui->setupUi(this);
}

InterfaceAluno::~InterfaceAluno()
{
    delete ui;
}

void InterfaceAluno::on_agendar_clicked()
{
    close();
}


void InterfaceAluno::on_preferencias_clicked()
{
    close();
}

void InterfaceAluno::on_tabela_clicked()
{
    close();
}

void InterfaceAluno::on_voltar_clicked()
{
    close();
    MainWindow* w = new MainWindow(this);
    w->show();
}


void InterfaceAluno::on_pendencias_clicked()
{

}

