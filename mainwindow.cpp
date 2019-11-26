#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->verticalSlider->setValue(0);
    ui->verticalSlider->setMaximum(300);

   connect(ui->verticalSlider,SIGNAL(actionTriggered(int)),this, SLOT(vitesse()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Scene()
{
    ui->graphicsView->setScene(scene);
    myitem->v1 = ui->verticalSlider->value();
    scene->addItem(myitem);
}

void MainWindow::vitesse()
{
    myitem->v1 = ui->verticalSlider->value();
    scene->update();
}
