#include "fireball.h"
#include "QtWidgets/qgraphicsitem.h"
#include <QPixmap>
#include <QTimer>
#include <ctime>

fireball::fireball(int dataitem[28][11], int r, int c,int dir){
    row = r;
    column = c;
    direction = dir;
    if(direction == 0)
    {
        QPixmap p("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/fireballUp.png");
        p = p.scaledToWidth(20);
        p = p.scaledToHeight(20);
        setPixmap(p);

    }
    else if(direction == 1)
    {
        QPixmap p("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/fireballDown.png");
        p = p.scaledToWidth(20);
        p = p.scaledToHeight(20);
        setPixmap(p);
    }
    else if(direction == 2)
    {
        QPixmap p("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/fireballLeft.png");
        p = p.scaledToWidth(15);
        p = p.scaledToHeight(15);
        setPixmap(p);
    }
    else if(direction == 3)
    {
        QPixmap p("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/fireballRight.png");
        p = p.scaledToWidth(15);
        p = p.scaledToHeight(15);
        setPixmap(p);
    }
    setPos(60+50*column,75+50*row);
    for(int i=0;i<28;i++)
        for (int j=0;j<11;j++)
            data[i][j]=dataitem[i][j];
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);
    srand(time(NULL));
}
void fireball::move(){
    if(direction == 0)
    {
        if(data[row-1][column]<=4){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(direction == 1)
    {
        if(data[row+1][column]<=4){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(direction == 2)
    {
        if(data[row][column-1]<=4){
            scene()->removeItem(this);
            delete this;
        }
    }
    else if(direction == 3)
    {
        if(data[row][column+1]<=4){
            scene()->removeItem(this);
            delete this;
        }
    }
    QList <QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for (int i = 0; i < n; i++){
        if (typeid(*(colliding_items[i])) == typeid(player)){
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    if(direction == 0)
    {
        row--;
    }
    else if(direction == 1)
    {
        row++;
    }
    else if(direction == 2)
    {
        column--;
    }
    else if(direction == 3)
    {
        column++;
    }
    setPos(60+50*column,75+50*row);
}
