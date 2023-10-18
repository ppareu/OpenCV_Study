#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image;
	image = imread("squid.jpeg", IMREAD_COLOR);
	if (image.empty()) { cout << "영상을 읽을 수 없음" << endl; }

	imshow("출력 영상", image); // 타이틀
	waitKey(0); // 창을 닫지 않는 한 무한으로 waiting
	return 0;
}