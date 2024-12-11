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
    label->setText("Sum: XXX USD");
}

MainWindow::~MainWindow()
{
    delete this->label;
    delete this->canvas;
}

void MainWindow::update_cost(float cost)
{
    label->setText(QString("Sum: ") + QString::number(COST * cost / UNIT_OF_DISTANCE, 'f', 2) + QString(" USD"));
}
