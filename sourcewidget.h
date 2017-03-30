#ifndef SOURCEWIDGET_H
#define SOURCEWIDGET_H

#include <QWidget>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QString>
#include <iostream>
#include <string> 
#include <QThread>
using namespace std; 

namespace Ui {
class SourceWidget;
}

class SourceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SourceWidget(QWidget *parent = 0);
    ~SourceWidget();
	void registerEvents(); 

signals: 
	void newImage(cv::Mat); 
	void videoStarted(); 
	void videoCompleted(); 
	void valueChanged(int); 

public slots:
void openVideoFile();
void updateProgressBar(int i); 

private:
    Ui::SourceWidget *ui;
	cv::Mat src; 
	bool completedFlag = false; 
	int i = 0; 
};

#endif // SOURCEWIDGET_H
