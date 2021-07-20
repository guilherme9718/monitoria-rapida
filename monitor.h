#ifndef MONITOR_H
#define MONITOR_H

#include "aluno.h"

class Disciplina;

class Monitor : public Aluno
{
public:
    Monitor();
    ~Monitor();

private:
    int monitorID;
    QString email;
    Disciplina *disciplina;
};

#endif // MONITOR_H
