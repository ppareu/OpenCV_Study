#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("Lenna.jpg");
	if (img.empty()) { cout << "������ ���� �� ����" << endl; return -1; }
	imshow("�÷� ����", img);
	//imwrite("img.jpg", img);

	cout << "���� �� = " << img.rows << endl;
	cout << "���� �� = " << img.cols << endl;
	cout << "����� ũ�� = " << img.size() << endl;
	cout << "��ü ȭ�� ���� = " << img.total() << endl;
	cout << "�� ȭ�� ũ�� = " << img.elemSize() << endl;
	cout << "Ÿ�� = " << img.type() << endl;
	cout << "ä�� = " << img.channels() << endl;

	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	imshow("��� ����", gray); // Ÿ��Ʋ
	//imwrite("gray.jpg", gray);

	cout << "���� �� = " << gray.rows << endl;
	cout << "���� �� = " << gray.cols << endl;
	cout << "����� ũ�� = " << gray.size() << endl;
	cout << "��ü ȭ�� ���� = " << gray.total() << endl;
	cout << "�� ȭ�� ũ�� = " << gray.elemSize() << endl;
	cout << "Ÿ�� = " << gray.type() << endl;
	cout << "ä�� = " << gray.channels() << endl;

	waitKey(0); // â�� ���� �ʴ� �� �������� waiting
	return 0;
}