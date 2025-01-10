#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Menu->setPixmap(QPixmap("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Menu.png"));
    ui->Eye->setPixmap(QPixmap ("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Eye.png"));
    ui->Title->setPixmap(QPixmap ("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Title.png"));
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Login_clicked()
{
    logmenu.setWindowTitle("The Pharaoh's curse");
    logmenu.setFixedSize(900,700);
    logmenu.show();
    this->close();
}


void MainWindow::on_Quit_clicked()
{
    QApplication::quit();
}

