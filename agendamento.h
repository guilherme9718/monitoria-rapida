#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#include "aluno.h"
#include "horario.h"

class Agendamento
{
public:
    Agendamento();
    ~Agendamento();

    Aluno* aluno;
    Horario* horario;
};

#endif // AGENDAMENTO_H
