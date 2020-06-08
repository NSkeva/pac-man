#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

class Igrac:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Igrac (QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
private:
    QMediaPlayer * jedeZvuk;

};

#endif // MYRECT_H
