// P67 06번 문제

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void  onMouse(int event, int x, int y, int flags, void* param) {
	if (event == EVENT_RBUTTONDOWN) {
		Mat& image = *(Mat*)(param);
		rectangle(image, Point(x, y), Point(x+100, y+100), Scalar(0, 255, 255), 5, LINE_AA);
		imshow("src", image);
	}
	else if (event == EVENT_LBUTTONDOWN) {
		Mat& image = *(Mat*)(param);
		circle(image, Point(x, y), 100, Scalar(128, 0, 128), 3);
		imshow("src", image);
	}
	else if (event == EVENT_MBUTTONDOWN) {}
	else if (event == EVENT_MOUSEMOVE) {}
}

int main() {
	// 800 * 600 윈도우 창
	Mat src = Mat(600, 800, CV_8UC3, Scalar(211, 211, 211));
	if (src.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	imshow("src", src);

	setMouseCallback("src", onMouse, &src);
	waitKey(0);
	return(0);
}