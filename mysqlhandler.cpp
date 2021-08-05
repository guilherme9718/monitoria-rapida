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

QVariant BancoDeDados::MySQLHandler::adicionar(Monitor &monitor) {
    db.open();

    if (!query.prepare(BancoDeDados::INSERT_MONITOR_SQL)) {
        ShowError(query.lastError());
        return QVariant(-99);
    }

    if(!monitor.disciplina)
        return -99;

    query.addBindValue(monitor.ra);
    query.addBindValue(monitor.nome);
    query.addBindValue(monitor.senha);
    query.addBindValue(monitor.email);
    query.addBindValue(monitor.disciplina->disciplinaID);
    query.exec();

    db.close();
    std::cout << "Sucesso ao inserir monitor";
    return query.lastInsertId();
}
QVariant BancoDeDados::MySQLHandler::adicionar(Aluno &aluno) {
    db.open();

    if (!query.prepare(BancoDeDados::INSERT_ALUNO_SQL)) {
        ShowError(query.lastError());
        return QVariant(-99);
    }

    query.addBindValue(aluno.ra);
    query.addBindValue(aluno.nome);
    query.addBindValue(aluno.senha);
    query.exec();

    db.close();
    std::cout << "Sucesso ao inserir aluno";
    return query.lastInsertId();
}
QVariant BancoDeDados::MySQLHandler::adicionar(Horario &horario) {
    db.open();

    if (!query.prepare(BancoDeDados::INSERT_HORARIO_SQL)) {
        ShowError(query.lastError());
        return QVariant(-99);
    }

    if(!horario.monitor)
        return -99;

    query.addBindValue(horario.monitor->id);
    query.addBindValue(horario.diaSemana);
    query.addBindValue(horario.inicio.toString());
    query.addBindValue(horario.fim.toString());
    query.exec();

    db.close();
    std::cout << "Sucesso ao inserir horario";
    return query.lastInsertId();
}
QVariant BancoDeDados::MySQLHandler::adicionar(Agendamento &agenda) {
    db.open();

    if (!query.prepare(BancoDeDados::INSERT_AGENDAMENTO_SQL)) {
        ShowError(query.lastError());
        return QVariant(-99);
    }

    if(!agenda.aluno)
        return -99;
    query.addBindValue(agenda.aluno->ra);
    query.addBindValue(agenda.horario->horarioID);
    query.exec();

    db.close();
    std::cout << "Sucesso ao inserir agendamento";
    return query.lastInsertId();
}

QVariant BancoDeDados::MySQLHandler::adicionar(Disciplina &disc) {
    db.open();

    if (!query.prepare(BancoDeDados::INSERT_DISCIPLINA_SQL)) {
        ShowError(query.lastError());
        return QVariant(-99);
    }

    query.addBindValue(disc.codigo);
    query.addBindValue(disc.nome);
    query.addBindValue(disc.departamento);
    query.exec();

    db.close();
    std::cout << "Sucesso ao inserir disciplina";
    return query.lastInsertId();
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
QVector<Monitor*> BancoDeDados::MySQLHandler::coletarMonitor(QString filter) {
    db.open();
    std::unique_ptr<QSqlRelationalTableModel> table_monitor{new QSqlRelationalTableModel(nullptr, db)};

    table_monitor->setTable("Monitor");
    table_monitor->setFilter(filter);
    table_monitor->setSort(3, Qt::SortOrder::AscendingOrder);
    table_monitor->select();

    int rowCount = table_monitor->rowCount();

    QVector<Horario*> horarios = coletarHorario();

    QVector<Monitor*> monitores;
    monitores.reserve(rowCount);
    int init = 0, j=0;
    for(int i=0; i < rowCount; i++) {
        Monitor* monitor = new Monitor;
        monitor->ra = table_monitor->record(i).value("ra").toInt();
        monitor->nome = table_monitor->record(i).value("nome").toString();
        monitor->senha = table_monitor->record(i).value("senha").toString();
        monitor->monitorID = table_monitor->record(i).value("monitorID").toInt();
        monitor->email = table_monitor->record(i).value("email").toString();

        for(j = init; j < horarios.size(); j++) {
            if(monitor->monitorID == horarios[j]->id) {
                monitor->adiciona_horario(horarios[j]);
            }
            else if(monitor->monitorID > horarios[j]->id) {
                init = j;
                break;
            }
        }

        monitores.append(monitor);
    }

    db.close();

    return monitores;
}
QVector<Disciplina*> BancoDeDados::MySQLHandler::coletarDisciplina(QString filter) {
    db.open();
    std::unique_ptr<QSqlRelationalTableModel> table{new QSqlRelationalTableModel(nullptr, db)};

    table->setTable("Disciplina");
    table->setFilter(filter);
    table->setSort(0, Qt::SortOrder::AscendingOrder);
    table->select();

    int rowCount = table->rowCount();

    QVector<Disciplina*> disciplinas;
    disciplinas.reserve(rowCount);
    for(int i=0; i < rowCount; i++) {
        Disciplina* disc = new Disciplina;
        disc->disciplinaID = table->record(i).value("disciplinaID").toInt();
        disc->codigo = table->record(i).value("codigo").toString();
        disc->nome = table->record(i).value("nome").toString();
        disc->departamento = table->record(i).value("departamento").toString();
        disciplinas.append(disc);
    }

    db.close();

    return disciplinas;
}
QVector<Agendamento*> BancoDeDados::MySQLHandler::coletarAgendamento(QString filter) {
    db.open();
    std::unique_ptr<QSqlRelationalTableModel> table{new QSqlRelationalTableModel(nullptr, db)};

    table->setTable("Agendamento");
    table->setFilter(filter);
    table->setSort(0, Qt::SortOrder::AscendingOrder);
    table->select();

    int rowCount = table->rowCount();

    QVector<Agendamento*> agendas;
    agendas.reserve(rowCount);
    for(int i=0; i < rowCount; i++) {
        Agendamento* agenda = new Agendamento;
        agenda->alunoID = table->record(i).value("alunoID").toInt();
        agenda->horarioID = table->record(i).value("horarioID").toInt();
        agendas.append(agenda);
    }

    db.close();

    return agendas;
}

QVector<Horario*> BancoDeDados::MySQLHandler::coletarHorario(QString filter) {
    db.open();
    std::unique_ptr<QSqlRelationalTableModel> table{new QSqlRelationalTableModel(nullptr, db)};

    table->setTable("Horario");
    table->setFilter(filter);
    table->setSort(0, Qt::SortOrder::AscendingOrder);
    table->select();

    int rowCount = table->rowCount();

    QVector<Horario*> horarios;
    horarios.reserve(rowCount);
    for(int i=0; i < rowCount; i++) {
        Horario* hora = new Horario;
        hora->horarioID = table->record(i).value("horarioID").toInt();
        hora->id = table->record(i).value("monitorID").toInt();
        hora->diaSemana = table->record(i).value("diaSemana").toInt();
        hora->inicio = table->record(i).value("inicio").toTime();
        hora->fim = table->record(i).value("fim").toTime();
        horarios.append(hora);
    }

    db.close();

    return horarios;
}
