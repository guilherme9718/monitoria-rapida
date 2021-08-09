#ifndef INTERFACEORIENTADOR_H
#define INTERFACEORIENTADOR_H

#include <QDialog>

namespace Ui {
class InterfaceOrientador;
}

class InterfaceOrientador : public QDialog
{
    Q_OBJECT

public:
    explicit InterfaceOrientador(QWidget *parent = nullptr);
    ~InterfaceOrientador();

private slots:
    void on_voltar_clicked();

    void on_pendencias_clicked();

    void on_tabela_clicked();

private:
    Ui::InterfaceOrientador *ui;
};

#endif // INTERFACEORIENTADOR_H
