#include "mysqlhandler.h"

MySQLHandler::MySQLHandler()
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

    db.close();
}

MySQLHandler::~MySQLHandler() {
    db.close();
}
