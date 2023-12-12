// P.367 chapter11 이진화 타입 트랙바 실습


#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;
/*
int threshold_value = 128;
int threshold_type = 0;
const int max_type = 4;
const int max_binary_value = 255;
Mat src, src_gray, dst;

static void MyThreshold(int, void*) {
	threshold(src, dst, threshold_value, max_binary_value, threshold_type);
	imshow("result", dst);
}

int main() {
	src = imread("lenna.jpg", IMREAD_GRAYSCALE);
	imshow("src", src);
	namedWindow("result", WINDOW_AUTOSIZE);
	createTrackbar("Type : \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted",
		"result", &threshold_type,
		max_type, MyThreshold);
	MyThreshold(0, 0);
	waitKey();
	return 0;
}
*/


// P.372 적응적 이진화
/*
int main() {
	Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);
	Mat img, th1, th2, th3, th4;

	medianBlur(src, img, 5);
	threshold(img, th1, 127, 255, THRESH_BINARY);
	adaptiveThreshold(img, th2, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, 2);
	adaptiveThreshold(img, th3, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 11, 2);
	imshow("Original", src);
	imshow("Global Thresholding", th1);
	imshow("Adaptive Mean", th2);
	imshow("Adaptive Gaussian", th3);
	waitKey();
	return 0;
}
*/

// Otsu 이진화 방법
int main() {
	Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);
	Mat blur, th1, th2, th3, th4;
	threshold(src, th1, 127, 255, THRESH_BINARY);
	threshold(src, th1, 0, 255, THRESH_BINARY | THRESH_OTSU);

	Size size = Size(5, 5);
	GaussianBlur(src, blur, size, 0);
	threshold(blur, th3, 0, 255, THRESH_BINARY | THRESH_OTSU);

	imshow("Original", src);
	imshow("Global", th1);
	imshow("Ostu", th2);
	imshow("Ostu after Blurring", th3);
	waitKey();
	return 0;
}