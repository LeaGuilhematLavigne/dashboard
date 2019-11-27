#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mygraphicitem.h"
#include "speedometer_lea.h"
#include "tachometergauge_lea.h"
#include "fuelgauge.h"
#include "voyant_lea.h"
#include "aiguille_lea.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QGraphicsView *view = new QGraphicsView();
    QGraphicsScene *scene = new QGraphicsScene ();
    mygraphicItem *myitem = new mygraphicItem ();
    speedometer_Lea *compteur_vitesse = new speedometer_Lea;
    TachometerGauge_Lea *tours_minute = new TachometerGauge_Lea;
    FuelGauge *essence = new FuelGauge;
    voyant_Lea *fuel = new voyant_Lea;


    ~MainWindow();

public slots :
    void Scene();
    void vitesse();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
