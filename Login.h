#ifndef LOGIN_H
#define LOGIN_H

#include "play.h"
#include <QDialog>
#include <QFile>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_Log_clicked();

    void on_Clear_clicked();

private:
    Ui::Login *ui;
    QString NAME;
    QString PASSWORD;
    Play play;
};

#endif // LOGIN_H
