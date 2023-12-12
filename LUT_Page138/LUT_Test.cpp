#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;



void reduceColorAt(Mat& input, uchar table[])
{
	for (int i = 0; i < input.rows; ++i)
		for (int j = 0; j < input.cols; ++j)
			input.at<uchar>(i, j) = table[input.at<uchar>(i, j)];
}

int main()
{
	Mat img1 = imread("Lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", img1);

	Mat table(1, 256, CV_8U);
	uchar* p = table.ptr();
	for (int i = 0; i < 256; ++i)
		p[i] = (i / 100) * 100;

	reduceColorAt(img1, p);
	imshow("New Image", img1);
	waitKey(0);

	return 0;
}