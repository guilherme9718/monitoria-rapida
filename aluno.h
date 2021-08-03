#ifndef ALUNO_H
#define ALUNO_H

#include <QString>
#include "entidade.h"

class Aluno : public Entidade
{
public:
    Aluno();
    ~Aluno();

    int ra;
    QString nome;
    QString senha;
};

#endif // ALUNO_H
