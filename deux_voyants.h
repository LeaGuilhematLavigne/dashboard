#ifndef DEUX_VOYANTS_H
#define DEUX_VOYANTS_H
#include <QString>
#include <QGraphicsItem>
#include <QRectF>

class deux_voyants : public QGraphicsItem
{
public:
    deux_voyants(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString chemin, chemin2;
    int x,y,on=0;
    void setSize(int, int);
    QSize taille1;
    QSize taille2;
    virtual void parametrage(int param_x,int param_y, QString param_chemin,QString param_chemin2);

};

#endif // DEUX_VOYANTS_H
