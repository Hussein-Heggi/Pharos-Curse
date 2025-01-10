#include "enemy1.h"
#include "arrow.h"
#include <QTimer>
#include <ctime>
#include "changemap.h"
#include "bullet.h"
#include "score.h"
#include "player.h"

int enemy1::count1 = 0;
int enemy1::count2 = 0;

enemy1::enemy1(int dataitem [28][11], int r, int c, int ro, player *a)
{
        x = a;
       row= r;
       column= c;
       room = ro;
       QPixmap p("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/e1.png");
       p=p.scaledToWidth(50);
       p=p.scaledToHeight(50);
       setPixmap(p);
       setPos(50+50*column,50+50*row);
       for(int i=0;i<28;i++)
           for (int j=0;j<11;j++)
               data[i][j]=dataitem[i][j];

       if (room == 1){
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
        move();
        srand(time(NULL));

        QTimer *timer2 = new QTimer();
        connect(timer2,SIGNAL(timeout()),this,SLOT(attack()));
        timer2->start(600);
        srand(time(NULL));

        QTimer *timer3 = new QTimer();
        connect(timer3, SIGNAL(timeout()),this,SLOT(collision()));
        timer3->start(50);
        srand(time(NULL));

}
void enemy1::move(){
    {
        if (!(this->health <= 0))
        {
            srand(time(NULL));
            int rnd = arc4random() % 4;
            if(rnd == 0 && !(data[row-1][column]<=4))
            {
                row--;
            }
            else if(rnd == 1 &&!(data[row+1][column]<=4))
            {
                row++;
            }
            else if(rnd == 2 && !(data[row][column-1]<=4))
            {
                column--;
            }
            else if(rnd == 3 &&!(data[row][column+1]<=4))
            {
                column++;
            }
            setPos(50+50*column,50+50*row);
            direction = rnd;
        }
    }
}

void enemy1::attack()
{
    if (!(this->health <= 0)){
        arrow *Arrow = new arrow(data,row,column,direction);
        scene()->addItem(Arrow);
    }


}

void enemy1::collision(){
    QList <QGraphicsItem *> colliding_items = collidingItems();
        int n = colliding_items.size();
        for (int i = 0; i < n; i++){
            if (typeid(*(colliding_items[i])) == typeid(Bullet)){
                DecreaseHealth(20);
                x->score->IncreaseScore(10);

                qDebug () << "enemy health" << health;
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                if (this->getHealth() <= 0){
                    scene()->removeItem(this);
                    if(room == 1){
                        count1--;
                    }
                    else if (room == 3){
                        count2--;
                    }
                    qDebug() << "count: " << count1;

                    return;
                }
                return;
            }

        }

}

void enemy1::DecreaseHealth(int num){
    health -= num;
}

int enemy1::getHealth(){
    return health;
}



enemy1::~enemy1(){
    if (room == 1){
        count1--;
    }
    else if (room == 3){
        count2--;
    }
}

