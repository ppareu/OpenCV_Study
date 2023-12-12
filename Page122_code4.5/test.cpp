#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	double alpha = 1.0;
	int beta = 0;
	Mat img = imread("contrast.jpg", IMREAD_GRAYSCALE);
	Mat oimg = Mat::zeros(img.size(), img.type());
	cout << "알파값을 입력하시오 : [1.0-3.0]: "; cin >> alpha;
	cout << "베타값을 입력하시오 : [0-100]: "; cin >> beta;
	/*
	for (int y = 0; y < img.rows; y++) {
		for (int x = 0; x < img.cols; x++) {
			for(int c = 0; c < 3; c++)
				oimg.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * (img.at<Vec3b>(y, x)[c]) + beta);
		}
	}
	*/

	img.convertTo(oimg, -1, alpha, beta);
	imshow("Original Image", img);
	imshow("New Image", oimg);
	waitKey();
	return 0;
}