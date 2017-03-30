#ifndef FILTERWIDGET_H
#define FILTERWIDGET_H

#include <QWidget>
#include <opencv2/core.hpp>
#include <QFileDialog>
#include <QString>
#include <QStandardItemModel>
#include <QStandardItem>
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
class FilterWidget;
}

class FilterWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilterWidget(QWidget *parent = 0);
    ~FilterWidget();
	void registerEvents(); 
	void initModels(); 
	void applyFilter(cv::Mat &src, QStandardItemModel *model, const QModelIndex & topLeft = QModelIndex(), bool changed = false);
	void normalizeFilter(cv::Mat &src); 
	void normalizeOutput(cv::Mat &src); 
signals:
	void newImage(cv::Mat); 
//	void valueChanged(int); 

public slots: 
void onNewImage(cv::Mat); 
void setModel();

public:
    Ui::FilterWidget *ui;
	QStandardItemModel *model3, *model5, *model7; 
	cv::Mat src; 
};

#endif // FILTERWIDGET_H
