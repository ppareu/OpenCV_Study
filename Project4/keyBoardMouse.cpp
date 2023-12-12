#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/*void  onMouse(int event, int x, int y, int flags, void* param) {
	if (event == EVENT_LBUTTONDOWN) {
		Mat& image = *(Mat*)(param);
		circle(image, Point(x, y), 50, Scalar(0, 255, 0), 10);
		putText(image, "I found a dog!", Point(x-300, y), FONT_HERSHEY_DUPLEX, 1.0, 255, 2);
		imshow("src", image);
	}
	else if (event == EVENT_RBUTTONDOWN) {}
	else if (event == EVENT_MBUTTONDOWN) {}
	else if (event == EVENT_MOUSEMOVE) {}
}

int main() {
	Mat src = imread("dog.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	imshow("src", src);

	setMouseCallback("src", onMouse, &src);
	waitKey(0);
	return(0);
}*/

int main() {
	Mat img;
	img = imread("dog.jpg", IMREAD_COLOR);
	if (img.empty()) { cout << "영상을 읽을 수 없음" << endl; }

	imshow("img", img);
	int x = 300;
	int y = 200;

	while (1) {
		int key = waitKey(100);
		if (key == 'q') break; // 종료
		else if (key == 'a')
			x -= 10;
		else if (key == 'w')
			y -= 10;
		else if (key == 'd')
			x += 10;
		else if (key == 's')
			y += 10;

		circle(img, Point(x, y), 100, Scalar(0, 255, 255), 5);
		imshow("img", img);
	}
	return 0;
}