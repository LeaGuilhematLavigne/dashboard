#ifndef QUATRE_VOYANTS_H
#define QUATRE_VOYANTS_H
#include <QString>
#include <QGraphicsItem>
#include <QRectF>

class Quatre_Voyants : public QGraphicsItem
{
public:
    Quatre_Voyants(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString chemin, chemin2, chemin3;
    int x,y,on=0;
    void setSize(int, int);
    QSize taille1;
    QSize taille2;
    virtual void parametrage(int param_x,int param_y, QString param_chemin,QString param_chemin2,QString param_chemin3 );
};

#endif // QUATRE_VOYANTS_H
