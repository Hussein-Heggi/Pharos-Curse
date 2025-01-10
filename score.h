#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent= 0);
    void IncreaseScore(int num);
    void DecreaseScore(int num);
    int getScore();
private:
    int score;
};

#endif // SCORE_H
