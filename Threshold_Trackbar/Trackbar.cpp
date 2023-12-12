#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>


using namespace cv;

Mat src, src_gray, dst;

void Threshold_Demo(int position, void*)
{
	threshold(src_gray, dst, position, 255, 0);
	imshow("결과 영상", dst);
}

int main()
{
	int threshold_value = 0;
	src = imread("lenna.jpg");
	cvtColor(src, src_gray, COLOR_BGRA2GRAY);
	namedWindow("결과 영상", WINDOW_AUTOSIZE);

	createTrackbar("임계값", "결과 영상",
		&threshold_value,
		255, Threshold_Demo);


	Threshold_Demo(threshold_value, 0);

	while (true)
	{
		int c;
		c = waitKey(20);
		if ((char)c == 27) {	// ESC 키가 입력되면 무한 루프 종료
			break;
		}
	}
	return 0;
}
