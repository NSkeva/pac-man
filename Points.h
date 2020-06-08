#ifndef POINTS_H
#define POINTS_H

#include <QGraphicsTextItem>
#include <QObject>

class Points: public QGraphicsTextItem
{
    Q_OBJECT
public:
    Points(QGraphicsItem * parent=0);
    void increase();
    int getPoints();
    int points;
public slots:
    void vici();
signals:
    void victory();
};

#endif // POINTS_H
