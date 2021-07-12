#ifndef MYSQLHANDLER_H
#define MYSQLHANDLER_H

#include <QSqlDatabase>
#include <iostream>

class MySQLHandler
{
private:
    QSqlDatabase db;
    QString hostname;
    QString userName;
    QString databaseName;
    QString password;
public:
    MySQLHandler();

    ~MySQLHandler();


};

#endif // MYSQLHANDLER_H
