#ifndef INTERFACEMONITOR_H
#define INTERFACEMONITOR_H

#include <QDialog>

namespace Ui {
class Interfacemonitor;
}

class Interfacemonitor : public QDialog
{
    Q_OBJECT

public:
    explicit Interfacemonitor(QWidget *parent = nullptr);
    ~Interfacemonitor();

private slots:
    void on_pendencias_clicked();

    void on_tabela_clicked();

    void on_voltar_clicked();

private:
    Ui::Interfacemonitor *ui;
};

#endif // INTERFACEMONITOR_H
