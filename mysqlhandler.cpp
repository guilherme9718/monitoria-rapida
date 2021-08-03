#include "mysqlhandler.h"

BancoDeDados::MySQLHandler* BancoDeDados::MySQLHandler::instance = nullptr;

BancoDeDados::MySQLHandler::MySQLHandler()
{
    instance = this;
    db = QSqlDatabase::addDatabase("QMYSQL");
    hostname = "localhost";
    userName = "app";
    password = "c5l32o";
    databaseName = "monitoria";
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

BancoDeDados::MySQLHandler* BancoDeDados::MySQLHandler::getInstance() {
    if(instance == nullptr) {
        instance = new BancoDeDados::MySQLHandler;
    }
    return instance;
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

QVector<Aluno*> BancoDeDados::MySQLHandler::coletarAluno(QString filter) {
    db.open();
    std::unique_ptr<QSqlRelationalTableModel> table{new QSqlRelationalTableModel(nullptr, db)};

    table->setTable("Aluno");
    table->setFilter(filter);
    table->setSort(0, Qt::SortOrder::AscendingOrder);
    table->select();

    int rowCount = table->rowCount();

    QVector<Aluno*> alunos;
    alunos.reserve(rowCount);
    for(int i=0; i < rowCount; i++) {
        Aluno* aluno = new Aluno;
        aluno->ra = table->record(i).value("ra").toInt();
        aluno->nome = table->record(i).value("nome").toString();
        aluno->senha = table->record(i).value("senha").toString();
        alunos.append(aluno);
    }

    db.close();

    return alunos;
}
QVariant BancoDeDados::MySQLHandler::adicionar(Monitor monitor) {

}
QVariant BancoDeDados::MySQLHandler::adicionar(Aluno aluno) {

}
QVariant BancoDeDados::MySQLHandler::adicionar(Horario horario) {

}
QVariant BancoDeDados::MySQLHandler::adicionar(Agendamento agenda) {

}
