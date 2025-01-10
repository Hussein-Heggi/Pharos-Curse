#ifndef PLAYER_H
#define PLAYER_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMouseEvent>
#include "QtMultimedia/qmediaplayer.h"
#include "QtWidgets/qgraphicsview.h"
#include "health.h"
//#include "bullet.h"
//#include "arrow.h"
#include <QGraphicsTextItem>
#include "loss.h"
#include "score.h"
//#include "shop.h"
class player :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int x = 60;
    int y = 30;
    int row;
    int column;
    int data[28][11];
    int direction;
    bool Finished1 = false;
    bool Finished2 = false;
    bool Finished3 = false;
    QMediaPlayer* sound = new QMediaPlayer;
    Loss l;
    //Shop *S=new Shop(score,health);


public:
    player(int [28][11]);
    Score *score;
    Health *health;
    int hp = 100;
    int getrow();
    int getcol();




public slots:
    void keyPressEvent(QKeyEvent* event);
    void collision();
    void checkRoom1();
    void checkRoom2();
    void checkRoom3();



};
#endif // PLAYER_H
