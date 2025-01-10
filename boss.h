#ifndef BOSS_H
#define BOSS_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <player.h>
#include <QTimer>
#include <QStack>
#include <ctime>
#include "player.h"
#include "win.h"
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

#define ROW 28
#define COL 11

const int MAX = 10000;
// Creating a shortcut for int, int pair type
typedef std::pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
typedef std::pair<double, std::pair<int, int> > pPair;

// A structure to hold the necessary parameters
struct cell {
    // Row and Column index of its parent
    // Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
    int parent_i, parent_j;
    // f = g + h
    double f, g, h;
};

class boss: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Pair Is;
    Pair It;
    int rh,ch;
    int dir;
    int row;
    int column;
    int data[ROW][COL];
    int health = 200;
    int playerrow = ptr->getrow();
    int playercol = ptr->getcol();
    Pair src = std::make_pair(row, column);
    Pair dest = std::make_pair(ptr->getrow(), ptr->getcol());
    player *ptr;
    Win W;
    QStack<Pair> Pathfinal;
    QStack<Pair> tem;
public:
    boss(int [ROW][COL], player *a);
    bool isValid(int row, int col);
    bool isUnBlocked(int grid[][COL], int row, int col);
    bool isDestination(int row, int col, Pair dest);
    double calculateHValue(int row, int col, Pair dest);
    void tracePath(cell cellDetails[][COL], Pair dest);
    void aStarSearch(int grid[][COL], Pair src, Pair dest);
    void Decreasehealth(int num);
    int Gethealth();
    void check();
//    void move();
public slots:
    void move();
    void find();
    void attack();
    void collision();
    void Defeated();
    void Spawn();
};
#endif // BOSS_H
