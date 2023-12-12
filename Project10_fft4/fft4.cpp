#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void shuffleDFT(Mat& src) {
	int cX = src.cols / 2;
	int cY = src.rows / 2;

	Mat q1(src, Rect(0, 0, cX, cY));
	Mat q2(src, Rect(cX, 0, cX, cY));
	Mat q3(src, Rect(0, cY, cX, cY));
	Mat q4(src, Rect(cX, cY, cX, cY));

	Mat tmp;
	q1.copyTo(tmp);
	q4.copyTo(q1);
	tmp.copyTo(q4);
	q2.copyTo(tmp);
	q3.copyTo(q2);
	tmp.copyTo(q3);
}

void displayDFT(Mat& src, const string& windowDFT) {
	Mat image_array[2] = { Mat::zeros(src.size(), CV_32F), Mat::zeros(src.size(), CV_32F) };
	split(src, image_array);

	Mat mag_image;
	magnitude(image_array[0], image_array[1], mag_image);

	mag_image += Scalar::all(1);
	log(mag_image, mag_image);

	normalize(mag_image, mag_image, 0, 1, NORM_MINMAX);
	imshow(windowDFT, mag_image);
}

Mat getFilter(Size size, int radius) {
	Mat filter = Mat::ones(size, CV_32FC2);
	circle(filter, size / 2, radius, Vec2f(0, 0), -1); // Circular filter
	return filter;
}

int main() {
	Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Error: Image not loaded." << endl;
		return -1;
	}

	imshow("Original", src);

	Mat src_float;
	src.convertTo(src_float, CV_32FC1, 1.0 / 255.0);
	Mat dft_image;
	dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
	shuffleDFT(dft_image);

	Mat highpass1 = getFilter(dft_image.size(), 2);
	Mat highpass2 = getFilter(dft_image.size(), 5);
	Mat highpass3 = getFilter(dft_image.size(), 10);

	Mat result1, result2, result3;
	multiply(dft_image, highpass1, result1);
	multiply(dft_image, highpass2, result2);
	multiply(dft_image, highpass3, result3);

	displayDFT(result1, "DFT (Radius 2)");
	displayDFT(result2, "DFT (Radius 5)");
	displayDFT(result3, "DFT (Radius 10)");

	Mat inverted_image1, inverted_image2, inverted_image3;
	shuffleDFT(result1);
	shuffleDFT(result2);
	shuffleDFT(result3);

	idft(result1, inverted_image1, DFT_SCALE | DFT_REAL_OUTPUT);
	idft(result2, inverted_image2, DFT_SCALE | DFT_REAL_OUTPUT);
	idft(result3, inverted_image3, DFT_SCALE | DFT_REAL_OUTPUT);

	imshow("Inverted (Radius 2)", inverted_image1);
	imshow("Inverted (Radius 5)", inverted_image2);
	imshow("Inverted (Radius 10)", inverted_image3);

	waitKey(0);
	return 0;
}

