#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QDebug>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string> 
#include <QSize>
#include <QPixmap>
#include <sstream>

using namespace std;
namespace Ui {
class DisplayWidget;
}

class DisplayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayWidget(QWidget *parent = 0);
    ~DisplayWidget();
    void test();
	void registerEvents(); 
	void recordVideo(cv::Mat &src);
signals: 
	void valueChanged(int); 
	
public slots: 
void onNewImage(cv::Mat); 
void onVideoCompleted();
void onVideoStarted(); 
private:
    Ui::DisplayWidget *ui;
	int i = 0; 
	QPixmap *pmap; 
	//cv::VideoWriter writer; 
	int firstTime = 0; 
	int j = 0; 
};

#endif // DISPLAYWIDGET_H
