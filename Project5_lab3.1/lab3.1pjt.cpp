#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("Lenna.jpg");
	if (img.empty()) { cout << "영상을 읽을 수 없음" << endl; return -1; }
	imshow("컬러 영상", img);
	//imwrite("img.jpg", img);

	cout << "행의 수 = " << img.rows << endl;
	cout << "열의 수 = " << img.cols << endl;
	cout << "행렬의 크기 = " << img.size() << endl;
	cout << "전체 화소 개수 = " << img.total() << endl;
	cout << "한 화소 크기 = " << img.elemSize() << endl;
	cout << "타입 = " << img.type() << endl;
	cout << "채널 = " << img.channels() << endl;

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	imshow("흑백 영상", gray); // 타이틀
	//imwrite("gray.jpg", gray);

	cout << "행의 수 = " << gray.rows << endl;
	cout << "열의 수 = " << gray.cols << endl;
	cout << "행렬의 크기 = " << gray.size() << endl;
	cout << "전체 화소 개수 = " << gray.total() << endl;
	cout << "한 화소 크기 = " << gray.elemSize() << endl;
	cout << "타입 = " << gray.type() << endl;
	cout << "채널 = " << gray.channels() << endl;

	waitKey(0); // 창을 닫지 않는 한 무한으로 waiting
	return 0;
}