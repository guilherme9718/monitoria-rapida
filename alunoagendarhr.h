#ifndef ALUNOAGENDARHR_H
#define ALUNOAGENDARHR_H

#include <QDialog>

namespace Ui {
class AlunoAgendarHr;
}

class AlunoAgendarHr : public QDialog
{
    Q_OBJECT

public:
    explicit AlunoAgendarHr(QWidget *parent = nullptr);
    ~AlunoAgendarHr();

private slots:
    void on_voltar_clicked();

private:
    Ui::AlunoAgendarHr *ui;
};

#endif // ALUNOAGENDARHR_H
