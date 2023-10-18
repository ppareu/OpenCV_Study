#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat image = imread("Lenna.jpg", IMREAD_COLOR);
	if (image.empty()) { cout << "������ ���� �� ����" << endl; }
	//imshow("�÷� ����", image);

	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);
	//imshow("��� ����", gray); // Ÿ��Ʋ
	imwrite("gray.jpg", gray);

	Mat dst;
	flip(image, dst, 1);// Y��
	//imshow("������ ����", dst);
	imwrite("dst.jpg", dst);

	Mat dst1;
	flip(image, dst1, 0); // X��
	//imshow("������ ����1", dst1);
	imwrite("dst1.jpg", dst1); 
	
	Mat dst2;
	flip(image, dst2, -1); // �ݹ���(?)
	//imshow("������ ����2", dst2);
	imwrite("dst2.jpg", dst2);

	// Ÿ�� ����� ����1
	Mat a1 = Mat(400, 600, CV_8UC3, Scalar(0, 0, 0));

	// a1, Point(300, 200) ��ġ, Point(100, 60) ũ��, 0 ����, 360 ���� ����, 0 ��������, Scalar(255, 255, 0) ����, 5 �� ����
	ellipse(a1, Point(300, 200), Point(100, 60), 135, 360, 0, Scalar(255, 255, 0), 5);

	line(a1, Point(100, 100), Point(300, 300), Scalar(0, 0, 255), 7);
	rectangle(a1, Point(250, 30), Point(450, 200), Scalar(0, 255, 0), 5);
	circle(a1, Point(100, 300), 60, Scalar(255, 0, 0), 3);

	imshow("Ÿ�� ����1", a1);

	waitKey(0); // â�� ���� �ʴ� �� �������� waiting
	return 0;
}