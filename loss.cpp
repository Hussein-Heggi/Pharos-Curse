#include "loss.h"
#include "ui_loss.h"

Loss::Loss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loss)
{
    ui->setupUi(this);
    ui->Lost->setPixmap(QPixmap("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Over.png"));
}

Loss::~Loss()
{
    delete ui;
}

void Loss::on_Quit_0_clicked()
{
    QApplication::quit();
}

