#include "tachometergauge_lea.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>


TachometerGauge_Lea::TachometerGauge_Lea(QGraphicsItem *parent) :
    QGraphicsItem(parent)
{

}

QRectF TachometerGauge_Lea::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}

void TachometerGauge_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPen pen;
    QBrush brush(Qt::SolidPattern);
    QRectF rect_tours_min (x-r,y-r,r*2,r*2);
    pen.setColor(Qt::black);
    painter->setPen(pen);
       painter->setRenderHint(QPainter::Antialiasing);
       painter->drawArc(rect_tours_min,angle_debut*16,angle_fin*16);
       for (int i=0;i<=41;i++)
       {
            int j;
           pen.setColor(Qt::white);
           pen.setWidth(2);
           painter->setPen(pen);
           if (i==0 || i==8 || i==15 || i==22 || i==29 || i==35 || i==41)
           {
               i==41 ? (j=i+1) : (j=i);                                        //i+1 quand on arrive a 41 pour pouvoir avoir 6 quand on le divise par 7
               pen.setWidth(4);
               pen.setColor(Qt::white);
               painter->setPen(pen);
               painter->drawText((x-10+(r-30)*(cos((angle_debut-(i*span_angle/41))*pi/180))),(y+8-(r-30)*(sin((angle_debut-(i*span_angle/41))*pi/180))),QString("%1").arg(j/7));
               pen.setColor(Qt::red);
               painter->setPen(pen);

           }
           painter->drawLine((x+r*(cos((angle_debut-(i*span_angle/41))*pi/180))),(y-r*(sin((angle_debut-(i*span_angle/41))*pi/180))),(x+(r-10)*(cos((angle_debut-(i*span_angle/41))*pi/180))),(y-(r-10)*(sin((angle_debut-(i*span_angle/41))*pi/180))));
       }
}

void TachometerGauge_Lea::parametrage(double param_x, double param_y, double param_r, int param_start, int param_end, int param_spanAngle)
{
    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    angle_fin = param_end;

    span_angle=param_spanAngle;

}
