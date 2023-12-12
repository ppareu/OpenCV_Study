#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat img = imread("Lenna.jpg", IMREAD_COLOR);
	cout << "영상의 크기 : " << img.rows << " * " << img.cols << endl << endl;

	if (img.isContinuous()) {
		img.reshape(1, img.cols * img.rows);
	}
	imshow("reshape Image", img);

	waitKey(0);
	return 0;
}