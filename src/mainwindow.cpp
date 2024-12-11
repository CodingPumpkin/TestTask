#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    setWindowTitle("points to visit app");
    setFixedSize(WINDOW_W, WINDOW_H);

    canvas = new Canvas(this);
    canvas->setFixedSize(WINDOW_W, WINDOW_H);
    connect(canvas, &Canvas::done, this, &MainWindow::update_cost);
    label = new QLabel(this);
    label->setText("Total: XXX USD");
}

MainWindow::~MainWindow()
{
    delete this->label;
    delete this->canvas;
}

void MainWindow::update_cost(float cost)
{
    label->setText(QString("Total: ") + QString::number(COST * cost / UNIT_OF_DISTANCE ) + QString(" USD"));
}
