#ifndef INTERFACEALUNO_H
#define INTERFACEALUNO_H

#include <QDialog>

namespace Ui {
class InterfaceAluno;
}

class InterfaceAluno : public QDialog
{
    Q_OBJECT

public:
    explicit InterfaceAluno(QWidget *parent = nullptr);
    ~InterfaceAluno();

private slots:
    void on_agendar_clicked();

    void on_tabela_clicked();

    void on_voltar_clicked();

    void on_pendencias_clicked();

private:
    Ui::InterfaceAluno *ui;
};

#endif // INTERFACEALUNO_H
