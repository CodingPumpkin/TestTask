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
// private slots:
//     void on_pushButton_clear_clicked();
//     void addNewPointCoords();
//     void on_pushButton_calculate_clicked();

private:
    Canvas *canvas;
    QLabel *label;
};
#endif // MAINWINDOW_H
