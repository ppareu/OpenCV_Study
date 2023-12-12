//20195039 박현빈
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("crayfish.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) { return -1; }

    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange = { range };
    bool uniform = true, accumulate = false;

    // 1. 히스토그램 계산
    Mat hist;
    calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);

    // 2. 누적 히스토그램 계산
    Mat cumulativeHist = Mat::zeros(histSize, 1, CV_32F);
    cumulativeHist.at<float>(0) = hist.at<float>(0);
    for (int i = 1; i < histSize; i++) {
        cumulativeHist.at<float>(i) = cumulativeHist.at<float>(i - 1) + hist.at<float>(i);
    }

    // 3. 누적 히스토그램 정규화
    float totalPixels = src.rows * src.cols;
    cumulativeHist /= totalPixels;

    // 4. 이미지 변환
    Mat equalized = src.clone();
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            int pixelValue = src.at<uchar>(y, x);
            float newPixelValue = cumulativeHist.at<float>(pixelValue) * 255;
            equalized.at<uchar>(y, x) = static_cast<uchar>(newPixelValue);
        }
    }

    imshow("Original Image", src);
    imshow("Equalized Image", equalized);
    waitKey(0);
    return 0;
}
