#ifndef MONITORPRESENCAS_H
#define MONITORPRESENCAS_H

#include <QDialog>

namespace Ui {
class MonitorPresencas;
}

class MonitorPresencas : public QDialog
{
    Q_OBJECT

public:
    explicit MonitorPresencas(QWidget *parent = nullptr);
    ~MonitorPresencas();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MonitorPresencas *ui;
    void listar_presencas();
};

#endif // MONITORPRESENCAS_H
