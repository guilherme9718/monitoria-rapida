#ifndef HORARIOSMONITOR_H
#define HORARIOSMONITOR_H

#include <QDialog>

namespace Ui {
class Horariosmonitor;
}

class Horariosmonitor : public QDialog
{
    Q_OBJECT

public:
    explicit Horariosmonitor(QWidget *parent = nullptr);
    ~Horariosmonitor();

private:
    Ui::Horariosmonitor *ui;
};

#endif // HORARIOSMONITOR_H
