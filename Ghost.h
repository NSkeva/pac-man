#ifndef GHOST_H
#define GHOST_H
#include <QGraphicsPixmapItem>
#include <QObject>

class Ghost: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
   Ghost();
public slots:
    void move();
signals:
    void dead();
};
#endif // GHOST_H
