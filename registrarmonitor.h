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

private:
    Ui::RegistrarMonitor *ui;
};

#endif // REGISTRARMONITOR_H
