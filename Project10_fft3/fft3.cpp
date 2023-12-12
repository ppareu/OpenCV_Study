/*#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void shuffleDFT(Mat& src)
{
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

void displayDFT(Mat& src) {
	Mat image_array[2] = { Mat::zeros(src.size(), CV_32F), Mat::zeros(src.size(), CV_32F) };

	split(src, image_array);

	Mat mag_image;

	magnitude(image_array[0], image_array[1], mag_image);

	mag_image += Scalar::all(1);
	log(mag_image, mag_image);

	normalize(mag_image, mag_image, 0, 1, NORM_MINMAX);
	imshow("DFT", mag_image);
	waitKey(0);
}

Mat getFilter25(Size size) {
	Mat filter(size, CV_32FC2, Vec2f(0, 0));
	circle(filter, size / 2, 25, Vec2f(1, 1), -1); // 원 모양 필터
	return filter;
}

Mat getFilter50(Size size) {
	Mat filter(size, CV_32FC2, Vec2f(0, 0));
	circle(filter, size / 2, 50, Vec2f(1, 1), -1); // 원 모양 필터
	return filter;
}

Mat getFilter100(Size size) {
	Mat filter(size, CV_32FC2, Vec2f(0, 0));
	circle(filter, size / 2, 100, Vec2f(1, 1), -1); // 원 모양 필터
	return filter;
}

int main() {
	Mat src = imread("lenna.jpg", IMREAD_GRAYSCALE);
	Mat src_float;
	imshow("original", src);

	src.convertTo(src_float, CV_32FC1, 1.0 / 255.0);
	Mat dft_image;
	dft(src_float, dft_image, DFT_COMPLEX_OUTPUT);
	shuffleDFT(dft_image);

	Mat lowpass1 = getFilter25(dft_image.size());
	Mat lowpass2 = getFilter50(dft_image.size());
	Mat lowpass3 = getFilter100(dft_image.size());
	Mat result1, result2, result3;

	multiply(dft_image, lowpass1, result1);
	multiply(dft_image, lowpass2, result2);
	multiply(dft_image, lowpass3, result3);

	displayDFT(result1);
	displayDFT(result2);
	displayDFT(result3);

	Mat inverted_image1, inverted_image2, inverted_image3;
	shuffleDFT(result1);
	shuffleDFT(result2);
	shuffleDFT(result3);
	idft(result1, inverted_image1, DFT_SCALE | DFT_REAL_OUTPUT);
	idft(result2, inverted_image2, DFT_SCALE | DFT_REAL_OUTPUT);
	idft(result3, inverted_image3, DFT_SCALE | DFT_REAL_OUTPUT);
	imshow("inverted25", inverted_image1);
	imshow("inverted50", inverted_image2);
	imshow("inverted100", inverted_image3);

	waitKey(0);
	return 0;
}*/

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
	Mat filter(size, CV_32FC2, Vec2f(0, 0));
	circle(filter, size / 2, radius, Vec2f(1, 1), -1); // Circular filter
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

	Mat lowpass1 = getFilter(dft_image.size(), 25);
	Mat lowpass2 = getFilter(dft_image.size(), 50);
	Mat lowpass3 = getFilter(dft_image.size(), 100);

	Mat result1, result2, result3;
	multiply(dft_image, lowpass1, result1);
	multiply(dft_image, lowpass2, result2);
	multiply(dft_image, lowpass3, result3);

	displayDFT(result1, "DFT Filtered (Radius 25)");
	displayDFT(result2, "DFT Filtered (Radius 50)");
	displayDFT(result3, "DFT Filtered (Radius 100)");

	Mat inverted_image1, inverted_image2, inverted_image3;
	shuffleDFT(result1);
	shuffleDFT(result2);
	shuffleDFT(result3);

	idft(result1, inverted_image1, DFT_SCALE | DFT_REAL_OUTPUT);
	idft(result2, inverted_image2, DFT_SCALE | DFT_REAL_OUTPUT);
	idft(result3, inverted_image3, DFT_SCALE | DFT_REAL_OUTPUT);

	imshow("Inverted (Radius 25)", inverted_image1);
	imshow("Inverted (Radius 50)", inverted_image2);
	imshow("Inverted (Radius 100)", inverted_image3);

	waitKey(0);
	return 0;
}
