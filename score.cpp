#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",20));

}

void Score::IncreaseScore(int num){
    score += num;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::DecreaseScore(int num)
{
    score -= num;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore(){
    return score;
}
