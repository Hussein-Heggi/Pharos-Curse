#include "changemap.h"
#include <QTimer>
#include <ctime>
#include "enemy1.h"
#include <QApplication>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QWidget>
#include <QMainWindow>
#include <QGraphicsView>
#include "player.h"
#include "enemy1.h"
#include "enemy2.h"
#include "health.h"


Changemap::Changemap()
{

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(OpenRoom2()));
    timer->start(100);


    QTimer *timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(OpenRoom3()));
    timer->start(100);


    QTimer *timer3 = new QTimer();
    connect(timer3, SIGNAL(timeout()), this, SLOT(OpenRoom4()));
    timer->start(100);

}


bool Changemap::Finished1(){
    if (enemy1::count1 <= 0){
        return true;
    }
}

bool changemap::Fins



