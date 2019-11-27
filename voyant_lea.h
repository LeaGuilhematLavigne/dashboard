#ifndef VOYANT_LEA_H
#define VOYANT_LEA_H
#include <QString>
#include <QGraphicsItem>
#include <QRectF>

class voyant_Lea: public QGraphicsItem
{
public:
    voyant_Lea(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QString chemin, chemin2;
    int x,y,on=0;
    void setSize(int, int);
    QSize taille1;
    QSize taille2;
    virtual void parametrage(int param_x,int param_y, QString param_chemin,QString param_chemin2="vide");
};

#endif // VOYANT_LEA_H
