#include "Login.h"
#include "QtMultimedia/qmediaplayer.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->LogMenu->setPixmap(QPixmap("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Menu.png"));
    ui->Eye2->setPixmap(QPixmap ("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Eye.png"));
    QMediaPlayer *theme = new QMediaPlayer();
    theme->setSource(QUrl("qrc:/Sound/Theme.mp3"));
    theme->play();
}

Login::~Login()
{
    delete ui;
}

void Login::on_Log_clicked()
{
    NAME = ui->user->text();
    PASSWORD = ui->pass->text();
    QFile file("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/login.txt");
    file.open(QIODevice::ReadOnly);
    // creating a text stream
    QTextStream stream(&file);
    QString tempU,tempP;
    stream>>tempU;
    stream>>tempP;
    if (NAME == tempU && PASSWORD == tempP)
    {
        play.setWindowTitle("The Pharaoh's curse");
        play.setFixedSize(900,700);
        play.show();
        this->close();
    }
    else
        ui->status->setText("Login Failed ... Please Try Again");


}

void Login::on_Clear_clicked()
{
    ui->user->setText("");
    ui->pass->setText("");
}

