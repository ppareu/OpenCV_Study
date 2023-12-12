#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {

	Mat A = imread("image2.jpg");
	Mat B = imread("logo.png");

	int x = (A.cols - B.cols) / 2; // 중앙 x 좌표 계산
	int y = (A.rows - B.rows) / 2; // 중앙 y 좌표 계산

	Mat roi(A, Rect(A.cols - B.cols, A.rows - B.rows, B.cols, B.rows)); // 오른쪽 하단
	//Mat roi1(A, Rect(x, y, B.cols, B.rows)); // 가운데
	Mat roi1(A, Rect((A.cols) / 2, (A.rows) / 2, B.cols, B.rows)); // 가운데
	Mat roi2(A, Rect(0, 0, B.cols, B.rows)); // 왼쪽 상단
	Mat roi3(A, Rect(A.cols - B.cols, 0, B.cols, B.rows)); // 오른쪽 상단
	Mat roi4(A, Rect(0, A.rows - B.rows, B.cols, B.rows)); // 왼쪽 하단

	B.copyTo(roi);
	B.copyTo(roi1);
	B.copyTo(roi2);
	B.copyTo(roi3);
	B.copyTo(roi4);
	imshow("result", A);
	waitKey(0);
	return 0;
}