#include "interfacemonitor.h"
#include "ui_interfacemonitor.h"
#include "monitorpendencias.h"
#include "monitorpresencas.h"
#include "login.h"
Interfacemonitor::Interfacemonitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interfacemonitor)
{
    ui->setupUi(this);
    Interfacemonitor::setWindowTitle("Monitor");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

Interfacemonitor::~Interfacemonitor()
{
    delete ui;
}

void Interfacemonitor::on_pendencias_clicked()
{
    close();
    new MonitorPendencias();
}


void Interfacemonitor::on_tabela_clicked()
{

}


void Interfacemonitor::on_voltar_clicked()
{
    close();
    new Login();
}

