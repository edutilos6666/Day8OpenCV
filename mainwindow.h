#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "displaywidget.h"
#include "filterwidget.h"
#include "sourcewidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addWidgets();
    void registerEvents();

public:
    DisplayWidget *displayWidget;
    SourceWidget *sourceWidget;
    FilterWidget *filterWidget;
    QGridLayout *mainLayout ;
    QWidget *mainWidget;
};

#endif // MAINWINDOW_H
