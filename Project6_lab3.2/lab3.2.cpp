#define _CRT_SECURE_NO_WARRINGS
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("opencv.png");
	if (img.empty()) {
		cout << "영상을 읽을 수 없음" << endl; return -1;
	}
	imshow("img", img);

	int b = img.at<Vec3b>(40, 110)[0]; //blue channel
	int g = img.at<Vec3b>(40, 110)[1]; //green channel
	int r = img.at<Vec3b>(40, 110)[2]; //red channel

	cout << b << "\n" << g << "\n" << r << endl;
	waitKey(0);
	return 0;
}