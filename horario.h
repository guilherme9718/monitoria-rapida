#ifndef HORARIO_H
#define HORARIO_H

#include <ctime>

#include "monitor.h"

class Horario
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
    tm inicio;
    tm fim;
};

#endif // HORARIO_H
