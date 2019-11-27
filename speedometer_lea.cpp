#include "speedometer_lea.h"
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>


speedometer_Lea::speedometer_Lea(QGraphicsItem *parent) :
     QGraphicsItem(parent)
{

}

QRectF speedometer_Lea::boundingRect() const
{
    QRectF rectf(0,0,800,500);
    return rectf;
}

void speedometer_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
        for (int i=0;i<=vitesse_max;i+=10)
        {
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


//            {

//            pen.setColor(Qt::green);
//            pen.setWidth(2);
//            painter->setPen(pen);
//            QRectF rect_vitesse (x-r,y-r,r*2,r*2);
//            painter->drawArc(rect_vitesse,angle_debut*16,angle_fin*16);
//            pen.setColor(Qt::red);
//            painter->setPen(pen);
//            painter->drawLine((x+r*(cos((angle_debut-(i*span_angle/nb_graduation))*pi/180))),(y-r*(sin((angle_debut-(i*span_angle/nb_graduation))*pi/180))),(x+(r-10)*(cos((angle_debut-(i*span_angle/nb_graduation))*pi/180))),(y-(r-10)*(sin((angle_debut-(i*span_angle/nb_graduation))*pi/180))));


//            }

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
        painter->setPen(QPen(QBrush(radial),20,Qt::SolidLine,Qt::FlatCap));
        painter->drawArc(220,20,360,360,310*16,280*16);
    }
}

void speedometer_Lea::parametrage(double param_x, double param_y, double param_r, int param_start, int param_end, int param_spanAngle, int param_graduation, int param_vitMax)
{

    x= param_x;
    y=param_y;
    r=param_r;
    angle_debut=param_start;
    angle_fin = param_end;
    nb_graduation = param_graduation;
    span_angle=param_spanAngle;
    vitesse_max=param_vitMax;


}
