#include "registromonitor.h"
#include "ui_registromonitor.h"
#include "senha.h"
RegistroMonitor::RegistroMonitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistroMonitor)
{
    ui->setupUi(this);
}

RegistroMonitor::~RegistroMonitor()
{
    delete ui;
}



void RegistroMonitor::on_pushButton_clicked()
{
    close();
    Senha* senha = new Senha(this);
    senha->show();
}

