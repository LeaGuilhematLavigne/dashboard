#include "deux_voyants.h"
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

deux_voyants::deux_voyants(QGraphicsItem *parent) :
    QGraphicsItem(parent)
{

}

QRectF deux_voyants::boundingRect() const
{
    QRectF rectf(0,0,800,500);

    return rectf;
}

void deux_voyants::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (on==1)
  {   QPixmap voyant (chemin);
    QPixmap voyant2= voyant.scaled(taille1);
    painter->drawPixmap(x,y,voyant2);
  }
    else if (on==2)
    {
        QPixmap voyant (chemin2);
        QPixmap voyant2 = voyant.scaled(taille1);
        painter->drawPixmap(x,y,voyant2);
    }
    else
    {
        QPen pen;
        QBrush brush;
        pen.setColor(Qt::transparent);
        brush.setColor(Qt::transparent);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawRect(x,y,30,30);
    }
}

void deux_voyants::setSize(int w, int h)
{
    taille1=QSize(w,h);
}

void deux_voyants::parametrage(int param_x, int param_y, QString param_chemin, QString param_chemin2)
{
    x=param_x;
    y=param_y;
    chemin=param_chemin;
    chemin2=param_chemin2;
}
