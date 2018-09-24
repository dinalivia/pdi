#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

/**  @function main */
int main( int argc, char** argv )
{
  Mat src, dst;

  string source_window = "Source image";
  string equalized_window = "Equalized Image";

  /// Camera 
  VideoCapture cap;

  //start camera
  cap.open(0);

  if(!cap.isOpened()){
    cout << "Camera not available";
    return -1;
  }

  while(1){
    /// capture image
    cap >> src;

    /// Convert to grayscale
    cvtColor( src, src, CV_BGR2GRAY );

    /// Apply Histogram Equalization
    equalizeHist( src, dst );

    /// Display results
    namedWindow( source_window, CV_WINDOW_NORMAL );
    namedWindow( equalized_window, CV_WINDOW_NORMAL );

    imshow( source_window, src );
    imshow( equalized_window, dst );

    if(waitKey(30) >= 0) break;
    }

  // Closes all the windows
  destroyAllWindows();

  return 0;
}