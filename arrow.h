#ifndef ARROW_H
#define ARROW_H
#include <QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "enemy1.h"
#include "enemy2.h"
#include <QList>
#include <ctime>
#include "player.h"

class arrow: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[28][11];
    int direction;
public:
    arrow (int dataitem[28][11], int r, int c, int dir);
public slots:
    void move();

};
#endif
