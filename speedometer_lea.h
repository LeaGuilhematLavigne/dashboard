#ifndef SPEEDOMETER_LEA_H
#define SPEEDOMETER_LEA_H
#include <QGraphicsItem>
#include <QRectF>

class speedometer_Lea : public QGraphicsItem
{
public:
    speedometer_Lea(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    double xpos;
    double ypos;
    double xc;
    double yc;
    int v1; //vitesse
    const double pi=3.14159265359;

    double x;
    double y;
    double r;
    int angle_debut;
    int angle_fin;
    int span_angle;
    int vitesse_max=270;
    virtual void parametrage(double param_x,double param_y, double param_r,int param_start, int param_end, int param_spanAngle, int param_graduation, int param_vitMax );
    int nb_graduation =28;



};

#endif // SPEEDOMETER_LEA_H
