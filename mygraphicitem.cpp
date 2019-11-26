#include "mygraphicitem.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>

mygraphicItem::mygraphicItem(QGraphicsItem *parent):
    QGraphicsItem(parent)
{

}

QRectF mygraphicItem::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}

void mygraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    int v;
    if (v1>=0 && v1 <=270) {v=v1;}
    else if (v1<0) {v=0;}
    else {v=270;}
    QPen pen;
    QBrush brush(Qt::SolidPattern);
    brush.setColor(Qt::black);
    painter->fillRect(this->boundingRect(),brush);
    xc=400.0;
    yc=200.0;
    double c=cos((225-v)*pi/180);       //calcul le cos et sin de l'angle formé
    double s=sin((225-v)*pi/180);

    xpos=xc+160*c;      //position de la pointe de la fleche =xc (centre du cercle)+rayon du cercle (taille aiguille)*cos (angle formé)
    ypos=yc-160*s;      // "-" carle y part du haut vers le bas




    // Bloc draw traits compteur vitesse
    {   pen.setColor(Qt::white);

        for (int i=0;i<=270;i+=10) {
        i%20==0 ? pen.setWidth(25) : pen.setWidth(10) ;

            pen.setColor(Qt::white);
            if (i==220 || i==180 || i==140)
            {
                pen.setColor(Qt::red);
            }

            pen.setCapStyle(Qt::FlatCap);
            pen.setStyle(Qt::SolidLine);
            painter->setPen(pen);
            painter->drawArc(245,45,310,310,(i-45)*16,20);      //245= position x traits, 45 position y des traits,  320,320=taille du cercle, 20 epaisseur trait
            pen.setColor(Qt::white);
            painter->setPen(pen);
            painter->setRenderHint(QPainter::Antialiasing);
            QFont font("Bell",12, QFont::Bold);
            painter->setFont(font);

        if (i%20==0) painter->drawText(xc-15+130*cos((225-i)*pi/180),yc+8-130*sin((225-i)*pi/180),QString("%1").arg(i));

        }

    }

    //Bloc draw arc au dessus du compteur

    {
        QRadialGradient radial(QPointF(xc,yc),180);
        radial.setColorAt(0,Qt::transparent);
        radial.setColorAt(0.95,Qt::blue);
        radial.setColorAt(1,"b8faf5");
//        pen.setColor(Qt::blue);
//        pen.setWidth(5);
        painter->setPen(QPen(QBrush(radial),20,Qt::SolidLine,Qt::FlatCap));
        painter->drawArc(220,20,360,360,310*16,280*16);

    }

    //Bloc Fleche

    {painter->setRenderHint(QPainter::Antialiasing);
     pen.setWidth(1);
     pen.setColor(Qt::red);
     brush.setColor(Qt::red);
     pen.setJoinStyle(Qt::RoundJoin);
     painter->setPen(pen);
     painter->setBrush(brush);
     QPointF points[3] = {
           QPointF(xc-9*cos((225-v-90)*pi/180),yc+9*sin((225-v-90)*pi/180)),     //xc -9(taille rayon base aiguille)*cos (angle -90(angle droit aiguille))
           QPointF(xpos, ypos),
           QPointF(xc+9*cos((225-v-90)*pi/180),yc-9*sin((225-v-90)*pi/180))
            };

     painter->drawConvexPolygon(points, 3);
     }


    // draw black circle in the middle
    {
        pen.setColor(Qt::transparent);
        QLinearGradient linearGradie(QPointF(385, 185), QPointF(415, 215));
           linearGradie.setColorAt(0,"#9d0409" );
           linearGradie.setColorAt(1,Qt::red);
        QBrush brush9(linearGradie)  ;
        painter->setPen(pen);
        painter->setBrush(brush9);
        painter->drawEllipse(xc-20,yc-20,40,40);



    brush.setColor(Qt::black);
    QLinearGradient linearGradi(QPointF(415, 215), QPointF(385, 185));
       linearGradi.setColorAt(0, "#9d0409");
       linearGradi.setColorAt(1,"#5e0407");
    QBrush brush8(linearGradi)  ;
    painter->setPen(pen);
    painter->setBrush(brush8);
    painter->drawEllipse(xc-15,yc-15,30,30);

    }


    // Bloc jauge essence
    {
    painter->setRenderHint(QPainter::Antialiasing);
    pen.setColor(Qt::white);
    painter->setPen(pen);
    painter->drawRect(650,250,20,100);
    QLine line1(640,250,650,250), line2(640,270,650,270), line3(640,290,650,290),line4(640,310,650,310),line5(640,330,650,330),line6(640,350,650,350);

    painter->drawLine(line1);
    painter->drawLine(line2);
    painter->drawLine(line3);
    painter->drawLine(line4);
    painter->drawLine(line5);
    painter->drawLine(line6);
}



    // Bloc tours/minutue

 {  QRectF rect_tours_min (10,110,260,260);
    double xc2=140.0;
    double yc2=240.0;
    painter->setRenderHint(QPainter::Antialiasing);
//painter->drawRect(rect_tours_min);
    painter->drawArc(rect_tours_min,50*16,180*16);
    for (int i=0;i<=41;i++) {

        pen.setColor(Qt::white);
        pen.setWidth(2);
        painter->setPen(pen);
        if (i==0 || i==8 || i==15 || i==22 || i==29 || i==35 || i==41){
            pen.setWidth(4);
            pen.setColor(Qt::red);
            painter->setPen(pen);
            QRectF text_tours_min (20,120,200,220);
           // painter->drawRect(text_tours_min);
            pen.setColor(Qt::white);
            painter->setPen(pen);
            painter->drawText((xc2-10+(130-30)*(cos((230-(i*180/41))*pi/180))),(yc2+8-(130-30)*(sin((230-(i*180/41))*pi/180))),QString("%1").arg(i));

        }
        painter->drawLine((xc2+130*(cos((230-(i*180/41))*pi/180))),(yc2-130*(sin((230-(i*180/41))*pi/180))),(xc2+(130-10)*(cos((230-(i*180/41))*pi/180))),(yc2-(130-10)*(sin((230-(i*180/41))*pi/180))));

    }

    }


}
