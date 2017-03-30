#include "mainwindow.h"
//#include "ui_filterwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    addWidgets();

}

MainWindow::~MainWindow()
{
}


/*
 *  DisplayWidget *displayWidget;
    SourceWidget *sourceWidget;
    FilterWidget *filterWidget;
    QVBoxLayout *mainLayout ;
    QWidget *mainWidget;
    QHBoxLayout *secondLayout ;
    QWidget *secondWidget;
 * */
void MainWindow::addWidgets()
{
  mainLayout = new QGridLayout();

//mainLayout->setContentsMargins(-1, -1, -1,0); //   mainLayout->set
  mainLayout->setSpacing(0);
  mainLayout->setMargin(0);
  mainLayout->setVerticalSpacing(0);
  mainWidget = new QWidget(this);
  mainWidget->setLayout(mainLayout);
  this->setCentralWidget(mainWidget);
  this->resize(1000, 800);
  this->setWindowTitle("OpenCSV");

  sourceWidget = new SourceWidget();
  mainLayout->addWidget(sourceWidget , 0, 0, 1, 2);

//  secondLayout = new QHBoxLayout();  //secondLayout->setContentsMargins(-1, 0, -1, -1);
//  secondWidget = new QWidget();
//  secondWidget->setLayout(secondLayout);
//  mainLayout->addWidget(secondWidget);

  filterWidget = new FilterWidget();
  //  secondLayout->addWidget(filterWidget);
  //  secondLayout->setSpacing(0);
  //  secondLayout->setMargin(0);
    displayWidget = new DisplayWidget();
  //  secondLayout->addWidget(displayWidget);
  mainLayout->addWidget(filterWidget, 1, 0 );
  mainLayout->addWidget(displayWidget , 1, 1);
  mainLayout->setColumnStretch(0, 1);
  mainLayout->setColumnStretch(1, 1);
  mainLayout->setRowStretch(0, 1);
  mainLayout->setRowStretch(1, 1);
  registerEvents();
  this->show();

}

void MainWindow::registerEvents()
{
	QObject::connect(sourceWidget, SIGNAL(newImage(cv::Mat)), filterWidget, SLOT(onNewImage(cv::Mat)));
	QObject::connect(filterWidget, SIGNAL(newImage(cv::Mat)), displayWidget, SLOT(onNewImage(cv::Mat))); 
	//QObject::connect(filterWidget->ui->cbFilterSizeFW, SIGNAL(currentIndexChanged(const QString &text)), filterWidget, SLOT(setModel2(const QString &text)));
	//QObject::connect(displayWidget, SIGNAL(valueChanged(int)), sourceWidget, SLOT(updateProgressBar(int))); 
	
	//QObject::connect(sourceWidget, SIGNAL(videoCompleted()), displayWidget, SLOT(onVideoCompleted()));

	QObject::connect(sourceWidget, SIGNAL(videoStarted()), displayWidget, SLOT(onVideoStarted())); 
	QObject::connect(sourceWidget, SIGNAL(videoCompleted()), displayWidget, SLOT(onVideoCompleted()));
}
