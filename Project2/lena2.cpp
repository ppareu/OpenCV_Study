#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image;
	image = imread("squid.jpeg", IMREAD_COLOR);
	if (image.empty()) { cout << "������ ���� �� ����" << endl; }

	imshow("��� ����", image); // Ÿ��Ʋ
	waitKey(0); // â�� ���� �ʴ� �� �������� waiting
	return 0;
}