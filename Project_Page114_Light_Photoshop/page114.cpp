#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("Lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", img);

	/*
	for (int r = 0; r < img.rows; r++) {
		for (int c = 0; c < img.cols; c++) {
			img.at<uchar>(r, c) = saturate_cast<uchar>(img.at<uchar>(r, c) + 30); // 오버플로우 방지
		}
	}
	

	if (img.isContinuous()) {
		uchar* p = img.data;
		for (int c = 0; c < img.cols * img.rows; c++)
			*p++ = saturate_cast<uchar>(*p + 30);
	}
	*/

	Mat oimage;
	img.convertTo(oimage, -1, 1, 30); //opencv함수이다.

	imshow("New Image", img);
	waitKey(0);
	return 0;
}