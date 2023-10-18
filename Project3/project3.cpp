#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("Lenna.jpg", IMREAD_COLOR);
	if (image.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	//imshow("컬러 영상", image);

	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);
	//imshow("흑백 영상", gray); // 타이틀
	imwrite("gray.jpg", gray);

	Mat dst;
	flip(image, dst, 1);// Y축
	//imshow("뒤집은 영상", dst);
	imwrite("dst.jpg", dst);

	Mat dst1;
	flip(image, dst1, 0); // X축
	//imshow("뒤집은 영상1", dst1);
	imwrite("dst1.jpg", dst1); 
	
	Mat dst2;
	flip(image, dst2, -1); // 반바퀴(?)
	//imshow("뒤집은 영상2", dst2);
	imwrite("dst2.jpg", dst2);

	// 타원 만들기 과제1
	Mat a1 = Mat(400, 600, CV_8UC3, Scalar(0, 0, 0));

	// a1, Point(300, 200) 위치, Point(100, 60) 크기, 0 기울기, 360 시작 지점, 0 종료지점, Scalar(255, 255, 0) 색깔, 5 선 굵기
	ellipse(a1, Point(300, 200), Point(100, 60), 135, 360, 0, Scalar(255, 255, 0), 5);

	line(a1, Point(100, 100), Point(300, 300), Scalar(0, 0, 255), 7);
	rectangle(a1, Point(250, 30), Point(450, 200), Scalar(0, 255, 0), 5);
	circle(a1, Point(100, 300), 60, Scalar(255, 0, 0), 3);

	imshow("타원 영상1", a1);

	waitKey(0); // 창을 닫지 않는 한 무한으로 waiting
	return 0;
}