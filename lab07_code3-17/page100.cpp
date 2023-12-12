#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

int main() {
	Mat LoadedImage = imread("Lenna.jpg", IMREAD_COLOR);
	
	imshow("Original Image", LoadedImage);
	cout << "이미지의 크기 : " << LoadedImage.size() << endl;

	resize(LoadedImage, LoadedImage, Size(100, 100));
	imshow("New Image", LoadedImage);

	resize(LoadedImage, LoadedImage, Size(200, 300));
	imshow("New2 Image", LoadedImage);

	
	waitKey(0);
	return 0;
}