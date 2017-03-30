#include "sourcewidget.h"
#include "ui_sourcewidget.h"

SourceWidget::SourceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SourceWidget)
{
    ui->setupUi(this);
	registerEvents(); 
}

SourceWidget::~SourceWidget()
{
    delete ui;
}



void SourceWidget::openVideoFile() {
	QString caption = "Open Video File"; 
	QString dir = "C:/Users/edutilos/Pictures";
	QString filter = "Video Files(*.mp4, *.avi)"; 
	QString fileName = QFileDialog::getOpenFileName(0, caption, dir); 
  
	 
	cv::VideoCapture cap; 
	cap.open(fileName.toStdString()); 
	cout << fileName.toStdString() << endl ; 
	if (!cap.isOpened())  {
		cout << "error"; 
		return; 
	}


	emit videoStarted(); 

	cv::Mat frame; 


	
	double frameCount = cap.get(cv::CAP_PROP_FRAME_COUNT);
	 ui->pbSW->setMaximum(frameCount); 

	 double fps = ui->sbSW->value(); 

	//cap.set(cv::CAP_PROP_FPS, fps);
	 cout << "fps before = " << cap.get(cv::CAP_PROP_FPS) << endl; 
	 bool res = cap.set(cv::CAP_PROP_FPS, fps); 
	 cout << "fps setting result = " << res; 
	 cout << "fps after = " << cap.get(cv::CAP_PROP_FPS) << endl; 
	for (;;) {
		
	//	QThread::sleep(1); 
	/*	if (!cap.read(frame))  {
			cout << "error in cap.read"; 
			return; 
		}*/

		cap >> frame; 
		if (i < (int)frameCount) {
			emit newImage(frame);
			emit valueChanged(++i); 
		}
		else {
			i = 0; 
			break; 
		}
	}
	

	
}


void SourceWidget::registerEvents() {
	ui->sbSW->setMaximum(1000000); 
	QObject::connect(ui->btnSWChoose, SIGNAL(clicked()), this, SLOT(openVideoFile())); 
	QObject::connect(this, SIGNAL(valueChanged(int)), this, SLOT(updateProgressBar(int))); 
}


void SourceWidget::updateProgressBar(int i) {
	//if (i > ui->pbSW->maximum()) {
	//	completedFlag = true; 
	//	emit videoCompleted();
	//}
	//else {
	//	QThread::msleep(1);
	//	ui->pbSW->setValue(i);
	//}
		//QThread::msleep(1);

	if (i < ui->pbSW->maximum()) {
		ui->btnSWChoose->setEnabled(false); 
		ui->sbSW->setEnabled(false); 
	}
	else {
		ui->btnSWChoose->setEnabled(true);
		ui->sbSW->setEnabled(true);
		emit videoCompleted(); 
	}

		ui->pbSW->setValue(i);
		QCoreApplication::processEvents(); 

}