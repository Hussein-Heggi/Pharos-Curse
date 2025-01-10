#ifndef ENEMY2_H
#define ENEMY2_H
#include "player.h"
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
class enemy2 :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int room;
    int data[28][11];
    int health = 120;
    int direction;
    player *x;
public:
    enemy2(int[28][11], int r, int c, int ro, player *a);
    void DecreaseHealth(int num);
    int getHealth();
    static int count1;
    static int count2;


public slots:
    void move();
    void attack();
    void collision();

};
#endif // ENEMY2_H
