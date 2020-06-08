#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsView>

class Wall:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Wall();
private:
    QPen pen;

};

#endif // WALL_H
