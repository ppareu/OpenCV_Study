#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat M = Mat::eye(5, 10, CV_64F);
	Mat Row = M.row(1); // index : 1
	cout << "Row = " << endl << Row << endl << endl;

	Mat Col = M.col(M.cols-1);
	cout << "Col = " << endl << Col << endl << endl;

	Mat E = M(Range::all(), Range(1, 3));
	cout << "Range = " << endl << E << endl << endl;
	
	imshow("test", M);
	waitKey(0);
}