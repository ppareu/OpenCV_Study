#define _CRT_SECURE_NO_WARRINGS
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	int startROW, endROW = 0;
	int r, g, b;

	Mat img = imread("opencv.png");
	if (img.empty()) {
		cout << "영상을 읽을 수 없음" << endl; return -1;
	}
	imshow("img", img);

	cout << "행렬의 크기 : " << img.size() << endl;

	cout << "시작 행 입력 : ";
	cin >> startROW;

	cout << "끝 행 입력 : ";
	cin >> endROW;

	for (; startROW <= endROW; startROW++) {
		cout << endl << startROW << "행" << endl;

		for (int col = 0;  col < img.cols; col++) {
			b = img.at<Vec3b>(startROW, col)[0]; //blue channel
			g = img.at<Vec3b>(startROW, col)[1]; //green channel
			r = img.at<Vec3b>(startROW, col)[2]; //red channel

			cout << b << " " << g << " " << r << " ";
		}
	}

	waitKey(0);
	return 0;

}