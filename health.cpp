#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    health = 100;
}

void Health::DecreaseHealth(int num){
    health -= num;
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::IncreaseHealth(int num)
{
    health += num;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}

void Health::healthcolor()
{
    if (health > 50)
    {
        setPlainText(QString("Health: ") + QString::number(health));
        setDefaultTextColor(Qt::green);
        setFont(QFont("times",20));
    }
    if (health > 20 && health <= 50)
    {
        setPlainText(QString("Health: ") + QString::number(health));
        setDefaultTextColor(Qt::yellow);
        setFont(QFont("times",20));
    }
    if (health <= 20)
    {
        setPlainText(QString("Health: ") + QString::number(health));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",20));
    }
}
