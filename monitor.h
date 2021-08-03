#ifndef MONITOR_H
#define MONITOR_H

#include <QVector>

#include "aluno.h"
#include "disciplina.h"

class Horario;

class Monitor : public Aluno
{
public:
    Monitor();
    ~Monitor();

    int monitorID;
    QString email;
    Disciplina *disciplina;
    QVector<Horario*> horarios;

    void adiciona_horario(Horario *hora);
};

#endif // MONITOR_H
