#ifndef REGISTROALUNO_H
#define REGISTROALUNO_H

#include <QDialog>
#include "mysqlhandler.h"

namespace Ui {
class RegistroAluno;
}

class RegistroAluno : public QDialog
{
    Q_OBJECT

public:
    explicit RegistroAluno(QWidget *parent = nullptr);
    ~RegistroAluno();

private slots:
    void on_cadastrar_clicked();

private:
    Ui::RegistroAluno *ui;
};

#endif // REGISTROALUNO_H
