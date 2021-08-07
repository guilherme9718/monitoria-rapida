#ifndef MONITORPENDENCIAS_H
#define MONITORPENDENCIAS_H

#include <QDialog>

namespace Ui {
class MonitorPendencias;
}

class MonitorPendencias : public QDialog
{
    Q_OBJECT

public:
    explicit MonitorPendencias(QWidget *parent = nullptr);
    ~MonitorPendencias();

private slots:
    void on_pushButton_clicked();

private:
    void listar_pendencias();
    Ui::MonitorPendencias *ui;
};

#endif // MONITORPENDENCIAS_H
