//201995039 박현빈
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

Mat convolution(const Mat& inputImage, const Mat& mask) {
    Mat result;
    filter2D(inputImage, result, -1, mask);
    return result;
}

int main() {
    Mat src;
    int scale = 1;
    int delta = 0;
    src = imread("Lenna.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) { return -1; }

    // 평균값 마스크 (블러링)
    Mat averageMask = Mat::ones(3, 3, CV_32F) / 9.0;

    // 샤프닝 마스크
    Mat sharpenMask = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);

    // 사용자 정의 컨볼루션 함수를 사용하여 블러링을 적용
    Mat blurredImage = convolution(src, averageMask);

    // 사용자 정의 컨볼루션 함수를 사용하여 샤프닝을 적용
    Mat sharpenedImage = convolution(src, sharpenMask);

    imshow("Original Image", src);
    imshow("Blurred Image", blurredImage);
    imshow("Sharpened Image", sharpenedImage);
    waitKey(0);
    return 0;
}
