#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("Lenna.jpg", IMREAD_COLOR);
	Mat dst = Mat();
	Size dsize = Size(src.cols, src.rows);


	Point center = Point(0, 0);

	Mat M = getRotationMatrix2D(center, -15, 1.0);

	warpAffine(src, dst, M, dsize, INTER_LINEAR);

	imshow("Image", src);
	imshow("Rotated", dst);
	waitKey(0);
	return 1;
}