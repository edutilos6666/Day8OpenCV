#include "displaywidget.h"
#include "ui_displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWidget)
{
    ui->setupUi(this);
	registerEvents(); 
}

DisplayWidget::~DisplayWidget()
{
    delete ui;
}


void DisplayWidget::test() {
//   QMediaPlayer *player = new QMediaPlayer();
//   QGraphicsVideoItem *item = new QGraphicsVideoItem();
//   player->setVideoOutput(item);
//   player->setVolume(0);
////   player->setMedia(QUrl::fromLocalFile("C:/mov01.mp4"));
//     player->setMedia(QUrl::fromLocalFile("C:/Users/cplusplus/Downloads/material-Day8/material/mov01.mp4"));
//   QGraphicsScene *scene = new QGraphicsScene();
//   scene->setSceneRect(ui->displayDW->rect());
//   qDebug() << ui->displayDW->rect();
//   scene->addItem(item);
//   ui->displayDW->setScene(scene);
//   player->play();
}


int i = 0; 
void DisplayWidget::onNewImage(cv::Mat src) {

  	//cv::Mat src = cv::imread(inFile); 
	//cv::Mat temp = cv::imread("C:/Users/cplusplus/Pictures/img3.jpg"); 
	cv::Mat dst;
	int cols = src.cols;
	int rest = cols % 4;
	cols -= rest;
	int rows = src.rows;
	rest = rows % 4;
	rows -= rest;
	//cout << src.cols << " , " << src.rows  << endl ; 
	cv::resize(src, src, cv::Size(cols, rows)); 
	//cout << src.cols << " , " << src.rows  << endl ; 
	/*for (int i = src.cols; i < cols; ++i) {
		src.at<unsigned char>(i, src.rows) = 1; 		
	}

	for (int i = src.rows; i < rows; ++i) {
		src.at<unsigned char>(src.cols, i) = 1; 
	}*/



	//video recording 
	if (ui->cbRecordDW->isChecked()) {
		cv::VideoWriter writer; 
		if (firstTime == 0) {
			string fileName = ui->editFileNameDW->text().toStdString();
			//int codec = CV_FOURCC('M', 'J', 'P', 'G');
			//int codec = CV_FOURCC('D', 'I', 'V', 'X');
			int codec = CV_FOURCC('D', 'I', 'V', '3');
			double fps = ui->sbDW->value();
			bool isColored = true;
			++firstTime; 

			stringstream ss; 
			ss << "C:/Users/edutilos/Pictures/"; 
			ss << fileName; 
			fileName = ss.str(); 
			cout << fileName << endl; 
			
			writer.open(cv::String(fileName), codec, fps, src.size(), isColored); 
			if (!writer.isOpened()) {
				cout << "writer could not be opened" << endl; 
			}
		}
		//recordVideo(src); 
		writer.write(src); 
	}


	cv::cvtColor(src, dst, cv::COLOR_BGR2RGB);
	QImage qImage((uchar*)dst.data, dst.cols, dst.rows, QImage::Format_RGB888);
	//pmap = &(QPixmap::fromImage(qImage));
	QPixmap pmap = QPixmap::fromImage(qImage); 
	QSize qSize(src.rows, src.cols);



	//QLabel *lbl = new QLabel();
	ui->lblDisplay->setPixmap(pmap);
	emit valueChanged(++i); 
//	ui->lblDisplay->show(); 
	//ui->lblDisplay->setText(QString("Hello %1").arg(i++)); 
	//ui->lblDisplay->setText("hello world");
	//cout << "inside DisplayWidget" << endl;
}


void DisplayWidget::recordVideo(cv::Mat &src) {
	//cout << "record video is called " << j++ << endl; 
	//if (writer.isOpened()) {
	//	writer.write(src); 
	//}
	//else {
	//	cout << "writer is closed" << endl; 
	//}
}

void  DisplayWidget::onVideoCompleted() {
//	i = 0;
	ui->cbPreserveDW->setEnabled(false); 
	ui->cbRecordDW->setEnabled(false); 
	//writer.release(); 
}


void DisplayWidget::onVideoStarted() {
	ui->cbPreserveDW->setEnabled(true); 
	ui->cbPreserveDW->setChecked(false); 
	ui->cbRecordDW->setEnabled(false); 
	ui->cbRecordDW->setChecked(false);
	ui->editFileNameDW->setText(""); 
	ui->editFileNameDW->setEnabled(true); 
}

void DisplayWidget::registerEvents() {
	QObject::connect(ui->cbPreserveDW, &QCheckBox::stateChanged, [this]() {
		cout << "inside cbPreserveDW" << endl; 
		//if (ui->cbPreserveDW->isChecked()) {
		//	if (pmap == Q_NULLPTR) return;
		//		int width = pmap->width();
		//		int height = pmap->height();
		//		//map->scaled(); 
		//		pmap = &(pmap->scaled(width, height, Qt::KeepAspectRatio));
		//		ui->lblDisplay->setPixmap(*pmap);
		//}
		//else {
		//	if (pmap == Q_NULLPTR) return;
		//	int width = pmap->width();
		//	int height = pmap->height();
		//	//map->scaled(); 
		//	pmap = &(pmap->scaled(width, height, Qt::IgnoreAspectRatio));
		//	ui->lblDisplay->setPixmap(*pmap);
		//}

		int width = ui->lblDisplay->width();
		int height = ui->lblDisplay->height();
		QPixmap pmap;
		int ratio; 
		if (ui->cbPreserveDW->isChecked()) {
			ratio = Qt::KeepAspectRatio; 
		}

		else {
			ratio = Qt::IgnoreAspectRatio; 
		}

		ui->lblDisplay->setPixmap(pmap.scaled(width, height, (Qt::AspectRatioMode)ratio));
	
	}); 



	QObject::connect(ui->editFileNameDW, &QLineEdit::textChanged, [this](const QString &text) {
		if (text == "") {
			ui->cbRecordDW->setEnabled(false); 
		}
		else {
			ui->cbRecordDW->setEnabled(true); 
		}
	}); 

	QObject::connect(ui->cbRecordDW, &QCheckBox::stateChanged, [this](int newState) {
		if (ui->cbRecordDW->isChecked()) {
		
			ui->editFileNameDW->setEnabled(false); 
			ui->sbDW->setEnabled(false); 
			ui->lblStatusDW->setText("Recording"); 
		}
		else {
			ui->editFileNameDW->setEnabled(true); 
			ui->sbDW->setEnabled(true); 
			ui->lblStatusDW->setText("Not Recording"); 
		}
	}); 
}