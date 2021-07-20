#ifndef ALUNO_H
#define ALUNO_H

#include <QString>

class Aluno
{
public:
    Aluno();
    ~Aluno();

private:
    int ra;
    QString nome;
    QString senha;
};

#endif // ALUNO_H
