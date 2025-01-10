#include "win.h"
#include "ui_win.h"

Win::Win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Win)
{
    ui->setupUi(this);
    ui->Win_2->setPixmap(QPixmap("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Win.png"));
}

Win::~Win()
{
    delete ui;
}

void Win::on_Quit_a_clicked()
{
    QApplication::quit();
}

