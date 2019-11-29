#ifndef TACHOMETERGAUGE_LEA_H
#define TACHOMETERGAUGE_LEA_H
#include <QGraphicsItem>
#include <QRectF>

class TachometerGauge_Lea : public QGraphicsItem
{
public:
    TachometerGauge_Lea(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double r;
    double x;
    double y;
    int angle_debut;
    int angle_fin;
    int nb_graduation=41;
    int span_angle;
    int vitesse_max=270;
    int value;
    const double pi=3.14159265359;
    int getValueMax();
    void setValue(int);

    virtual void parametrage(double param_x,double param_y, double param_r,int param_start, int param_end, int param_spanAngle, int param_graduation, int param_vitMax );


};

#endif // TACHOMETERGAUGE_LEA_H
