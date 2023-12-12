//201995039 박현빈
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

void histo_stretch(Mat& image, Mat& new_image) {
    int low = 0;
    int high = 255;

    double minVal, maxVal;
    minMaxLoc(image, &minVal, &maxVal);

    float scale = (high - low) / (maxVal - minVal);

    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            int output = saturate_cast<uchar>(low + (image.at<uchar>(y, x) - minVal) * scale);
            new_image.at<uchar>(y, x) = output;
        }
    }
}

int main() {
    Mat image = imread("crayfish.jpg", IMREAD_GRAYSCALE);
    Mat new_image = Mat::zeros(image.size(), image.type());

    histo_stretch(image, new_image);

    imshow("입력 영상", image);
    imshow("결과 영상", new_image);
    waitKey();
    return 0;
}
