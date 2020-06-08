#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include <QColor>
#include "Gumb.h"
#include <QBrush>
#include "Igra.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "Wall.h"
#include "Ghost.h"
#include <QGraphicsRectItem>
#include <QObject>
#include "Ghost2.h"
#include "Hrana.h"
#include "Points.h"
#include <QGraphicsView>
#include <QMediaPlayer>
QMediaPlayer * PacmanMrtav = new QMediaPlayer();
QMediaPlayer * muzika = new QMediaPlayer();

Igra::Igra(QWidget *parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    setScene(scene);
}

void Igra::start(){
    scene->clear();


        setBackgroundBrush(QBrush(QImage(":/Slike/background.jpg")));


    // zidovi
       Wall * wall_gore = new Wall();
       wall_gore->setRect(0,0,800,50);

       Wall * wall_livo = new Wall();
       wall_livo->setRect(0,0,50,600);

       Wall * wall_desno = new Wall();
       wall_desno->setRect(750,0,50,600);

       Wall * wall_dole = new Wall();
       wall_dole->setRect(0,550,800,50);

       Wall * wall_sredina_gore = new Wall();
       wall_sredina_gore->setRect(375,-25,50,125);

       Wall * wall_sredina_dole = new Wall();
       wall_sredina_dole->setRect(375,500,50,125);

       Wall * wall_sredina1 = new Wall();
       wall_sredina1->setRect(300,200,200,50);

       Wall * wall_sredina2 = new Wall();
       wall_sredina2->setRect(300,350,200,50);

       Wall * wall_L_1 = new Wall();
       wall_L_1->setRect(150,150,25,100);

       Wall * wall_L_2 = new Wall();
       wall_L_2->setRect(150,350,25,100);

       Wall * wall_D_1 = new Wall();
       wall_D_1->setRect(620,350,25,100);

       Wall * wall_D_2 = new Wall();
       wall_D_2->setRect(620,150,25,100);

       // pekman
       igrac = new Igrac();
        // change the rect from 0x0 (default) to 100x100 pixels
       igrac->setPos(375,275);

       // tockice koje pekmen skuplja okomito skroz lijevo
        Hrana *rect1 = new Hrana();
        rect1->setPos(100,90);

        Hrana *rect2 = new Hrana();
        rect2->setPos(100,165);

        Hrana *rect3 = new Hrana();
        rect3->setPos(100,240);

        Hrana *rect4 = new Hrana();
        rect4->setPos(100,315);

        Hrana *rect5 = new Hrana();
        rect5->setPos(100,390);

        Hrana *rect6 = new Hrana();
        rect6->setPos(100,465);

        //tockice koje pekmen skuplja vodoravno skroz gore

        Hrana *rect7 = new Hrana();
        rect7->setPos(175,90);

        Hrana *rect8 = new Hrana();
        rect8->setPos(250,90);

        Hrana *rect9 = new Hrana();
        rect9->setPos(325,90);

        Hrana *rect10 = new Hrana();
        rect10->setPos(475,90);

        Hrana *rect11 = new Hrana();
        rect11->setPos(550,90);

        Hrana *rect12 = new Hrana();
        rect12->setPos(625,90);

        Hrana *rect13 = new Hrana();
        rect13->setPos(700,90);

        //tockice koje pekmen skuplja okomito drugi red slijeva

        Hrana *rect14 = new Hrana();
        rect14->setPos(225,165);

        Hrana *rect15 = new Hrana();
        rect15->setPos(225,240);

        Hrana *rect16 = new Hrana();
        rect16->setPos(225,315);

        Hrana *rect17 = new Hrana();
        rect17->setPos(225,390);

        Hrana *rect18 = new Hrana();
        rect18->setPos(225,465);

       //tockice koje pekmen skuplja vodoravno drugi red odozgo

        Hrana *rect19 = new Hrana();
        rect19->setPos(550,165);

        Hrana *rect20 = new Hrana();
        rect20->setPos(700,165);

        //tockice koje pekmen skuplja vodoravno treci red

        Hrana *rect21 = new Hrana();
        rect21->setPos(300,290);

        /*Hrana *rect22 = new Hrana();
        rect22->setRect(390,290,25,25);*/

        Hrana *rect23 = new Hrana();
        rect23->setPos(475,290);

        //tockice koje pekmen skuplja okomito treci red

        Hrana *rect24 = new Hrana();
        rect24->setPos(550,240);

        Hrana *rect25 = new Hrana();
        rect25->setPos(550,315);

        Hrana *rect26 = new Hrana();
        rect26->setPos(550,390);

        Hrana *rect27 = new Hrana();
        rect27->setPos(550,465);

        //tockice koje pekmen skuplja okomito cetvrti red

        Hrana *rect28 = new Hrana();
        rect28->setPos(700,240);

        Hrana *rect29 = new Hrana();
        rect29->setPos(700,315);

        Hrana *rect30 = new Hrana();
        rect30->setPos(700,390);

        Hrana *rect31 = new Hrana();
        rect31->setPos(700,465);

        //tockice koje pekmen skuplja vodoravno zadnji red

        Hrana *rect32 = new Hrana();
        rect32->setPos(325,465);

        Hrana *rect33 = new Hrana();
        rect33->setPos(475,465);

        //Ghost -
        Ghost2 * enemy_2 = new Ghost2();
        enemy_2->setPos(375,117);

        Ghost * enemy_1 = new Ghost();
        enemy_1->setPos(375,417);


       // dodaj points
        points = new Points();
        scene->addItem(points);


        igrac->setFlag(QGraphicsItem::ItemIsFocusable);
        igrac->setFocus();


       // dodaj pekmena
       scene->addItem(wall_gore);
       scene->addItem(wall_sredina_gore);
       scene->addItem(wall_sredina1);
       scene->addItem(wall_L_1);
       scene->addItem(enemy_1);
       scene->addItem(enemy_2);
       scene->addItem(wall_L_2);
       scene->addItem(wall_D_1);
       scene->addItem(wall_D_2);
       scene->addItem(wall_sredina2);
       scene->addItem(wall_sredina_dole);
       scene->addItem(wall_desno);
       scene->addItem(wall_livo);
       scene->addItem(wall_dole);
       scene->addItem(igrac);
       scene->addItem(rect1);
       scene->addItem(rect2);
       scene->addItem(rect3);
       scene->addItem(rect4);
       scene->addItem(rect5);
       scene->addItem(rect6);
       scene->addItem(rect7);
       scene->addItem(rect8);
       scene->addItem(rect9);
       scene->addItem(rect10);
       scene->addItem(rect11);
       scene->addItem(rect12);
       scene->addItem(rect13);
       scene->addItem(rect14);
       scene->addItem(rect15);
       scene->addItem(rect16);
       scene->addItem(rect17);
       scene->addItem(rect18);
       scene->addItem(rect19);
       scene->addItem(rect20);
       scene->addItem(rect21);
       //scene->addItem(rect22);
       scene->addItem(rect23);
       scene->addItem(rect24);
       scene->addItem(rect25);
       scene->addItem(rect26);
       scene->addItem(rect27);
       scene->addItem(rect28);
       scene->addItem(rect29);
       scene->addItem(rect30);
       scene->addItem(rect31);
       scene->addItem(rect32);
       scene->addItem(rect33);

       //muzika pozadina
       muzika->setMedia(QUrl("qrc:/Zvukovi/PacmanOriginal.mp3"));
       muzika->setVolume(1);
       muzika->play();


    connect(enemy_1,SIGNAL(dead()),this,SLOT(gameOver()));
    connect(enemy_2,SIGNAL(dead()),this,SLOT(gameOver()));
    connect(points,SIGNAL(victory()),this,SLOT(gameOver()));



}

void Igra::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}



void Igra::displayMainMenu(){

    setBackgroundBrush(QBrush(QImage(":/Slike/Main.jpg")));

    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Pac - Man"));
    QFont titleFont("arial rounded mt bold",50);
    QColor titleColor("white");
    titleText->setDefaultTextColor(titleColor);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    QGraphicsTextItem* Company = new QGraphicsTextItem(QString("Zebo & Keva"));
    QFont companyFont("arial rounded mt bold",25);
    QColor companyColor("white");
    Company->setDefaultTextColor(companyColor);
    Company->setFont(companyFont);
    int cxPos = 560;
    int cyPos = 560;
    Company->setPos(cxPos,cyPos);
    scene->addItem(Company);

    Gumb* playGumb = new Gumb(QString("Start"));
    int bxPos = 300;
    int byPos = 225;
    playGumb->setPos(bxPos,byPos);
    connect(playGumb,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playGumb);

    Gumb* quitGumb = new Gumb(QString("Quit"));
    int qxPos = 300;
    int qyPos = 375;
    quitGumb->setPos(qxPos,qyPos);
    connect(quitGumb,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitGumb);
}

void Igra::gameOver(){

    QString message;
    displayGameOverWindow(message);
    PacmanMrtav->setMedia(QUrl("qrc:/Zvukovi/PacmanUmre.mp3"));
    PacmanMrtav->play();
    muzika->stop();
}

void Igra::displayGameOverWindow(QString textToDisplay){

     scene->clear();


    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Menu"));
    QFont titleFont("arial rounded mt bold",50);
    QColor titleColor("white");
    titleText->setDefaultTextColor(titleColor);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);



    Gumb* quit = new Gumb(QString("Quit"));
    int qxPos = this->width()/2 - quit->boundingRect().width()/2;
    int qyPos = 350;
    quit->setPos(qxPos, qyPos);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));


    QGraphicsTextItem* overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(460,225);
    scene->addItem(overText);
}

// muzika u pozadini


