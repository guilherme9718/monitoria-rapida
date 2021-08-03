#include "monitor.h"
#include "horario.h"
#include "mysqlhandler.h"

Monitor::Monitor()
{
    monitorID = 0;
    email = "";
    disciplina = nullptr;
}

Monitor::~Monitor() {
    for(int i=0; i < horarios.size(); i++) {
        delete(horarios[i]);
    }
}

void Monitor::adiciona_horario(Horario *hora) {
    hora->monitor = this;
    horarios.append(hora);
    BancoDeDados::MySQLHandler::getInstance()->adicionar(*hora);
}
