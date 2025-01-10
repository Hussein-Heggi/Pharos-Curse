#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent= 0);
    void DecreaseHealth(int num);
    void IncreaseHealth(int num);
    int getHealth();
    void healthcolor();
private:
    int health;
};

#endif // HEALTH_H
