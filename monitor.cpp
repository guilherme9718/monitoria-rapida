#include "monitor.h"
#include "horario.h"
#include "mysqlhandler.h"
#include <QTextStream>

QTextStream out(stdout);
Monitor::Monitor()
{
    this->email = "";
    this->mdisciplina = "";
    this->disciplina = nullptr;
}

Monitor::~Monitor() {
    for(int i=0; i < horarios.size(); i++) {
        delete(horarios[i]);
    }
    QMutableMapIterator<QString, QString> i(this->map_horarios);
     while (i.hasNext()) {
             i.remove();
     }
}

void Monitor::adiciona_horario(Horario *hora) {
    hora->monitor = this;
    horarios.append(hora);
    BancoDeDados::MySQLHandler::getInstance()->adicionar(*hora);
}

void Monitor::adiciona_map_horarios(QString dia, QString range_horario){
    this->map_horarios.insert(dia, range_horario);
}

void Monitor::imprimir_mapa(){
    QMapIterator<QString, QString> i(this->map_horarios);
    while (i.hasNext()) {
        i.next();
        out << i.key() << ": " << i.value() << Qt::endl;
    }
}
