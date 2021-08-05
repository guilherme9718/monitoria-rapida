#ifndef HORARIO_H
#define HORARIO_H

#include <ctime>
#include <QTime>

#include "monitor.h"
#include "entidade.h"

class Horario : public Entidade
{
public:
    Horario();
    ~Horario();

    /*
    1 = segunda
    2 = terça
    4 = quarta
    8 = quinta
    16 = sexta
    32 = sabado
    64 = domingo
    */
    char diaSemana;
    Monitor* monitor;
    int horarioID;
    QTime inicio;
    QTime fim;
};

#endif // HORARIO_H
