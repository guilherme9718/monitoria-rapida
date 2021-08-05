#ifndef MONITOR_H
#define MONITOR_H

#include <QVector>
#include <QString>
#include <QMap>
#include "aluno.h"
#include "disciplina.h"

class Horario;

class Monitor : public Aluno
{
public:
    Monitor();
    ~Monitor();

    int monitorID;
    Disciplina *disciplina;
    QVector<Horario*> horarios;
    QMap <QString, QString> map_horarios;

    void adiciona_horario(Horario *hora);
    void adiciona_map_horarios(QString dia, QString range_horario);
    void imprimir_mapa();

    QString email;
    int ra;
    QString senha;
    QString nome;
    QString monitor_disciplina;
};

#endif // MONITOR_H
