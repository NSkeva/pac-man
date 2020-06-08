#include "Points.h"
#include <QFont>
#include <QTimer>
#include <QMediaPlayer>
QTimer * timer4 = new QTimer();
QMediaPlayer * jedeZvuk = new QMediaPlayer();
Points::Points(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    points = 0;
    setPlainText(QString("Points: ") + QString::number(points));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
}

void Points::increase(){
    points++;
    setPlainText(QString("Points: ")+ QString::number(points));

    jedeZvuk->setMedia(QUrl("qrc:/Zvukovi/PacmanJede.mp3"));
    jedeZvuk->play();
    if(points==32)
    {

        connect(timer4,SIGNAL(timeout()),this,SLOT(vici()));
        timer4->start(200);
    }
}
void Points:: vici()
{

    emit victory();
    timer4->stop();
}
int Points::getPoints(){
    return points;
}
