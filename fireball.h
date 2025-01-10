#ifndef FIREBALL_H
#define FIREBALL_H
#include <QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "enemy1.h"
#include <QList>
#include <ctime>
#include "player.h"

class fireball:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[28][11];
    int direction;
public:
    fireball (int dataitem[28][11], int r, int c, int dir);
public slots:
    void move();
};

#endif // FIREBALL_H
