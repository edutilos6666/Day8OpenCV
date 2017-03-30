#include "mainwindow.h"
#include <QApplication>
#include "sourcewidget.h"
#include "filterwidget.h"
#include "displaywidget.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <QLabel>
#include <QImage>


using namespace std; 


void test2() {
	cv::Mat m1(5, 5, CV_8U, cv::Scalar(1, 2, 3, 4)); 
	

	m1.at<unsigned char>(1, 0) = 100; 
	//cout << m1 << endl;

	cv::String inFile = "C:/Users/cplusplus/Pictures/img1.jpg";
	cv::Mat src = imread(inFile);

	cout << src << endl; 
}
void testOpenCV() {

	cv::Mat img = cv::imread("C:/Users/cplusplus/Pictures/img1.jpg");
	if (img.empty())
		return;
	cv::namedWindow("Image");
	cv::imshow("Image", img);
	cv::waitKey();
	cv::destroyWindow("Image");
}


void test3()  {
	cv::String fileName = "C:/Users/cplusplus/Pictures/img1.jpg"; 
	//cv::IMREAD_COLOR
	//cv::IMREAD_GRAYSCALE
	//cv::IMREAD_UNCHANGED

	cv::Mat img = cv::imread(fileName, cv::IMREAD_GRAYSCALE); 

	if (img.empty()) return; 
	cv::namedWindow("ColoredImage"); 
	cv::imshow("ColoredImage", img); 
	cv::waitKey(); 
	cv::destroyWindow("ColoredImage"); 
}


void test4() {
	cv::String inFile = "C:/Users/cplusplus/Pictures/img1.jpg"; 
	cv::Mat img = cv::imread(inFile, cv::IMREAD_GRAYSCALE); 
	if (img.empty()) return; 
	cv::String outFile = "C:/Users/cplusplus/Pictures/img2.png"; 
	cv::imwrite(outFile, img, {}); 

	cout << "after writing  image"; 
	inFile = outFile; 
	img = cv::imread(inFile, cv::IMREAD_GRAYSCALE); 
	if (img.empty()) {
		cout << "img is empty"; 
		return; 
	}

	cv::namedWindow("Image"); 
	cv::imshow("Image", img);
	cv::waitKey(); 
	cv::destroyWindow("Image"); 
}


void testVideoCapture() {
	cv::VideoCapture cap; 
	cv::String inFile = "C:/Users/edutilos/Pictures/mov01.mp4";

	cap.open(inFile); 
	//cap.open(0); 
	//if (cap.isOpened()) {
	//	cv::Mat m;
	//	while (cap.read(m)) {
	//	//	cout << m << endl << endl;
	//		cv::imshow("Video", m); 
	//		if(cv::waitKey(30) >= 0) break; 
	//	}
	//}


	cv::Mat frame; 
	for (;;) {
		cap >> frame; 
		cv::Mat edges; 
		cv::cvtColor(frame, edges, cv::COLOR_BGR2GRAY); 
		/*cv::GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);
		cv::Canny(edges, edges, 0, 30, 3);*/
		cv::imshow("edges", edges);
	//	if (cv::waitKey(10000) >= 0) break;
		cv::waitKey(10); 
	}



}

void test5() {
	cv::String inFile = "C:/Users/cplusplus/Pictures/mov01.mp4";
	cv::VideoCapture cap; 
	cap.open(inFile); 

	if (!cap.isOpened()) return; 

	cv::Mat src; 
	


	cap >> src; 
	int coded = CV_FOURCC('M', 'J', 'P', 'G');
	double fps = 25; 
	bool isColor = true; 
	cv::String outFile = "C:/Users/cplusplus/Pictures/mov02.avi"; 
	cv::VideoWriter writer; 


	writer.open(outFile, coded, fps, src.size(), isColor); 
  
	if (!writer.isOpened()) return; 

	for (;;) {
		if (!cap.read(src)) return; 
		writer.write(src); 
	}
}


void test6() {
	cv::String inFile = "C:/Users/cplusplus/Pictures/mov02.avi";
   
	cv::VideoCapture cap; 
	cap.open(inFile); 

	if (!cap.isOpened()) return; 

	cv::Mat frame; 
	for (;;) {
		if (!cap.read(frame)) return; 
		cv::imshow("frame", frame); 
		cv::waitKey(5); 
	}
}


void test7() {

	/*
			cv::cvtColor(frame, edges, cv::COLOR_BGR2GRAY);
			cv::GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);
			cv::Canny(edges, edges, 0, 30, 3);
			cv::imshow("edges", edges);
	
	*/

	cv::String inFile = "C:/Users/edutilos/Pictures/mov01.mp4";
	cv::String outFile = "C:/Users/edutilos/Pictures/mov04.avi";

	cv::Mat src; 

	cv::VideoCapture cap; 
	double fps = 20;
	bool res = cap.set(cv::CAP_PROP_FPS, fps);
	cap.open(inFile); 

	if (!cap.isOpened()) return; 

	cap >> src; 
	//cap.release(); 

	cout << "src size= " << src.size() << endl; 
	//int codec = CV_FOURCC('M', 'J', 'P', 'G'); 
	//int codec = CV_FOURCC('D', 'I', 'V', 'X');
	//int codec = CV_FOURCC('M', 'P', '4', '2'); 
	int codec = CV_FOURCC('D', 'I', 'V', '3'); 
 

	cv::VideoWriter writer; 
	writer.open(outFile, codec, fps, src.size(), true); 

	if (!writer.isOpened()) {
		cout << "could not open writer" << endl; 
		return;
	}

	for (;;) {
		if (!cap.read(src)) {
			writer.release();
			return;
		}

		cv::Mat edges; 
		//cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);
		int ddepth = 0; 
		cv::Mat kernel (3, 3, CV_32F, cv::Scalar(1));
		kernel *= (1 / 25.0);
		cv::filter2D(src, src, ddepth, kernel); 
		/*cv::GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);
		cv::Canny(edges, edges, 0, 30, 3);*/
		
		writer.write(src); 
	}


	//writer.release(); 

	/*inFile = outFile; 
	cap.open(inFile); 
	cv::Mat frame; 
	if (!cap.isOpened()) return; 
	for (;;) {
		if (!cap.read(frame)) return; 
		cv::imshow("edges", frame); 
		cv::waitKey(10); 
	}*/
}


void test8() {
	cv::VideoCapture cap; 
	cv::String inFile = "C:/Users/cplusplus/Pictures/mov02.avi";
	cap.open(inFile);
	cv::Mat frame;
	if (!cap.isOpened()) return;
	cap.set(cv::CAP_PROP_FPS, 1); 
	for (;;) {
		if (!cap.read(frame)) return;
		cv::imshow("edges", frame);
		cv::waitKey(10);
	}


	cout << "properties" << endl; 
	double frameCount = cap.get(cv::CAP_PROP_FRAME_COUNT);
	double frameHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT); 
	double frameWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH); 
	double posFrames = cap.get(cv::CAP_PROP_POS_FRAMES); 
	
	cout << "frameCount = " << frameCount << endl
		<< "frameHeight = " << frameHeight << endl
		<< "frameWidth = " << frameWidth << endl
		<< "posFrames = " << posFrames << endl; 

}



//QImage qImage(qSize, QImage::Format_RGB888); 
//cv::Size cvSize(src.rows, src.cols); 
//cv::Mat header(cvSize, CV_8UC3, qImage.bits()); 
//cv::cvtColor(src, header, cv::COLOR_BGR2RGB);


//int cols = header.cols; 
//int rest = cols % 4; 
//cols += rest; 
//int rows = header.rows; 
//rest = rows % 4; 
//rows += rest; 
//QImage qImage2((uchar*)header.data, cols, rows, QImage::Format_RGB888); 
//QPixmap map = QPixmap::fromImage(qImage2); 


void testConvertImage() {
	cv::String inFile = "C:/Users/cplusplus/Pictures/img1.jpg"; 
	cv::Mat src = cv::imread(inFile); 
	cv::Mat temp = cv::imread("C:/Users/cplusplus/Pictures/img3.jpg"); 
	cv::Mat dst;
	int cols = src.cols;
	int rest = cols % 4;
	cols -= rest;
	int rows = src.rows;
	rest = rows % 4;
	rows -= rest;
	cout << src.cols << " , " << src.rows  << endl ; 
	cv::resize(src, src, cv::Size(cols, rows)); 
	cout << src.cols << " , " << src.rows  << endl ; 
	/*for (int i = src.cols; i < cols; ++i) {
		src.at<unsigned char>(i, src.rows) = 1; 		
	}

	for (int i = src.rows; i < rows; ++i) {
		src.at<unsigned char>(src.cols, i) = 1; 
	}*/

	cv::cvtColor(src, dst, cv::COLOR_BGR2RGB);
	QImage qImage((uchar*)dst.data, dst.cols, dst.rows, QImage::Format_RGB888);
	QPixmap map = QPixmap::fromImage(qImage);

	QSize qSize(src.rows, src.cols);



	QLabel *lbl = new QLabel();
	lbl->setPixmap(map);
	lbl->show();
}


void testFilter() {
	cv::String inFile = "C:/Users/edutilos/Pictures/img1.jpg";
	cv::Mat src = cv::imread(inFile);

	unsigned int matrix[7][7]; 
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			matrix[i][j] = 1; 
		}
	}

	//cv::Mat m1(5, 5, CV_8U, cv::Scalar(1, 2, 3, 4));
	cv::Mat filter(3, 3, CV_32F,  cv::Scalar(1));
	//filter.at<float>(1, 1) = 100.0; 
	filter *= (1 / 25.0); 
	cout << filter << endl; 
 
	//for (int i = 0; i < 3; ++i) {
	//	for (int j = 0; j < 3; ++j) {
	//		if (filter.at<float>(j, i) >255) filter.at<float>(j, i) = 255; 
	//	}
	//}

	cv::Mat dst; 
	cv::filter2D(src, dst, 0, filter); 

	cv::imshow("filter", dst); 
	cv::waitKey(); 
}


void test9() {
	cv::String inFile = "C:/Users/edutilos/Pictures/mov02.avi";
	int codec = CV_FOURCC('M', 'J', 'P', 'G');
  
	cv::Mat frame; 
	cv::VideoCapture cap; 
	cap.open(inFile); 
	if (!cap.isOpened()) {
		cout << "error opening file with cap" << endl;
	}

	while (cap.read(frame)) {
		cv::imshow("frame", frame); 
		cv::waitKey(10); 
   }
	

	cout << "end" << endl; 

}

void test10() {
	cv::VideoCapture cap; 
	cv::String fileName = "C:/Users/edutilos/Pictures/file1.avi"; 
	cv::Mat frame; 
	cap.open(fileName); 
	if (!cap.isOpened()) {
		cout << "error opening file with cap" << endl; 
		return; 
	}

	while (cap.read(frame)) {
		cv::imshow("frame", frame); 
		cv::waitKey(); 
	}
}

int main(int argc, char *argv[])
{

//     w.show();
//     w.test();
//
////     SourceWidget *w = new SourceWidget();
	//testConvertImage(); 	
	//testFilter(); 
	//testFilter(); 
//	test2(); 

	
	//testVideoCapture(); 
	//testFilter(); 
	/*QApplication a(argc, argv);
	MainWindow *w = new MainWindow;
	w->show();
	return a.exec();*/

	test7(); 
	//test9(); 
	//test10(); 
}
