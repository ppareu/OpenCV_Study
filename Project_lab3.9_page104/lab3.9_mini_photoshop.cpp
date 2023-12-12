// 이름 : 박현빈 학번 : 201995039
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat img, roi;
int mx1, my1, mx2, my2; // 마우스로 지정한 사각형의 자표
bool cropping = false; // 사각형 선택 중임을 나타내는 플래그 변수

void onMouse(int event, int x, int y, int flags, void* param) {
	Mat temp = img.clone();
	if (event == EVENT_LBUTTONDOWN) {
		mx1 = x;
		my1 = y;
		cropping = true;
	} else if (event == EVENT_MOUSEMOVE && cropping) {
		mx2 = x;
		my2 = y;

		rectangle(temp, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0));
		imshow("image", temp);
	} else if (event == EVENT_LBUTTONUP) {
		cropping = false;

		rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0));
		
		imshow("image", img);
		img = temp.clone();
	}
}

int main() {
	img = imread("Lenna.jpg");
	imshow("image", img);
	Mat clone = img.clone();

	setMouseCallback("image", onMouse);

	while (1) {
		int key = waitKey(100);
		if (key == 'q') break;
		else if (key == 'c') {
			roi = clone(Rect(mx1, my1, mx2 - mx1, my2 - my1));
			imwrite("result.jpg", roi);

			imshow("roi", roi);
		}
	}
	return 0;
}