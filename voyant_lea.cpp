#include "voyant_lea.h"
#include <iostream>
#include <vector>
#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QtMath>
#include <QtDebug>
#include <QPointF>
#include <QPixmap>

voyant_Lea::voyant_Lea(QGraphicsItem *parent) :
    QGraphicsItem(parent)
{

}

QRectF voyant_Lea::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}

void voyant_Lea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (on==0)
  {   QPixmap voyant (chemin);
    QPixmap voyant2= voyant.scaled(taille1);
    painter->drawPixmap(x,y,voyant2);
  }
    else if (on==1)
    {
        QPixmap voyant (chemin2);
        QPixmap voyant2 = voyant.scaled(taille1);
        painter->drawPixmap(x,y,voyant2);
    }

}

void voyant_Lea::setSize(int w, int h)
{
   taille1=QSize(w,h);

}

void voyant_Lea::parametrage(int param_x, int param_y, QString param_chemin, QString param_chemin2)
{
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    chemin2=param_chemin2;



}
