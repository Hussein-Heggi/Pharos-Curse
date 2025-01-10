#ifndef POISONBALL_H
#define POISONBALL_H
#include <QObject>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "enemy1.h"
#include <QList>
#include <ctime>
#include "player.h"

class poisonball:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int data[28][11];
    int direction;
public:
    poisonball (int dataitem[28][11], int r, int c);
public slots:
    void move();
};
#endif // POISONBALL_H
