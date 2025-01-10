#include <QApplication>
#include <QBrush>
#include <QFile>
#include <QTextStream>
#include "loss.h"
#include "mainwindow.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QMediaPlayer>
#include "player.h"
#include "enemy1.h"
#include "enemy2.h"
#include "health.h"
#include "changemap.h"
#include "score.h"
#include "boss.h"


int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MainWindow w;
    w.setFixedSize(900,700);
    w.setWindowTitle("The Pharaoh's curse");
    QGraphicsScene scene; //creating a scene
    scene.setSceneRect(25,25,600,1500);
    QGraphicsView view; // creating the view

    //setting size and color of the window
    view.setFixedSize(600,600);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setWindowTitle("The Pharaoh's curse");
    QBrush brush(Qt::white);
    view.setBackgroundBrush(brush);


    // creating a file object
    QFile file("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Board.txt");
    file.open(QIODevice::ReadOnly);

    QFile Copyfile("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Board copy.txt");
    Copyfile.open(QIODevice::WriteOnly);

    // creating a text stream
    QTextStream stream(&file);
    int boarddata[28][11];
    // to read string from the file then convert it to int

    QTextStream Wstream(&Copyfile);
    QString temp, temp2;

    // Reading from the file
    for (int i=0;i<28;i++){
        for (int j=0;j<11;j++){
             stream>>temp;
             Wstream << temp << " ";
             boarddata[i][j]=temp.toInt();
        }
        Wstream << "\n";
    }
    Copyfile.close();

    QGraphicsPixmapItem dataimage[28][11];
    QPixmap floor("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Sand.jpeg");
    QPixmap wall("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/wall.jpeg");
    QPixmap Closeddoor ("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/block.png");


    floor=floor.scaledToWidth(50);
    floor=floor.scaledToHeight(50);

    wall=wall.scaledToWidth(50);
    wall=wall.scaledToHeight(50);

    Closeddoor=Closeddoor.scaledToWidth(50);
    Closeddoor=Closeddoor.scaledToHeight(50);


    for (int i=0;i<28;i++)
        for (int j=0;j<11;j++)
        {
            if(boarddata[i][j] == -1 || boarddata[i][j] == -2)
                dataimage[i][j].setPixmap(wall);
            else if (boarddata[i][j]> 5)
                dataimage[i][j].setPixmap(floor);
            else if (boarddata[i][j] == 2 || boarddata[i][j] == 3 || boarddata[i][j] == 4)
                dataimage[i][j].setPixmap(Closeddoor);
            else if (boarddata[i][j] == 05)
                dataimage[i][j].setPixmap(floor);
            dataimage[i][j].setPos(50+50*j,50+50*i);
            scene.addItem(&dataimage[i][j]);
        }


    player *p = new player(boarddata);
    scene.addItem(p);

    view.setSceneRect(0,0,1000000,1000000);
    view.centerOn(600,600);
    scene.addItem(p->health);
    scene.addItem(p->score);

    enemy1 e1(boarddata, 1,9,1,p);
    scene.addItem(&e1);

//    enemy1 e2(boarddata, 1,4,1,p);
//    scene.addItem(&e2);

    enemy2 e3(boarddata, 8,4,2,p);
    scene.addItem(&e3);

    //enemy2 e4(boarddata, 12,5,2 ,p);
    //scene.addItem(&e4);

    enemy1 e5(boarddata, 17,4,3,p);
    scene.addItem(&e5);

    enemy2 e6(boarddata, 20,5,3,p);
    scene.addItem(&e6);

    enemy2 e7(boarddata, 19,6,3,p);
    scene.addItem(&e7);

    //enemy1 e8(boarddata, 16,7,3,p);
    //scene.addItem(&e8);

    boss B(boarddata,p);
    scene.addItem(&B);



    view.setScene(&scene);
    view.show();


    w.show();
    p->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    p->setFocus();
    return a.exec();
}
