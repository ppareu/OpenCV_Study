//201995039 박현빈
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img1 = Mat::zeros(Size(300, 300), CV_8UC1);
	Mat img2 = Mat::zeros(Size(300, 300), CV_8UC1);

	Point center(img1.cols / 2, img1.rows / 2); // 원의 중심 좌표
	int radius = 100; // 반지름
	Scalar color = Scalar(255, 255, 255); // 흰색
	int thickness = -1; // 원을 채웁니다 (음수 값)
	circle(img1, center, radius, color, thickness);
	
	imshow("image 1", img1);

	Mat t2 = img2(Range(0, 300), Range(0, 150)); //앞 부분 세로, 뒷 부분 가로
	t2 = 255;
	imshow("image 2", img2);

	Mat result;
	
	bitwise_and(img1, img2, result);
	imshow("AND", result);
	bitwise_or(img1, img2, result);
	imshow("OR", result);
	bitwise_xor(img1, img2, result);
	imshow("XOR", result);
	bitwise_not(img1, result);
	imshow("NOT", result);
	
	waitKey(0);
	return 0;
}