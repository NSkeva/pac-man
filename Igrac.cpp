#include "Igrac.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsItem>
#include <QDebug>
#include <QTimer>
#include "Hrana.h"
#include "Igra.h"
#include <QMediaPlayer>
extern Igra * igra;




Igrac::Igrac(QGraphicsItem *parent)
{
    setPixmap(QPixmap(":/Slike/Pac.png"));
}

void Igrac::keyPressEvent(QKeyEvent *event)
{
        QList<QGraphicsItem *> colliding_items = collidingItems();
        for(int i=0, n=colliding_items.size(); i<n; ++i)
        {

             if(typeid(*(colliding_items[i])) == typeid(Hrana))
             {
                 igra->points->increase();
                 scene()->removeItem(colliding_items[i]);
                 delete colliding_items[i];
                 return;
             }
         }



        if (event->key() == Qt::Key_Left){
                if (pos().x() != 75 && (pos().x() != 675 || (pos().y() <= 75 || (pos().y() >=275 && pos().y() <=275) || pos().y() >=475))     &&   (pos().x() != 525 || (pos().y() <= 125 || (pos().y()>=275 && pos().y() <= 275) || pos().y() >=425))    &&     (pos().x() != 450 || pos().y() <= 425)     &&     (pos().x() != 450 || pos().y() >= 125)     &&      (pos().x() != 200 || (pos().y() <= 75 || (pos().y() >= 275 && pos().y() <= 275) || pos().y() >= 475)))
                {
                        setPos(x()-25,y());
                }
            }
            else if (event->key() == Qt::Key_Right){
                if (pos().x() != 675 && (pos().x() != 75 || (pos().y() <= 75 || (pos().y() >= 275 && pos().y() <= 275) || pos().y() >=475))     &&   (pos().x() != 225 || (pos().y() <= 125 || (pos().y()>=275 && pos().y() <= 275) || pos().y() >=425))       &&     (pos().x() != 300 || pos().y() >= 125)     &&     (pos().x() != 300 || pos().y() <= 425)     &&      ((pos().x() != 550 || (pos().y() <= 75 || (pos().y() >=275 && pos().y() <=275) || pos().y() >=475))))
                    setPos(x()+25,y());
            }
            else if (event->key() == Qt::Key_Up)
            {
                if(pos().y() > 75 && (pos().y() != 125 || (pos().x() == 75 || pos().x() == 200 || pos().x() == 225 || pos().x() == 250 || pos().x() == 275 || pos().x() == 300 || pos().x() == 450 || pos().x() == 475 || pos().x() == 500 || pos().x() == 525 || pos().x() == 550 || pos().x() == 675 || pos().x() == 700))      &      (pos().y() != 275 || (pos().x() == 75 || pos().x() == 200 || pos().x() == 225 || pos().x() == 525 || pos().x() == 550 || pos().x() == 675))        &&      (pos().y() != 425 || (pos().x() == 75 || pos().x() == 200 || pos().x() == 225 || pos().x() == 525 || pos().x() == 550 || pos().x() == 675))        &&      (pos().y() != 475 || (pos().x() == 75 || pos().x() == 200 || pos().x() == 225 || pos().x() == 250 || pos().x() == 275 || pos().x() == 300 || pos().x() == 325 || pos().x() == 350 || pos().x() == 375 || pos().x() == 400 || pos().x() == 425 || pos().x() == 450 || pos().x() == 475 || pos().x() == 500 || pos().x() == 525 || pos().x() == 550 || pos().x() == 675)))
                    setPos(x(),y()-25);
            }
            else if (event->key() == Qt::Key_Down)
            {
                if(pos().y() < 475 && (pos().y() != 425 || (pos().x() == 75 || pos().x() == 200 || pos().x() == 225 || pos().x() == 250 || pos().x() == 275 || pos().x() == 300 || pos().x() == 450 || pos().x() == 475 || pos().x() == 500 || pos().x() == 525 || pos().x() == 550 || pos().x() == 675 || pos().x() == 700))      &      (pos().y() != 275 || (pos().x() == 75 || pos().x() == 200 || pos().x() == 225 || pos().x() == 525 || pos().x() == 550 || pos().x() == 675))        &&      (pos().y() != 125 || (pos().x() == 75 || pos().x() == 200 || pos().x() == 225 || pos().x() == 525 || pos().x() == 550 || pos().x() == 675))        &&      (pos().y() != 75 || (pos().x() == 75 || pos().x() == 200 || pos().x() == 225 || pos().x() == 250 || pos().x() == 275 || pos().x() == 300 || pos().x() == 325 || pos().x() == 350 || pos().x() == 375 || pos().x() == 400 || pos().x() == 425 || pos().x() == 450 || pos().x() == 475 || pos().x() == 500 || pos().x() == 525 || pos().x() == 550 || pos().x() == 675)))
                    setPos(x(),y()+25);
            }
    //qDebug() << "X:" << pos().x() << "Y: " << pos().y();
}
