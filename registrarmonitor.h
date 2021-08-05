#ifndef REGISTRARMONITOR_H
#define REGISTRARMONITOR_H

#include <QDialog>
#include <QMap>
#include <monitor.h>
namespace Ui {
class RegistrarMonitor;
}

class RegistrarMonitor : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrarMonitor(QWidget *parent = nullptr);
    ~RegistrarMonitor();

private slots:
    void on_registrar_clicked();

    void on_segunda_clicked();

    void on_terca_clicked();

    void on_quarta_clicked();

    void on_quinta_clicked();

    void on_sexta_clicked();

private:
    Ui::RegistrarMonitor *ui;
    int dia[5];
    Monitor* monitor;
};

#endif // REGISTRARMONITOR_H
