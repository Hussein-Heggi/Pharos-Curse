#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Login.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Login_clicked();

    void on_Quit_clicked();

private:
    Ui::MainWindow *ui;
    Login logmenu;

};
#endif // MAINWINDOW_H
