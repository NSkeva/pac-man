#ifndef IGRA_H
#define IGRA_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Igrac.h"
#include "Points.h"

class Igra: public QGraphicsView{
    Q_OBJECT
public:
    Igra(QWidget * parent=NULL);

    void displayMainMenu();
    void displayGameOverWindow(QString textToDisplay);

    QGraphicsScene * scene;
    Igrac * igrac;
    Points * points;

public slots:
    void start();
    void gameOver();

private:
     void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
};


#endif // IGRA_H
