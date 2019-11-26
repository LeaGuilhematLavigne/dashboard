#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mygraphicitem.h"

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


    ~MainWindow();

public slots :
    void Scene();
    void vitesse();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
