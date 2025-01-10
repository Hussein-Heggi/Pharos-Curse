#include "enemy2.h"
#include "bullet.h"
#include "fireball.h"
#include <QTimer>
#include <ctime>

int enemy2::count1 = 0;
int enemy2::count2 = 0;

enemy2::enemy2(int dataitem [28][11], int r, int c, int ro, player *a)
{
        x = a;
       row= r;
       column= c;
       room = ro;
       QPixmap p("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/e2.png");
       p=p.scaledToWidth(50);
       p=p.scaledToHeight(50);
       setPixmap(p);
       setPos(50+50*column,50+50*row);
       for(int i=0;i<28;i++)
           for (int j=0;j<11;j++)
               data[i][j]=dataitem[i][j];

       if (room == 2){
           count1++;
       }
       else if (room == 3){
           count2++;
       }
//       else if (room == 4){

//       }

        QTimer *timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(move()));
        timer->start(600);


        QTimer *timer2 = new QTimer();
        connect(timer2,SIGNAL(timeout()),this,SLOT(attack()));
        timer2->start(600);

        QTimer *timer3 = new QTimer();
        connect(timer3, SIGNAL(timeout()),this,SLOT(collision()));
        timer3->start(50);



}
void enemy2::move(){
    {
        if (!(this->health <= 0))
        {
            srand(time(NULL));
            int rnd = arc4random() % 4;
            if(rnd == 0 && (data[row-1][column]!=02 && data[row-1][column] != -1 && data[row-1][column] != 03 && data[row-1][column]!= 04 && data[row-1][column]!=05))
            {
                row--;
            }
            else if(rnd == 1 && (data[row+1][column]!=02 && data[row+1][column] != -1 && data[row+1][column] != 03 && data[row+1][column] != 04 && data[row+1][column] != 05))
            {
                row++;
            }
            else if(rnd == 2 && (data[row][column-1]!=02 && data[row][column-1] != -1 && data[row][column-1] != 03 && data[row][column-1]!=4 && data[row][column-1]!=05))
            {
                column--;
            }
            else if(rnd == 3 && (data[row][column+1]!=02 && data[row][column+1] != -1 && data[row][column+1] != 03 && data[row][column+1] != 04 && data[row][column+1] != 05))
            {
                column++;
            }
            setPos(50+50*column,50+50*row);
            direction = rnd;
    }}
}

void enemy2::attack(){
    if (!(this->health <= 0)){
        fireball *Fireball = new fireball(data,row,column, direction);
        scene()->addItem(Fireball);
    }

}

void enemy2::collision(){
    QList <QGraphicsItem *> colliding_items = collidingItems();
        int n = colliding_items.size();
        for (int i = 0; i < n; i++){
            if (typeid(*(colliding_items[i])) == typeid(Bullet)){
                DecreaseHealth(20);
                x->score->IncreaseScore(10);
                qDebug () << "enemy health" << health;
                scene()->removeItem(colliding_items[i]);
                delete (colliding_items[i]);
                if (this->getHealth() <= 0){
                    scene()->removeItem(this);
                    if(room == 2){
                        count1--;
                    }
                    else if (room == 3){
                        count2--;
                    }
                }
                return;
            }
            //qDebug() << "count: " << count1;
        }
}

void enemy2::DecreaseHealth(int num){
    health -= num;
}

int enemy2::getHealth(){
    return health;
}


