#include "Hrana.h"
#include "Igra.h"
#include <QList>
#include <QDebug>
#include <QTimer>
#include "Ghost.h"
#include <QGraphicsPixmapItem>

Hrana::Hrana(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/Slike/Krug.png"));
}
