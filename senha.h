#ifndef SENHA_H
#define SENHA_H

#include <QDialog>

namespace Ui {
class Senha;
}

class Senha : public QDialog
{
    Q_OBJECT

public:
    explicit Senha(QWidget *parent = nullptr);
    ~Senha();

private slots:
    void on_login_clicked();

    void on_voltar_clicked();

private:
    Ui::Senha *ui;
};

#endif // SENHA_H
