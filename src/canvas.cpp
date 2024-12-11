#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget{parent}
{
    connect(this, &Canvas::start_set, this, &Canvas::calculate);
    graph = Graph();

    solver = new Solver(graph);
    painter = new QPainter(this);
}

Canvas::~Canvas()
{
    delete solver;
    delete painter;
}

void Canvas::paintEvent(QPaintEvent *event)
{

    painter->begin(this);
    painter->setPen(QPen(Qt::green, 2, Qt::DashDotLine, Qt::RoundCap));
    painter->drawEllipse(QPoint(FIELD_W/2, FIELD_H/2), R, R);
    painter->setPen(QPen(Qt::cyan, 2, Qt::SolidLine, Qt::RoundCap));
    for (utils::Vertex vertex : graph.vertices)
    {
        for (int connection : vertex.connections)
            painter->drawLine(QPoint(vertex.x, vertex.y),
                              QPoint(graph.vertices[connection].x, graph.vertices[connection].y));
    }
    painter->setPen(QPen(Qt::magenta, POINT_SIZE*POINT_SIZE, Qt::SolidLine, Qt::RoundCap));
    for (utils::Vertex vertex : graph.vertices)
    {
        painter->drawEllipse(QPoint(vertex.x, vertex.y) , POINT_SIZE, POINT_SIZE);
    }
    if (start_indx >= 0) {
        painter->setPen(QPen(START_COLOR, POINT_SIZE*POINT_SIZE, Qt::SolidLine, Qt::RoundCap));
        painter->drawEllipse(QPoint(graph.vertices[start_indx].x, graph.vertices[start_indx].y) , POINT_SIZE, POINT_SIZE);
    }
    if (dest_indx >= 0) {
        painter->setPen(QPen(DEST_COLOR, POINT_SIZE*POINT_SIZE, Qt::SolidLine, Qt::RoundCap));
        painter->drawEllipse(QPoint(graph.vertices[dest_indx].x, graph.vertices[dest_indx].y) , POINT_SIZE, POINT_SIZE);
    }
    painter->end();
    event->accept();
}

void Canvas::mousePressEvent(QMouseEvent *e)
{
    int x = e->position().x();
    int y = e->position().y();

    if (e->button() == CLEAR_BTN)
    {
        start_indx = -1;
        // dest_indx = -1;
        solver->clear();
        update();
        return;
    }

    if (start_indx  < 0)
    {
        for (int i = 0; i < NUMBER_OF_POINTS; i++)
        {
            double dist = sqrt( (graph.vertices[i].x-x) * (graph.vertices[i].x-x) +
            (graph.vertices[i].y-y) * (graph.vertices[i].y-y));
            if (dist <= (double)(2*POINT_SIZE))
            {
                if (e->button() == START_BTN)
                {
                    start_indx = i;
                    emit start_set();
                }
                // else if (e->button() == DEST_BTN)
                // {
                //     dest_indx = i;
                // }
                break;
            }
        }
    }
    update();
}

void Canvas::calculate()
{
    if(start_indx > 0)
    {
        solver->solve(start_indx);
        solver->print_visited();
        emit done(solver->get_cost());
    }
}
