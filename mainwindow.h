#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "mysqlhandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    static MainWindow* instancia;
    QString ra;
    Ui::MainWindow *ui;
    BancoDeDados::MySQLHandler* handler;
    bool ra_cadastrado(QString r);
};
#endif // MAINWINDOW_H
