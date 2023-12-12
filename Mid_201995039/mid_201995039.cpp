#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img2, temp;
int mx1, my1, mx2, my2;
bool cropping = false;

void onMouse(int event, int x, int y, int flags, void* param){
	if (event == EVENT_RBUTTONDOWN) {
		Mat& img = *(Mat*)(param);
		rectangle(img, Point(x, y), Point(x+50, y+50), Scalar(0, 0, 255), -1);
		imshow("img1", img);
		cout << "x : " << x << endl;
		cout << "y : " << y << endl;
	}
	else if (flags & EVENT_FLAG_LBUTTON) {
		Mat& img = *(Mat*)(param);
		rectangle(img, Point(x, y), Point(x + 50, y + 50), Scalar(255), -1);
		imshow("img1", img);
	}
}

void dMouse(int event1, int x1, int y1, int flags1, void* param1) {
    if (event1 == EVENT_LBUTTONDOWN) {
        mx1 = x1;
        my1 = y1;
        cropping = true;
    }
    else if (event1 == EVENT_MOUSEMOVE && cropping) {
        mx2 = x1;
        my2 = y1;
        imshow("img2", img2);
        Mat temp = img2.clone();

        int Lx = std::min(mx1, mx2);
        int Ly = std::min(my1, my2);
        int width = std::abs(mx2 - mx1);
        int height = std::abs(my2 - my1);

        if (width > 0 && height > 0) {
            Mat LightImg = temp(Rect(Lx, Ly, width, height));
            for (int i = 0; i < LightImg.rows; i++) {
                for (int j = 0; j < LightImg.cols; j++) {
                    LightImg.at<uchar>(i, j) = std::min(255, LightImg.at<uchar>(i, j) + 100);
                }
            }
        }

        rectangle(temp, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(255));
        imshow("img2", temp);
    }
    else if (event1 == EVENT_LBUTTONUP) {
        cropping = false;
    }
}


int main() {
	Mat img1(Size(800, 600), CV_8UC3, Scalar(255, 255, 255));
	imshow("img1", img1);
	setMouseCallback("img1", onMouse, &img1);

	img2 = imread("Lenna.jpg", IMREAD_GRAYSCALE);
	imshow("img2", img2);
	Mat clone = img2.clone();
	setMouseCallback("img2", dMouse);

    Mat img3 = imread("rgbimage.png");
    imshow("img3", img3);

    Mat bgr[3];
	waitKey(0);
	return 0;
}