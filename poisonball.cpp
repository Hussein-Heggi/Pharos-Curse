#include "poisonball.h"
#include "poisonball.h"
#include "QtWidgets/qgraphicsitem.h"
#include <QPixmap>
#include <QTimer>
#include <ctime>

poisonball::poisonball(int dataitem[28][11], int r, int c)
{
    row = r;
    column = c;
    srand(time(NULL));
    direction = rand()%4;


    QPixmap p("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/poison.png");
    setPixmap(p);

    setPos(60+50*column,75+50*row);
    for(int i=0;i<28;i++)
        for (int j=0;j<11;j++)
            data[i][j]=dataitem[i][j];

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);
    srand(time(NULL));
}
void poisonball::move()
{
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
        if(data[row][column+1]<=4)
        {
            scene()->removeItem(this);
            delete this;
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
