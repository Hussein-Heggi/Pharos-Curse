#ifndef ENEMY1_H
#define ENEMY1_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include "player.h"
#include "score.h"

class enemy1 :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT


private:

    int row;
    int column;
    int room;
    int data[28][11];
    int health = 80;
    int direction;
    player *x;

public:
    enemy1(int[28][11], int r, int c, int ro, player *a);
    void DecreaseHealth(int num);
    int getHealth();

    static int count1;
    static int count2;
    ~enemy1();

public slots:
    void move();
    void attack();
    void collision();
};

#endif // ENEMY1_H
