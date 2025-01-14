
#include "boss.h"
#include "QtWidgets/qapplication.h"
#include "bullet.h"
#include "poisonball.h"
#include "enemy2.h"
#include "enemy1.h"
#include <QDebug>
#include <QVector>
#include <ctime>



bool boss::isValid(int row, int col)
{
    // Returns true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) && (col >= 0)
           && (col < COL);
}
bool boss::isUnBlocked(int grid[][COL], int row, int col)
{
    // Returns true if the cell is not blocked else false
    if (grid[row][col] >= 0)

      {
      //  qDebug()<<grid[row][col];
        return (true);
      }
    else
    {
        //qDebug()<<grid[row][col];
        return (false);
    }
}
bool boss::isDestination(int row, int col, Pair dest)
{
    if (row == dest.first && col == dest.second)
        return (true);
    else
        return (false);
}
double boss::calculateHValue(int row, int col, Pair dest)
{
    // Return using the distance formula
    return ((double)sqrt(
        (row - dest.first) * (row - dest.first)
        + (col - dest.second) * (col - dest.second)));
}
void boss::tracePath(cell cellDetails[][COL], Pair dest)
{
   // qDebug()<<"here";
    //printf("\nThe Path is ");
    int ro = dest.first;
    int co = dest.second;

    QStack<Pair> Path;
    while (!(cellDetails[ro][co].parent_i == ro
             && cellDetails[ro][co].parent_j == co))
    {
        Path.push(std::make_pair(ro, co));
        int temp_row = cellDetails[ro][co].parent_i;
        int temp_col = cellDetails[ro][co].parent_j;
        ro = temp_row;
        co = temp_col;
    }

    Path.push(std::make_pair(ro, co));
    Pathfinal=Path;
    qDebug()<<Pathfinal.size()<<"before";
    while (!Path.empty()) {
        std::pair<int, int> p = Path.top();
        Path.pop();
        qDebug()<<"("<<p.first<< p.second<<")";
    }
   // qDebug()<<"here";
    return;
}
void boss::aStarSearch(int grid[][COL], Pair src, Pair dest)
{
    //Pathfinal.clear();
    //qDebug()<<"here1";
    // If the source is out of range
    if (isValid(src.first, src.second) == false)
    {
        qDebug()<<"Source is invalid\n";
        return;
    }

    // If the destination is out of range
    if (isValid(dest.first, dest.second) == false) {
        qDebug()<<"Destination is invalid\n";
        return;
    }

    // Either the source or the destination is blocked
    if (isUnBlocked(grid, src.first, src.second) == false
        || isUnBlocked(grid, dest.first, dest.second)
               == false) {
        qDebug()<<"Source or the destination is blocked\n";
        return;
    }

    // If the destination cell is the same as source cell
    if (isDestination(src.first, src.second, dest)
        == true) {
        qDebug()<<"We are already at the destination\n";
        return;
    }

    // Create a closed list and initialise it to false which
    // means that no cell has been included yet This closed
    // list is implemented as a boolean 2D array
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    // Declare a 2D array of structure to hold the details
    // of that cell
    cell cellDetails[ROW][COL];

    int i, j;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            cellDetails[i][j].f = MAX;
            cellDetails[i][j].g = MAX;
            cellDetails[i][j].h = MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    }

    // Initialising the parameters of the starting node
    i = src.first, j = src.second;
    cellDetails[i][j].f = 0.0;
    cellDetails[i][j].g = 0.0;
    cellDetails[i][j].h = 0.0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;
    qDebug()<<"here5";
    /*
     Create an open list having information as-
     <f, <i, j>>
     where f = g + h,
     and i, j are the row and column index of that cell
     Note that 0 <= i <= ROW-1 & 0 <= j <= COL-1
     This open list is implemented as a set of pair of
     pair.*/
    QSet<pPair> openList;

    // Put the starting cell on the open list and set its
    // 'f' as 0
    openList.insert(make_pair(0.0, std::make_pair(i, j)));

    // We set this boolean value as false as initially
    // the destination is not reached.
    bool foundDest = false;

    while (!openList.empty()) {
        pPair p = *openList.begin();

        // Remove this vertex from the open list
        openList.erase(openList.begin());

        // Add this vertex to the closed list
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true;

        /*
         Generating all the 8 successor of this cell

                   N   N.E
               \   |   /
                   |  /
             W----Cell----E
                  / | \
                /   |  \
             S.W    S   S.E

         Cell-->Popped Cell (i, j)
         N -->  North       (i-1, j)
         S -->  South       (i+1, j)
         E -->  East        (i, j+1)
         W -->  West           (i, j-1)*/

        // To store the 'g', 'h' and 'f' of the 8 successors
        double gNew, hNew, fNew;

        //----------- 1st Successor (North) ------------

        // Only process this cell if this is a valid one
        if (isValid(i - 1, j) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i - 1, j, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i - 1][j].parent_i = i;
                cellDetails[i - 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i - 1][j] == false
                     && isUnBlocked(grid, i - 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i - 1, j, dest);
                fNew = gNew + hNew;

                // If it isnâ€™t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i - 1][j].f == MAX
                    || cellDetails[i - 1][j].f > fNew) {
                    openList.insert(make_pair(
                        fNew, std::make_pair(i - 1, j)));

                    // Update the details of this cell
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                    row--;

                }
            }
        }

        //----------- 2nd Successor (South) ------------

        // Only process this cell if this is a valid one
        if (isValid(i + 1, j) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i + 1, j, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }
            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i + 1][j] == false
                     && isUnBlocked(grid, i + 1, j)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i + 1, j, dest);
                fNew = gNew + hNew;

                // If it isnâ€™t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i + 1][j].f == MAX
                    || cellDetails[i + 1][j].f > fNew) {
                    openList.insert(make_pair(
                        fNew, std::make_pair(i + 1, j)));
                    // Update the details of this cell
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                    row++;

                }
            }
        }

        //----------- 3rd Successor (East) ------------

        // Only process this cell if this is a valid one
        if (isValid(i, j + 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j + 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }

            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i][j + 1] == false
                     && isUnBlocked(grid, i, j + 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j + 1, dest);
                fNew = gNew + hNew;

                // If it isnâ€™t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i][j + 1].f == MAX
                    || cellDetails[i][j + 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, std::make_pair(i, j + 1)));

                    // Update the details of this cell
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                    column++;

                }
            }
        }

        //----------- 4th Successor (West) ------------

        // Only process this cell if this is a valid one
        if (isValid(i, j - 1) == true) {
            // If the destination cell is the same as the
            // current successor
            if (isDestination(i, j - 1, dest) == true) {
                // Set the Parent of the destination cell
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
                printf("The destination cell is found\n");
                tracePath(cellDetails, dest);
                foundDest = true;
                return;
            }

            // If the successor is already on the closed
            // list or if it is blocked, then ignore it.
            // Else do the following
            else if (closedList[i][j - 1] == false
                     && isUnBlocked(grid, i, j - 1)
                            == true) {
                gNew = cellDetails[i][j].g + 1.0;
                hNew = calculateHValue(i, j - 1, dest);
                fNew = gNew + hNew;

                // If it isnâ€™t on the open list, add it to
                // the open list. Make the current square
                // the parent of this square. Record the
                // f, g, and h costs of the square cell
                //                OR
                // If it is on the open list already, check
                // to see if this path to that square is
                // better, using 'f' cost as the measure.
                if (cellDetails[i][j - 1].f == MAX
                    || cellDetails[i][j - 1].f > fNew) {
                    openList.insert(make_pair(
                        fNew, std::make_pair(i, j - 1)));

                    // Update the details of this cell
                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                    column--;

                }
            }
        }

      }
    // When the destination cell is not found and the open
    // list is empty, then we conclude that we failed to
    // reach the destination cell. This may happen when the
    // there is no way to destination cell (due to
    // blockages)
    if (foundDest == false)
        qDebug()<<"Failed to find the Destination Cell\n";

   // qDebug()<<"end 0";

    return;
}

void boss::Decreasehealth(int num)
{
    health -= num;
}

int boss::Gethealth()
{
    return health;
}

void boss::check()
{

}
boss::boss(int boarddata[ROW][COL], player *ptr)
{
    row =26;
    column = 9;
    rh = 26;
    ch = 9;

    this->ptr = ptr;

    QPixmap p("/Users/s7s/Desktop/build-New_Project-Qt_6_3_0_for_macOS-Debug/Boss.png");
    p=p.scaledToWidth(50);
    p=p.scaledToHeight(50);
    setPixmap(p);
    setPos(50+column*50,50+row*50);
    for (int i=0;i<ROW;i++)
        for (int j=0;j<COL;j++)
        {
         data[i][j]=boarddata[i][j];
        }


    QTimer *findtimer = new QTimer();
    connect(findtimer, SIGNAL(timeout()), this, SLOT(find()));
    findtimer->start(500);

    QTimer *movetimer = new QTimer();
    connect(movetimer, SIGNAL(timeout()), this, SLOT(move()));
    movetimer->start(500);


    QTimer *collisiontimer = new QTimer();
    connect(collisiontimer, SIGNAL(timeout()),this,SLOT(collision()));
    collisiontimer->start(50);


     QTimer *attacktimer = new QTimer();
     connect(attacktimer,SIGNAL(timeout()),this,SLOT(attack()));
     attacktimer->start(1000);


     QTimer *defeated = new QTimer();
     connect(defeated,SIGNAL(timeout()),this,SLOT(Defeated()));
     defeated->start(50);

     QTimer *SpawnTimer = new QTimer();
     connect(SpawnTimer,SIGNAL(timeout()),this,SLOT(Spawn()));
     SpawnTimer->start(15000);
}
void  boss:: move()
{
    if (health > 0)
    {
        if (enemy1::count2 <= 0 && enemy2::count2 <=0)
        {



               if(Pathfinal.empty()==false)
               {
               Pair temp=Pathfinal.top();
               Pathfinal.pop();
               int ro=temp.first;
               int co=temp.second;
               qDebug()<<"still moving";
               qDebug()<<"((" <<ro<<","<<co<<"))";
               setPos(50+co*50,50+ro*50);
//
               }


        }
    }
}

void boss::find()
{
    if (health > 0)
    {
    src = std::make_pair(row, column);
    dest = std::make_pair(ptr->getrow(), ptr->getcol());
//    qDebug() << src;
//    qDebug() << dest;
    aStarSearch(data, src, dest);
}
}
void boss::attack()
{
    if (health > 0)
    {
        if (enemy1::count2 <= 0 && enemy2::count2 <=0)
        {
            poisonball *Poison = new poisonball(data,row,column);
            scene()->addItem(Poison);
        }

}}

void boss::collision()
{
    if (health > 0)
    {
    QList <QGraphicsItem *> colliding_items = collidingItems();
        int n = colliding_items.size();
        for (int i = 0; i < n; i++)
        {
            if (typeid(*(colliding_items[i])) == typeid(Bullet))
            {
                Decreasehealth(20);
                ptr->score->IncreaseScore(20);

                qDebug () << "enemy health" << health;
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                if (this->Gethealth() <= 0)
                {
                    scene()->removeItem(this);
                    return;
                }
                return;
            }

        }
}}

void boss::Defeated()
{
    if(health <= 0)
    {
        W.setFixedSize(640,640);
        W.setWindowTitle("The Pharaoh's Curse");
        W.show();
    }
}
void boss::Spawn(){
    //qDebug() << "row: " << row << "column" << column;
    enemy1 *e1;
    e1 = new enemy1(data,row, column, 4, ptr);
    scene()->addItem(e1);
    enemy2 *e2;
    e2 = new enemy2(data,row, column, 4, ptr);
    scene()->addItem(e2);

}


