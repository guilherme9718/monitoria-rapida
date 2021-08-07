#ifndef ALUNOPENDENCIAS_H
#define ALUNOPENDENCIAS_H

#include <QDialog>

namespace Ui {
class AlunoPendencias;
}

class AlunoPendencias : public QDialog
{
    Q_OBJECT

public:
    explicit AlunoPendencias(QWidget *parent = nullptr);
    ~AlunoPendencias();

private slots:
    void on_voltar_clicked();

private:
    Ui::AlunoPendencias *ui;
};

#endif // ALUNOPENDENCIAS_H
