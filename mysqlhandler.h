#ifndef MYSQLHANDLER_H
#define MYSQLHANDLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <iostream>

/* class Monitor;
class Aluno;
class horario;
class Agendamento;
class Orientador; */

namespace BancoDeDados {

const auto INSERT_ALUNO_SQL = QLatin1String(R"(
    INSERT INTO Aluno(ra, nome, senha) values(?, ?, ?)
    )");

    class MySQLHandler
    {
    private:
        QSqlDatabase db;
        QString hostname;
        QString userName;
        QString databaseName;
        QString password;
        QSqlQuery query;
    public:
        MySQLHandler();

        ~MySQLHandler();

        /*QVariant adicionar(Monitor monitor);
        QVariant adicionar(Aluno aluno);
        QVariant adicionar(Horario horario);
        QVariant adicionar(Agendamento agenda);
        QVariant adicionar(Orientador orientador);*/

        QVariant adicionarAluno(QString RA, QString nome, QString senha);
        //QVariant adicionarMonitor(Monitor monitor);

        void ShowError(QSqlError error);

    };
};
#endif // MYSQLHANDLER_H
