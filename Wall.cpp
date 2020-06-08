
#include "Igrac.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include "Wall.h"

Wall::Wall()
{
    pen.setBrush(Qt::NoBrush);
    setPen(pen);
    setBrush(Qt::darkBlue);
    setAcceptDrops(true);
    setAcceptHoverEvents(true);
}
