#include <opencv2/opencv.hpp>

int main()
{
    cv::Mat mat (600, 800, CV_8UC3, cv::Scalar(255, 0, 0));

    cv::imshow("Image", mat);

    while (cv::waitKey(30) != 27) ;

    return 0;
}