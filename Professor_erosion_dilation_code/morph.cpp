#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

void erosion(Mat img, Mat& dst, Mat mask) {
	Mat temp;
	dst = Mat(img.size(), CV_8U, Scalar(0));
	if (mask.empty()) mask = Mat(3, 3, CV_8UC1, Scalar(1));

	int cnt, mcnt = countNonZero(mask);
	int xcenter = mask.rows / 2, ycenter = mask.cols / 2;

	for (int x = xcenter; x < img.rows - xcenter; x++) {
		for (int y = ycenter; y < img.cols - ycenter; y++) {
			Mat roi(img, Rect(y - ycenter, x - xcenter, mask.cols, mask.rows));
			bitwise_and(roi, mask, temp);
			cnt = countNonZero(temp);
			dst.at<uchar>(x, y) = (cnt == mcnt) ? 255 : 0;
		}
	}
}

void dilation(Mat img, Mat& dst, Mat mask) {
	Mat temp;
	dst = Mat(img.size(), CV_8U, Scalar(0));
	if (mask.empty()) mask = Mat(3, 3, CV_8UC1, Scalar(1));

	int cnt;
	int xcenter = mask.rows / 2, ycenter = mask.cols / 2;

	for (int x = xcenter; x < img.rows - xcenter; x++) {
		for (int y = ycenter; y < img.cols - ycenter; y++) {
			Mat roi(img, Rect(y - ycenter, x - xcenter, mask.cols, mask.rows));
			bitwise_and(roi, mask, temp);
			cnt = countNonZero(temp);
			dst.at<uchar>(x, y) = (cnt == 0) ? 0 : 255;
		}
	}
}

int main()
{
	Mat src, thImg, mask, dst1, dst2, erosion_dst, dilation_dst;

	src = imread("morph.jpg", IMREAD_GRAYSCALE);

	threshold(src, thImg, 128, 255, THRESH_BINARY);
	imshow("", thImg);

	Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3), Point(-1, -1));

	uchar weights[] = {
		0,1,0,
		1,1,1,
		0,1,0 };

	mask = Mat(3, 3, CV_8UC1, weights);
	erosion(thImg, dst1, mask);
	erode(thImg, erosion_dst, element);

	imshow("User", dst1);
	imshow("OpenCV", erosion_dst);

	Matx<uchar, 3, 3> mask2;
	mask2 << 0, 1, 0, 1, 1, 1, 0, 1, 0;

	dilation(thImg, dst2, (Mat)mask2);
	dilate(thImg, dilation_dst, element);

	imshow("User", dst2);
	imshow("OpenCV", dilation_dst);

	waitKey(0);
	return 0;
}