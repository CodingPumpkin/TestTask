#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    setWindowTitle("points to visit app");
    setFixedSize(WINDOW_W, WINDOW_H);

    canvas = new Canvas(this);
    canvas->setFixedSize(WINDOW_W, WINDOW_H);
    label = new QLabel(this);
    label->setText("Total: XXX USD");
}

MainWindow::~MainWindow()
{
    delete this->label;
    delete this->canvas;
}

