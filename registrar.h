#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QDialog>

namespace Ui {
class Registrar;
}

class Registrar : public QDialog
{
    Q_OBJECT

public:
    explicit Registrar(QWidget *parent = nullptr);
    ~Registrar();

private:
    Ui::Registrar *ui;
};

#endif // REGISTRAR_H
