#ifndef ORIENTADORPRESENCAS_H
#define ORIENTADORPRESENCAS_H

#include <QDialog>

namespace Ui {
class OrientadorPresencas;
}

class OrientadorPresencas : public QDialog
{
    Q_OBJECT

public:
    explicit OrientadorPresencas(QWidget *parent = nullptr);
    ~OrientadorPresencas();

private slots:
    void on_voltar_clicked();

private:
    Ui::OrientadorPresencas *ui;
};

#endif // ORIENTADORPRESENCAS_H
