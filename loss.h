#ifndef LOSS_H
#define LOSS_H

#include <QDialog>

namespace Ui {
class Loss;
}

class Loss : public QDialog
{
    Q_OBJECT

public:
    explicit Loss(QWidget *parent = nullptr);
    ~Loss();

private slots:
    void on_Quit_0_clicked();

private:
    Ui::Loss *ui;
};

#endif // LOSS_H
