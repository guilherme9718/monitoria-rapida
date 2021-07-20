#ifndef HORARIO_H
#define HORARIO_H

#include <ctime>

class Horario
{
public:
    Horario();
    ~Horario();
private:
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
    int monitorID;
    int horarioID;
    time_t inicio;
    time_t fim;
};

#endif // HORARIO_H
