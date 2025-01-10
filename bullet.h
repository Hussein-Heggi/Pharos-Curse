#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "enemy1.h"
#include "enemy2.h"
#include <QList>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[28][11];
    int direction;
public:
    Bullet(int dataitem[28][11], int r, int c, int dir);
public slots:
    void move();

};

#endif // BULLET_H
