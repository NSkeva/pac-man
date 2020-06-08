#include "Ghost.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Igra.h"
#include <QDebug>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
char smjer = 'd';
// d= desno D = dolje
QTimer * timer = new QTimer();
// connect
Ghost::Ghost(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/Slike/Ghost.png"));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(150);

}
void Ghost::move()
{
    // pomjeranje neprijatelja u smjeru
    if(smjer == 'd')
    {
     setPos(x()+25,y());
    }
    if(smjer == 'l')
    {
        setPos(x()-25,y());
    }
    if(smjer == 'D')
    {
      setPos(x(),y()+25);
    }
    if(smjer == 'g')
    {
        setPos(x(),y()-25);
    }



    // Promjene smjera
    if(pos().x()==525 && smjer == 'd')
    {
        smjer = 'D';
    }
    if(pos().y()==467 )
    {
        smjer = 'd';
    }
    if(pos().x()==675)
    {
        smjer = 'g';
    }
    if(pos().y()==67)
    {
        smjer = 'l';
    }
    if(pos().x()==525 && pos().y()==67)
    {
        smjer = 'D';
    }

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i)
    {

         if(typeid(*(colliding_items[i])) == typeid(Igrac))
         {
             emit dead();
             return;
         }
     }

    //qDebug() << "x:  " <<  pos().x() << "y: " << pos().y();

}

