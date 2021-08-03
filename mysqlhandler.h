#ifndef MYSQLHANDLER_H
#define MYSQLHANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <iostream>
#include <ctime>

#include "aluno.h"
#include "monitor.h"
#include "horario.h"
#include "agendamento.h"
#include "disciplina.h"

/* class Monitor;
class Aluno;
class horario;
class Agendamento;
class Orientador; */

namespace BancoDeDados {

const auto INSERT_ALUNO_SQL = QLatin1String(R"(
    INSERT INTO Aluno(ra, nome, senha) values(?, ?, ?)
    )");
const auto INSERT_MONITOR_SQL = QLatin1String(R"(
    INSERT INTO Monitor(ra, nome, senha, email, disciplinaID) values(?, ?, ?, ?, ?)
    )");
const auto INSERT_HORARIO_SQL = QLatin1String(R"(
    INSERT INTO Horario(monitorID, diaSemana, inicio, fim) values(?, ?, ?, ?)
    )");
const auto INSERT_AGENDAMENTO_SQL = QLatin1String(R"(
    INSERT INTO Agendamento(alunoID, HorarioID) values(?, ?)
    )");
const auto INSERT_DISCIPLINA_SQL = QLatin1String(R"(
    INSERT INTO Disciplina(codigo, nome, departamento) values(?, ?, ?)
    )");

    class MySQLHandler
    {
    private:
        MySQLHandler();

        QSqlDatabase db;
        QString hostname;
        QString userName;
        QString databaseName;
        QString password;
        QSqlQuery query;

        static MySQLHandler* instance;
    public:
        ~MySQLHandler();

        static MySQLHandler* getInstance();
        QVariant adicionar(Monitor &monitor);
        QVariant adicionar(Aluno &aluno);
        QVariant adicionar(Horario &horario);
        QVariant adicionar(Agendamento &agenda);
        //QVariant adicionar(Orientador orientador);
        QVariant adicionar(Disciplina &disc);

        QVariant adicionarAluno(QString RA, QString nome, QString senha);
        //QVariant adicionarMonitor(Monitor monitor);

        QVector<Aluno*> coletarAluno(QString filter="");
        QVector<Monitor*> coletarMonitor(QString filter="");
        QVector<Disciplina*> coletarDisciplina(QString filter="");
        QVector<Agendamento*> coletarAgendamento(QString filter="");

        void ShowError(QSqlError error);

    };
};
#endif // MYSQLHANDLER_H
