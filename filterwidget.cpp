#include "filterwidget.h"
#include "ui_filterwidget.h"

FilterWidget::FilterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterWidget)
{
    ui->setupUi(this);
	initModels(); 
	setModel(); 
	registerEvents(); 
}

FilterWidget::~FilterWidget()
{
    delete ui;
}


void FilterWidget::onNewImage(cv::Mat src) {
	QStandardItemModel *model = (QStandardItemModel*)ui->tvFilterFW->model(); 
	this->src = src; 
	applyFilter(this->src, model); 

	emit newImage(this->src); 
//	emit valueChanged(++i); 
}

void  FilterWidget::registerEvents() {
	//QObject::connect(ui->cbFilterSizeFW, SIGNAL(currentIndexChanged(int)), this, SLOT(setModel())); 
	/*QObject::connect(ui->cbFilterSizeFW, SIGNAL(currentIndexChanged(int index)), this, SLOT(setModel2())); */
	//QObject::connect(ui->cbFilterSizeFW, SIGNAL(currentIndexChanged(const QString &text)), this, SLOT(setModel2(const QString &text)));
//	QObject::connect(ui->cbNFilterFW, SIGNAL(stateChanged(int)), this, SLOT(stateChanged(int))); 

	QObject::connect(ui->cbFilterSizeFW, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [this]() {
	//	cout << "currentIndexChanged" << endl; 
		setModel(); 
	}); 


	ui->tvFilterFW->horizontalHeader()->hide(); 
	ui->tvFilterFW->verticalHeader()->hide(); 

	QObject::connect(model3, &QStandardItemModel::dataChanged, [this](const QModelIndex & topLeft, const QModelIndex & bottomRight) {
	/*	cout << QString("[%1 %2] and [%3 %4]").arg(topLeft.row())
			.arg(topLeft.column())
			.arg(bottomRight.row())
			.arg(bottomRight.column()).toStdString()  << endl ; */

		applyFilter(src, model3, topLeft , true); 
	}); 


	QObject::connect(model5, &QStandardItemModel::dataChanged, [this](const QModelIndex & topLeft, const QModelIndex & bottomRight) {
		/*	cout << QString("[%1 %2] and [%3 %4]").arg(topLeft.row())
		.arg(topLeft.column())
		.arg(bottomRight.row())
		.arg(bottomRight.column()).toStdString()  << endl ; */

		applyFilter(src, model5, topLeft , true);
	});


	QObject::connect(model7, &QStandardItemModel::dataChanged, [this](const QModelIndex & topLeft, const QModelIndex & bottomRight) {
		//cout << "inside dataChanged" << endl; 
		/*	cout << QString("[%1 %2] and [%3 %4]").arg(topLeft.row())
		.arg(topLeft.column())
		.arg(bottomRight.row())
		.arg(bottomRight.column()).toStdString()  << endl ; */

		applyFilter(src, model7, topLeft , true);
	});


	QObject::connect(ui->cbNFilterFW, &QCheckBox::stateChanged, [this]() {

		if (ui->cbNFilterFW->isChecked()) {
			normalizeFilter(src);
		}

		
	}); 

	QObject::connect(ui->cbNOutputFW, &QCheckBox::stateChanged, [this]() {
		if (ui->cbNOutputFW->isChecked()) {
			normalizeOutput(src);
		}
	}); 

}

void FilterWidget::applyFilter(cv::Mat &src , QStandardItemModel *model, const QModelIndex & topLeft, bool changed) {
	cv::Mat *filter;
	if (model == model3) {
		filter = new cv::Mat(3, 3, CV_32F, cv::Scalar(1));
		//filter.at<float>(1, 1) = 100.0; 
	
	}
	else if (model == model5) {
		filter = new cv::Mat(5, 5, CV_32F, cv::Scalar(1));
	}
	else if (model == model7) {
		filter = new cv::Mat(7, 7, CV_32F, cv::Scalar(1));
	}

	if (changed) {
		float val = model->data(topLeft).toFloat();
		filter->at<float>(topLeft.column(), topLeft.row()) = val;
	}
	(*filter) *= (1 / 25.0);
	//cv::Mat dst;
	cv::filter2D(src, src, 0, *filter);


	//if (ui->cbNFilterFW->isChecked()) {
	//	normalizeFilter(src); 
	//}

	//if (ui->cbNOutputFW->isChecked()) {
	//	normalizeOutput(src); 
	//}
}

void FilterWidget::setModel() {
	//cout << "inside setModel" << endl; 
	int size = ui->cbFilterSizeFW->currentText().toInt();
	switch (size) {
	case 3:
		ui->tvFilterFW->setModel(model3);
		break;
	case 5:
		ui->tvFilterFW->setModel(model5);
		break;
	case 7:
		ui->tvFilterFW->setModel(model7);
		break;
	}
}
void FilterWidget::initModels() {
	model3 = new QStandardItemModel(); 
	QStandardItem *item;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			item = new QStandardItem("1"); 
			model3->setItem(i, j, item); 
		}
	}

	model5 = new QStandardItemModel(); 

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			item = new QStandardItem("1"); 
			model5->setItem(i, j, item); 
		}
	}

	model7 = new QStandardItemModel(); 
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			item = new QStandardItem("1"); 
			model7->setItem(i, j, item); 
		}
	}

}





void FilterWidget::normalizeFilter(cv::Mat& src) {

}
void FilterWidget::normalizeOutput(cv::Mat& src) {

}