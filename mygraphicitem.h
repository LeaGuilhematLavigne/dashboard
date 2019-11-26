#ifndef MYGRAPHICITEM_H
#define MYGRAPHICITEM_H
#include <QGraphicsItem>
#include <QRectF>

class mygraphicItem: public QGraphicsItem
{
public:
    mygraphicItem(QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
   double xpos;
   double ypos;
   double xc;
   double yc;
   int v1; //vitesse
   const double pi=3.14159265359;


   int x =0,y=0,r=100,start_angle=0,end_angle=360, number_graduation=12,critique;
   QColor color=QColor(100,100,100);
   QColor color2=QColor(100,100,100);
   QStringList graduations;
   int angle =0;

};

#endif // MYGRAPHICITEM_H
