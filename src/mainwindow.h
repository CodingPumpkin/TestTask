#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QCursor>
#include <string>

#include "canvas.h"
#include "constants.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QCursor mouse_cursor;
public slots:
    void update_cost(float);

private:
    Canvas *canvas;
    QLabel *label;
};
#endif // MAINWINDOW_H
