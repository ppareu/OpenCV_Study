#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main() {
	
	Mat t1 = Mat::zeros(Size(500, 500), CV_8UC1); // 검은 화면
	Mat t2 = Mat::zeros(Size(500, 500), CV_8UC1);
	Mat t3 = Mat::zeros(Size(500, 500), CV_8UC1);

	Point center(t1.cols / 2, t1.rows / 2); // 중심에 표시
	
	int radius = 100; // 원의 반지름

	Scalar white(255, 255, 255); // 원의 색깔
	
	int line = -1; // 원의 선의 굵기 | Ex) -1로 하면 원 안이 채워짐

	circle(t1, center,radius, white, line);
	imshow("Display 1", t1);

	Mat nemo = t2(Range(0, 500), Range(250, 500)) = white;
	imshow("Display 2", t2);

	ellipse(t3, center, Point(40, 100), 180, 360, 0, white, -1);
	imshow("Display 3", t3);

	waitKey(0);
	return 0;
}