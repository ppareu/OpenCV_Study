#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main() {
	Mat img, hsv, dst;
	img = imread("lenna.jpg");
	cvtColor(img, hsv, COLOR_BGR2HSV);

	Mat array[3];
	split(hsv, array);
	imshow("src", img);
	imshow("hue", array[0]);
	imshow("saturation", array[1]);
	imshow("value", array[2]);

	waitKey(0);
	return 0;
}