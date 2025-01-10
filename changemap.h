#ifndef CHANGEMAP_H
#define CHANGEMAP_H
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QMouseEvent>
#include "health.h"
#include "bullet.h"
#include "arrow.h"
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include "enemy1.h"
#include "arrow.h"
#include <QTimer>
#include <ctime>
#include "bullet.h"
#include "QtWidgets/qgraphicsitem.h"

class Changemap:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Changemap();
public slots:
    bool Finished1();
    bool Finished2();
    bool Finished3();
private:
    bool enemies1 = false;
    bool enemies2 = false;
    bool enemies3 = false;



};
#endif // CHANGEMAP_H
