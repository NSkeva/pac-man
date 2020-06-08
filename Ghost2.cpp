#include "Ghost2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Igra.h"
#include <QDebug>
char smjer2 = 'l';
// d= desno D = dolje
QTimer * timer2 = new QTimer();
// connect
Ghost2::Ghost2(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/Slike/Ghost2.png"));
    connect(timer2,SIGNAL(timeout()),this,SLOT(move()));
    timer2->start(150);

}
void Ghost2::move(){
    // pomjeranje neprijatelja u smjeru
    if(smjer2 == 'd')
    {
     setPos(x()+25,y());
    }
    if(smjer2 == 'l')
    {
        setPos(x()-25,y());
    }
    if(smjer2 == 'D')
    {
      setPos(x(),y()+25);
    }
    if(smjer2 == 'g')
    {
        setPos(x(),y()-25);
    }



    // Promjene smjera
    if(pos().x()==200 && smjer2 == 'l')
    {
        smjer2 = 'g';
    }
    if(pos().x()==200 && pos().y()==67)
    {
        smjer2 = 'l';
    }
    if(pos().x()==75 && pos().y()==67)
    {
        smjer2 = 'D';
    }
    if(pos().x()==75 && pos().y()==467)
    {
        smjer2 = 'd';
    }
    if(pos().x()==200 && pos().y()==467)
    {
        smjer2 = 'g';
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

    qDebug() << "x:  " <<  pos().x() << "y: " << pos().y();

}



/*Ghost * enemy_2 = new Ghost();
enemy_2->setRect(375,417,70,70);*/

/*setPos(x(),y()+5);
if (pos().y() + rect().height() < 0)
{
    scene()->removeItem(this);
    delete this;
}*/
