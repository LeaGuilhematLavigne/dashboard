#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicitem.h"
#include "speedometer_lea.h"
#include "tachometergauge_lea.h"
#include "fuelgauge.h"
#include "voyant_lea.h"
#include "aiguille_lea.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalSlider->setValue(0);
    ui->verticalSlider->setMaximum(300);
    ui->verticalSlider->setMinimum(-20);
    ui->graphicsView->setBackgroundBrush(QBrush(Qt::black));

   connect(ui->verticalSlider,SIGNAL(actionTriggered(int)),this, SLOT(vitesse()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Scene()
{
    ui->graphicsView->setScene(scene);
//    myitem->v1 = ui->verticalSlider->value();
//    scene->addItem(myitem);

    //speedometer_Lea *compteur_vitesse = new speedometer_Lea;
    compteur_vitesse->v1 = ui->verticalSlider->value();
    scene->addItem(compteur_vitesse);


    fuel->parametrage(580,320,":/fuel.png",":/fuel2.png");
    fuel->setSize(30,30);
    fuel->on=1;
    scene->addItem(fuel);

    FuelGauge *GaugeEssence= new FuelGauge;
    GaugeEssence->parametrage(650,250,25,100,625,350,625,250);
    GaugeEssence->setValue(25);
    scene->addItem(GaugeEssence);

    aiguille_Lea *aiguille_vitesse = new aiguille_Lea;
    aiguille_vitesse->parametrage(400.0,200.0,9.0,160.0,225,270,270);
    aiguille_vitesse->setValue(150);
    scene->addItem(aiguille_vitesse);


    TachometerGauge_Lea *Gauge_Tours = new TachometerGauge_Lea;
    Gauge_Tours->parametrage(140.0,240.0,130.0,230,50,180);
    scene->addItem(Gauge_Tours);


    aiguille_Lea *aiguille_tours = new aiguille_Lea;
    aiguille_tours->parametrage(140.0,240.0,9.0,130,225,50,41);
    aiguille_tours->setValue(200);
    scene->addItem(aiguille_tours);

    voyant_Lea *porte_ouverte = new voyant_Lea;
    porte_ouverte->parametrage(380,400,":/PorteOuverte.png");
    porte_ouverte->setSize(80,80);
    porte_ouverte->on=0;
    scene->addItem(porte_ouverte);

    voyant_Lea *clignoGauche = new voyant_Lea;
    clignoGauche->parametrage(180,50,":/ClignottantGauche.png");
    clignoGauche->setSize(70,50);
    clignoGauche->on=0;
    scene->addItem(clignoGauche);

    voyant_Lea *clignoDroit = new voyant_Lea;
    clignoDroit->parametrage(580,50,":/ClignottantDroit.png");
    clignoDroit->setSize(70,50);
    clignoDroit->on=0;
    scene->addItem(clignoDroit);




//    speedometer_Lea *compteur = new speedometer_Lea;
//    compteur->parametrage(400.0,200.0,160.0,225,270,315,28,270);
//    scene->addItem(compteur);

}

void MainWindow::vitesse()
{
    compteur_vitesse->v1 = ui->verticalSlider->value();
    tours_minute->v1 = ui->verticalSlider->value();
    scene->update();
}
