#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPen>
#include <vector>
#include <cmath>
#include <iostream>

#include "graph.h"
#include "solver.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();
    int start_indx = -1;
    int dest_indx = -1;

signals:
    void done(float cost);
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *e);
private:
    QPainter *painter;

    Graph graph;
    Solver *solver;
    void draw_points();
    void calculate();
};

#endif // CANVAS_H
