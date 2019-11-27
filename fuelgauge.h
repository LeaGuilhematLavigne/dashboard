#ifndef FUELGAUGE_H
#define FUELGAUGE_H
#include <QGraphicsItem>
#include <QRectF>


class FuelGauge : public QGraphicsItem
{
public:
    FuelGauge(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setValue(int);
    double x;
    double y;
    double x2;
    double y2;
    double x3;
    double y3;
    double width;
    double height;

    int value;
    virtual void parametrage(double param_x, double param_y, double param_width, double param_height, double param_x2, double param_y2, double param_x3, double param_y3);
};

#endif // FUELGAUGE_H
