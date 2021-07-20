#include "mysqlhandler.h"

BancoDeDados::MySQLHandler::MySQLHandler()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    hostname = "localhost";
    userName = "app";
    password = "c5l32o";
    databaseName = "test";
    db.setHostName(hostname);
    db.setDatabaseName(databaseName);
    db.setUserName(userName);
    db.setPassword(password);
    bool ok = db.open();
    if(ok) {
        std::cout << "Database connected with success" << std::endl;
    }
    else {
        std::cout << "Error connecting database" << std::endl;
    }

    QSqlQuery q;
    this->query = q;

    db.close();
}

BancoDeDados::MySQLHandler::~MySQLHandler() {
    db.close();
}

QVariant BancoDeDados::MySQLHandler::adicionarAluno(QString RA, QString nome, QString senha) {
    db.open();

    if (!query.prepare(BancoDeDados::INSERT_ALUNO_SQL)) {
        ShowError(query.lastError());
        return QVariant(-99);
    }

    query.addBindValue(RA);
    query.addBindValue(nome);
    query.addBindValue(senha);
    query.exec();

    db.close();
    std::cout << "Sucesso ao inserir aluno";
    return query.lastInsertId();
}

void BancoDeDados::MySQLHandler::ShowError(QSqlError error) {
    std::cout << qPrintable(error.text()) << std::endl;
}

/*QVariant adicionar(Monitor monitor) {}
QVariant adicionar(Aluno aluno) {}
QVariant adicionar(Horario horario) {}
QVariant adicionar(Agendamento agenda) {}
QVariant adicionar(Orientador orientador) {} */
