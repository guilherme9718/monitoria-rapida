#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <QString>

class Disciplina
{
public:
    Disciplina();
    Disciplina(int id, QString codigo, QString nome, QString dep);

    ~Disciplina();

private:
    int disciplinaID;
    QString codigo;
    QString nome;
    QString departamento;
};

#endif // DISCIPLINA_H
