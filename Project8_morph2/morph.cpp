#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

bool check_match(Mat img, Point start, Mat mask, int mode = 0) {
	for (int u = 0; u < mask.rows; u++)
	{
		for (int v = 0; v < mask.cols; v++)
		{
			Point pt(v, u);
			int m = mask.at<uchar>(pt);
			int p = img.at<uchar>(start + pt);

			bool ch = (p == 255);
			if (m == 1 && ch == mode)
				return false;
		}
	}
	return true;
}

void erosion(Mat img, Mat& dst, Mat mask) {
	dst = Mat(img.size(), CV_8U, Scalar(0));
	if (mask.empty()) mask = Mat(3, 3, CV_8UC1, Scalar(1));


	Point h_m = mask.size() / 2;
	for (int i = h_m.y; i < img.rows - h_m.y; i++)
	{
		for (int j = h_m.x; j < img.cols - h_m.x; j++)
		{
			Point start = Point(j, i) - h_m;
			bool check = check_match(img, start, mask, 0);
			dst.at<uchar>(i, j) = (check) ? 255 : 0;
		}
	}
}

void dilation(Mat img, Mat& dst, Mat mask) {
	dst = Mat(img.size(), CV_8U, Scalar(0));
	if (mask.empty()) mask = Mat(3, 3, CV_8UC1, Scalar(0));

	Point h_m = mask.size() / 2;

	for (int i = h_m.y; i < img.rows - h_m.y; i++)
	{
		for (int j = h_m.x; j < img.cols - h_m.x; j++)
		{
			Point start = Point(j, i) - h_m;
			bool check = check_match(img, start, mask, 1);
			dst.at<uchar>(i, j) = (check) ? 0 : 255;
		}
	}
}

int main()
{
	Mat image = imread("morph.jpg", IMREAD_GRAYSCALE);

	CV_Assert(image.data);

	Mat th_img, dst1, dst2, dst3, dst4;
	threshold(image, th_img, 128, 255, THRESH_BINARY); // 이진화

	uchar data[] = { 0,1,0,
					1, 1, 1,
					0, 1, 0 };
	Mat mask2(3, 3, CV_8UC1, data);

	erosion(th_img, dst3, (Mat)mask2);
	morphologyEx(th_img, dst4, MORPH_ERODE, mask2);

	Matx<uchar, 3, 3> mask;

	mask << 0, 1, 0, 1, 1, 1, 0, 1, 1;

	dilation(th_img, dst1, (Mat)mask);

	morphologyEx(th_img, dst2, MORPH_DILATE, mask);

	imshow("image", image);
	imshow("OpenCV_dilation - 침식", dst2);
	imshow("OpenCV_dilation - 팽창", dst4);

	waitKey(0);

	return 0;
}

/*
import numpy as np, cv2

def erode(img, mask=None):
    dst = np.zeros(img.shape, np.uint8)
    if mask is None: mask = np.ones((3, 3), np.uint8)
    ycenter, xcenter = np.divmod(mask.shape[:2], 2)[0]

    mcnt = cv2.countNonZero(mask)

    for i in range(ycenter, img.shape[0] - ycenter):
        for j in range(xcenter, img.shape[1] - xcenter):
            y1, y2 = i - ycenter, i + ycenter + 1
            x1, x2 = j - xcenter, j +xcenter + 1
            roi = img[y1:y2, x1:x2]
            temp = cv2.bitwise_and(roi, mask)
            cnt = cv2.countNonZero(temp)
            dst[i, j] = 255 if (cnt == mcnt) else 0
    return dst

image = cv2.imread("morph.jpg", cv2.IMREAD_GRAYSCALE)
if image is None: raise Exception("영상파일 읽기 오류")

*/