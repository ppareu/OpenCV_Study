#include <opencv2/opencv.hpp>
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
	Mat src, dst1, dst2, dst3, open, close, th_img;
	src = imread("letterj.png", IMREAD_GRAYSCALE);

	Mat saltpepper_noise = Mat::zeros(src.rows, src.cols, CV_8U);
	randu(saltpepper_noise, 0, 255);

	Mat black = saltpepper_noise < 30;
	Mat white = saltpepper_noise > 225;

	Mat saltpepper_img = src.clone();
	saltpepper_img.setTo(255, white);
	saltpepper_img.setTo(0, black);

	threshold(saltpepper_img, th_img, 128, 255, THRESH_BINARY);
	imshow("src", th_img);

	Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3));

	erosion(th_img, dst1, element);
	dilate(dst1, open, element);
	imshow("Opening Demo", open);

	dilate(th_img, dst3, element);
	erosion(dst3, close, element);
	imshow("Closing Demo", close);
	waitKey(0);
	return 0;
}