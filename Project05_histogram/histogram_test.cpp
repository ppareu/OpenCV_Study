#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void drawHist(int histogram[]) {
	int hist_w = 512;
	int hist_h = 400;
	int bin_w = cvRound((double)hist_w / 256);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255,255,255));

	int max = histogram[0];
	int PixelMax = 0;
	for (int i = 1; i < 256; i++) {
		if (max < histogram[i]) {
			max = histogram[i];
			PixelMax = i;
		}		
	}
	
	cout << endl << endl << "MAX : " << max << endl;
	cout << endl << endl << "pixelMax : " << PixelMax << endl << endl;

	for (int i = 0; i < 256; i++) {
		histogram[i] = floor(((double)histogram[i] / max) * histImage.rows);
	}

	for (int i = 0; i < 256; i++) {
		line(histImage, Point(bin_w * (i), hist_h), 
			Point(bin_w * (i), hist_h - histogram[i]), 
			Scalar(0, 0, 255));
	}

	imshow("Histogram", histImage);

}

int main() {
	Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Input Image", src);
	int histograme[256] = { 0 };

	for (int y = 0; y < src.rows; y++)
		for (int x = 0; x < src.cols; x++)
			histograme[(int)src.at<uchar>(y, x)]++;

	cout << endl << endl;
	
	for (int count : histograme) {
		cout << count << ",";
	}
		
	drawHist(histograme);
	waitKey(0);
	return 0;
}