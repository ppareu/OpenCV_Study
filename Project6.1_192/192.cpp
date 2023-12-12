#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.jpg");

	Mat dst(src.size(), CV_8UC3, Scalar(0));
	if (src.empty()) { return -1; }

	Mat dst1, dst2;
	// <uchar> - 흑백 시 , <Vec3b> - 컬러 시
	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			for (int c = 0; c < 3; c++) {
				int sum = 0;
				sum += src.at<Vec3b>(y - 1, x - 1)[c];
				sum += src.at<Vec3b>(y, x - 1)[c];
				sum += src.at<Vec3b>(y + 1, x - 1)[c];
				sum += src.at<Vec3b>(y - 1, x)[c];
				sum += src.at<Vec3b>(y, x)[c];
				sum += src.at<Vec3b>(y + 1, x)[c];
				sum += src.at<Vec3b>(y - 1, x + 1)[c];
				sum += src.at<Vec3b>(y, x + 1)[c];
				sum += src.at<Vec3b>(y + 1, x + 1)[c];
				dst.at<Vec3b>(y, x)[c] = sum / 9;
			}
		}
	}

	blur(src, dst1, Size(7, 7));
	imshow("blur", dst1);

	for (int i = 1; i < 31; i = i + 2) {
		GaussianBlur(src, dst2, Size(i, i), 0, 0);
		imshow("Gaussian filter", dst2);
	}

	imshow("initial", src);
	imshow("final", dst);
	waitKey(0);
	return 0;
}