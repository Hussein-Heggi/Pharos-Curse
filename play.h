#ifndef PLAY_H
#define PLAY_H


#include <QDialog>
#include <QApplication>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QAudioOutput>
#include "QtMultimedia/qmediaplayer.h"
#include "player.h"
#include "enemy1.h"
#include "enemy2.h"


namespace Ui {
class Play;
}

class Play : public QDialog
{
    Q_OBJECT

public:
    explicit Play(QWidget *parent = nullptr);
    void Music();
    ~Play();

private slots:
    void on_Quit_2_clicked();

    void on_Play_x_clicked();

    void on_Music_clicked();

private:
    Ui::Play *ui;
    QMediaPlayer* player = new QMediaPlayer;
    bool On;

};

#endif // PLAY_H
