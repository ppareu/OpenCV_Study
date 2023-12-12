#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat A = imread("image2.jpg");
	Mat B = A;
	Mat C = A.clone();
	Mat D; A.copyTo(D);
	imshow("window 1", A);

	flip(B, B, 0);
	cout << "B�� �ݻ��Ŵ" << endl;
	imshow("window 2", A);

	flip(C, C, 0);
	cout << "C�� �ݻ��Ŵ" << endl;
	imshow("window 3", A);

	flip(D, D, 0);
	cout << "D�� �ݻ��Ŵ" << endl;
	imshow("window 4", A);

	waitKey(0);
	return 0;
}