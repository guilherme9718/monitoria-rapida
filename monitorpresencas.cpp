#include "monitorpresencas.h"
#include "ui_monitorpresencas.h"
#include "interfacemonitor.h"
MonitorPresencas::MonitorPresencas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MonitorPresencas)
{
    ui->setupUi(this);
    listar_presencas();
    MonitorPresencas::setWindowTitle("Presencas");
    setWindowIcon(QIcon(":/icones/mricon.png"));
    this->show();
}

MonitorPresencas::~MonitorPresencas()
{
    delete ui;
}

void MonitorPresencas::listar_presencas(){
    for(int i = 0; i < 10; i++){
        ui->listWidget->addItem(QString::number(i));
    }
}
void MonitorPresencas::on_pushButton_clicked()
{
    close();
    new Interfacemonitor();
}

