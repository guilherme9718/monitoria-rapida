#include "registrarmonitor.h"
#include "ui_registrarmonitor.h"
#include <QDialog>
#include "mysqlhandler.h"
#include "login.h"
RegistrarMonitor::RegistrarMonitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrarMonitor)
{
    ui->setupUi(this);
    RegistrarMonitor::setWindowTitle("Monitor");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

RegistrarMonitor::~RegistrarMonitor()
{
    delete ui;
}

void RegistrarMonitor::on_registrar_clicked()
{
    Monitor* monitor = new Monitor();
    monitor->adiciona_map_horarios("segunda feira", ui->segunda->text());
    monitor->adiciona_map_horarios("terca feira", ui->terca->text());
    monitor->adiciona_map_horarios("quarta feira", ui->quarta->text());
    monitor->adiciona_map_horarios("quinta feira", ui->quinta->text());
    monitor->adiciona_map_horarios("sexta feira", ui->sexta->text());
    monitor->email = ui->email->text();
    monitor->senha = ui->senha->text();
    monitor->nome = ui->nome->text();
    monitor->mdisciplina = ui->disciplina->text();
    monitor->ra = ui->ra->text().toInt();
    monitor->imprimir_mapa();

    //BancoDeDados::MySQLHandler* handler = BancoDeDados::MySQLHandler::getInstance();
    //handler->adicionarMonitor(monitor);

    close();
    new Login();
}



