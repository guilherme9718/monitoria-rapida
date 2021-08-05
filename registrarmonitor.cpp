#include "registrarmonitor.h"
#include "ui_registrarmonitor.h"

RegistrarMonitor::RegistrarMonitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrarMonitor)
{
    ui->setupUi(this);
    this->monitor = nullptr;

    for(unsigned int i = 0; i < 5; i++){
        dia[i] = 0;
    }
}

RegistrarMonitor::~RegistrarMonitor()
{
    delete ui;
}

void RegistrarMonitor::on_segunda_clicked(){
    this->dia[0] = 1;
}


void RegistrarMonitor::on_terca_clicked(){
    this->dia[1] = 1;
}


void RegistrarMonitor::on_quarta_clicked(){
    this->dia[2] = 1;
}


void RegistrarMonitor::on_quinta_clicked(){
    this->dia[3] = 1;
}


void RegistrarMonitor::on_sexta_clicked(){
    this->dia[4] = 1;
}
void RegistrarMonitor::on_registrar_clicked()
{
    this->monitor = new Monitor();
    if(dia[0] == 1){
          this->monitor->adiciona_map_horarios("segunda feira", ui->horariosegunda->text());
    }
    if(dia[1] == 1){
          this->monitor->adiciona_map_horarios("terca feira", ui->horarioterca->text());
    }
    if(dia[2] == 1){
          this->monitor->adiciona_map_horarios("quarta feira", ui->horarioquarta->text());
    }
    if(dia[3] == 1){
          this->monitor->adiciona_map_horarios("quinta feira", ui->horarioquinta->text());
    }
    if(dia[4] == 1){
          this->monitor->adiciona_map_horarios("sexta feira", ui->horariosexta->text());
    }
    this->monitor->email = ui->email->text();
    this->monitor->senha = ui->senha->text();
    this->monitor->nome = ui->nome->text();
    this->monitor->monitor_disciplina = ui->disciplina->text();
    this->monitor->imprimir_mapa();
    //Salvar no banco de dados o novo monitor
}

