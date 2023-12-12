#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

// ����ȭ ����
void binarToimage(Mat& dst, int threshold_value)
{
	for (int r = 0; r < dst.rows; r++) {
		for (int c = 0; c < dst.cols; c++) {
			if (dst.at<uchar>(r, c) >= threshold_value) {
				dst.at<uchar>(r, c) = 255;
			}
			else {
				dst.at<uchar>(r, c) = 0;
			}
		}
	}
}

int main()
{
	Mat img = imread("lenna.jpg", IMREAD_GRAYSCALE);
	Mat dst = img.clone();
	int value;
	cout << "�Ӱ谪 �Է� : ";
	cin >> value;
	binarToimage(dst, value);

	imshow("Original image", img);
	imshow("Binary image", dst);
	waitKey(0);
	return 0;
}