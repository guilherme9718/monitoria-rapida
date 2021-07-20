#ifndef REGISTROMONITOR_H
#define REGISTROMONITOR_H

#include <QDialog>

namespace Ui {
class RegistroMonitor;
}

class RegistroMonitor : public QDialog
{
    Q_OBJECT

public:
    explicit RegistroMonitor(QWidget *parent = nullptr);
    ~RegistroMonitor();

private slots:

    void on_pushButton_clicked();

private:
    Ui::RegistroMonitor *ui;
};

#endif // REGISTROMONITOR_H
