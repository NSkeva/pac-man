#ifndef GHOST2_H
#define GHOST2_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Ghost2: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
   Ghost2();
public slots:
    void move();
signals:
    void dead();
};

#endif // GHOST2_H
