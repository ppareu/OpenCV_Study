#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main()
{
	Mat src, dst, dst1, erosion_dst, dilation_dst;
	src = imread("morph.jpg", IMREAD_GRAYSCALE);

	threshold(src, dst, 127, 255, THRESH_BINARY);
	imshow("dst", dst);

	Mat element = getStructuringElement(MORPH_RECT,
		Size(3, 3),
		Point(-1, -1));

	erode(dst, erosion_dst, element);
	dilate(dst, dilation_dst, element);
	imshow("ÆØÃ¢", dilation_dst);
	imshow("Ä§½Ä", erosion_dst);
	waitKey(0);
	return 0;
}