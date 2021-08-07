#include "monitorpendencias.h"
#include "ui_monitorpendencias.h"
#include "interfacemonitor.h"
MonitorPendencias::MonitorPendencias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonitorPendencias)
{
    ui->setupUi(this);
    listar_pendencias();
    MonitorPendencias::setWindowTitle("Pendencias");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

MonitorPendencias::~MonitorPendencias()
{
    delete ui;
}

void MonitorPendencias::listar_pendencias(){
    for(int i = 0; i < 10; i++){
        ui->listWidget->addItem(QString::number(i));
    }
}

void MonitorPendencias::on_pushButton_clicked()
{
    close();
    new Interfacemonitor();
}

