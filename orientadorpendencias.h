#ifndef ORIENTADORPENDENCIAS_H
#define ORIENTADORPENDENCIAS_H

#include <QDialog>

namespace Ui {
class OrientadorPendencias;
}

class OrientadorPendencias : public QDialog
{
    Q_OBJECT

public:
    explicit OrientadorPendencias(QWidget *parent = nullptr);
    ~OrientadorPendencias();

private slots:
    void on_voltar_clicked();

private:
    Ui::OrientadorPendencias *ui;
};

#endif // ORIENTADORPENDENCIAS_H
