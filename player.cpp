#include "player.h"
#include "QtMultimedia/qaudiooutput.h"
#include "QtWidgets/qgraphicsscene.h"
#include "arrow.h"
#include "boss.h"
#include "bullet.h"
#include "fireball.h"
#include "poisonball.h"




player::player(int dataitem [28][11])
{

   row=1;
   column=1;
   score = new Score();
   health = new Health();
   health->healthcolor();
   (this->health)->setPos(this->health->x() + x, this->health->y()+x);
   (this->score)->setPos(this->score->x() + x, this->score->y()+y);


   QPixmap p("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/character.png");
   p=p.scaledToWidth(50);
   p=p.scaledToHeight(50);
   setPixmap(p);
   setPos(50+50*column,50+50*row);
   for(int i=0;i<28;i++)
       for (int j=0;j<11;j++)
           data[i][j]=dataitem[i][j];

   QTimer *timer = new QTimer();
   connect(timer, SIGNAL(timeout()),this,SLOT(collision()));
   timer->start(50);


   QTimer *timer2 = new QTimer();
   connect(timer2, SIGNAL(timeout()),this,SLOT(checkRoom1()));
   timer2->start(5000);


   QTimer *timer3 = new QTimer();
   connect(timer3, SIGNAL(timeout()),this,SLOT(checkRoom2()));
   timer3->start(5000);



   QTimer *timer4 = new QTimer();
   connect(timer4, SIGNAL(timeout()),this,SLOT(checkRoom3()));
   timer4->start(5000);


}



void player::keyPressEvent(QKeyEvent* event)
{

    if(event->key()==Qt::Key_Up&&!(data[row-1][column]<=4))
    {
        row--;
        direction = 0;
    }
    else if(event->key()==Qt::Key_Down&&!(data[row+1][column]<=4))
    {
        row++;
        direction = 1;
    }
    else if(event->key()==Qt::Key_Left&&!(data[row][column-1]<=4))
    {
        column--;
        direction = 2;
    }
    else if(event->key()==Qt::Key_Right&&!(data[row][column+1]<=4))
    {
        column++;
        direction = 3;
    }
    else if (event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet(data, row, column,direction);
        scene()->addItem(bullet);
        QAudioOutput *bulletsound = new QAudioOutput();
        sound->setAudioOutput(bulletsound);
        sound->setSource(QUrl("qrc:/Sound/Bullet_Sound.mp3"));


        if (sound->playbackState() == QMediaPlayer::PlayingState)
        {
            sound->setPosition(0);
        }
        else if (sound->playbackState() == QMediaPlayer::StoppedState)
        {
            sound->play();
        }
    }
    // else if (event->key() == Qt::Key_Shift)
    // {
    //     S->setFixedSize(600,600);
    //     S->setWindowTitle("Shop");
    //     S->show();
    // }
    setPos(50+50*column,50+50*row);


}

void player::collision(){
    if (hp > 0 )
    {
    QList <QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for (int i = 0; i < n; i++){
        if (typeid(*(colliding_items[i])) == typeid(arrow))
        {
            health->DecreaseHealth(10);
            health->healthcolor();
            hp = health->getHealth();
            if(hp <= 0)
            {
                l.setFixedSize(600,315);
                l.setWindowTitle("The Pharaoh's Curse");
                l.show();
            }
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(fireball)){
            health->DecreaseHealth(15);
            health->healthcolor();
            hp = health->getHealth();
            if(hp <= 0)
            {
                l.setFixedSize(600,315);
                l.setWindowTitle("The Pharaoh's curse");
                l.show();
            }
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
    }
        if (typeid(*(colliding_items[i])) == typeid(boss)){
            health->DecreaseHealth(20);
            health->healthcolor();
            hp = health->getHealth();
            if(hp <= 0)
            {
                l.setFixedSize(600,315);
                l.setWindowTitle("The Pharaoh's curse");
                l.show();
            }
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(poisonball))
        {
            health->DecreaseHealth(20);
            health->healthcolor();
            hp = health->getHealth();
            if(hp <= 0)
            {
                l.setFixedSize(600,315);
                l.setWindowTitle("The Pharaoh's curse");
                l.show();
            }
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            return;
}
}
}
}
void player::checkRoom1(){
    if (enemy1::count1 <= 0){
        for (int i = 0; i < 28; i++){
            for (int j = 0; j < 28; j++){
                if (data[i][j] == 2){
                    data[i][j] = 5;
                    return;
                }
            }
        }
    }
    else{
        return;
    }
}

void player::checkRoom2(){
    if (enemy2::count1 <= 0){
        for (int i = 0; i < 28; i++){
            for (int j = 0; j < 28; j++){
                if (data[i][j] == 3){
                    data[i][j] = 5;
                    return;
                }
            }
        }
    }
    else{
        return;
    }
}

void player::checkRoom3()
{
    if (enemy1::count2 <= 0 && enemy2::count2 <=0){
        for (int i = 0; i < 28; i++){
            for (int j = 0; j < 11; j++){
                if (data[i][j] == 4){
                    data[i][j] = 5;
                    return;
                }
            }
        }
    }
    else{
        return;
    }
}

int player::getrow()
{
    return this->row;
}

int player::getcol()
{
    return column;
}



