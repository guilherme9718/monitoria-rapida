#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "mysqlhandler.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_login_clicked();

private:
    QString ra;
    BancoDeDados::MySQLHandler* handler;
    bool ra_cadastrado(QString r);
    Ui::Login *ui;
};

#endif // LOGIN_H
