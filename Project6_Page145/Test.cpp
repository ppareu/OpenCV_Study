#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;



int main()
{
	double alpha, beta;
	Mat src1, src2, dst;

	cout << "���İ��� �Է��Ͻÿ�[0.0-1.0] : ";
	cin >> alpha;

	src1 = imread("test1.jpg");
	src2 = imread("test2.jpg");

	beta = (1.0 - alpha);
	
	dst = Mat::zeros(src1.size(), src1.type());
	//addWeighted(src1, alpha, src2, beta, 0.0, dst);
	//for�� 3���� ��ü
	for (int y = 0; y < src1.rows; y++)
	{
		for (int x = 0; x < src1.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				uchar pixel1 = src1.at<Vec3b>(y, x)[c];
				uchar pixel2 = src2.at<Vec3b>(y, x)[c];

				dst.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * pixel1 + beta * pixel2);
			}
		}
	}

	imshow("Original Image1", src1);
	imshow("Original Image2", src2);
	imshow("���� �ռ�", dst);
	waitKey(0);
	return(0);
}