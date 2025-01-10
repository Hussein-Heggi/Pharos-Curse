#include "play.h"
#include "QtMultimedia/qmediaplayer.h"
#include "ui_play.h"

Play::Play(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Play)
{
    ui->setupUi(this);
    ui->PlayMenu->setPixmap(QPixmap("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Menu.png"));
    ui->Eye3->setPixmap(QPixmap ("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Eye.png"));
    On = false;

}

Play::~Play()
{
    delete ui;
}

void Play::on_Quit_2_clicked()
{
    QApplication::quit();
}

void Play::on_Play_x_clicked()
{
    this->close();
}


void Play::on_Music_clicked()
{
    if (On == true)
    {
        On = false;
        player->stop();
    }
    else if (On == false)
    {
        On = true;
        QAudioOutput *theme = new QAudioOutput();
        player->setAudioOutput(theme);
        player->setSource(QUrl("qrc:/Sound/Theme.mp3"));
        player->setLoops(QMediaPlayer::Infinite);
        player->play();
    }
}

