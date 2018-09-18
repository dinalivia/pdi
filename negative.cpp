#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
  Mat image;
  int pxl;

  image= imread("img/camera__.jpg",CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data)
    cout << "nao abriu camera__.jpg" << endl;

  namedWindow("janela",WINDOW_AUTOSIZE);

  for(int i=100;i<200;i++){
    for(int j=100;j<200;j++){
      pxl = image.at<uchar>(i,j);
      image.at<uchar>(i,j) = 255 - pxl;
    }
  }
  
  imshow("janela", image);  
  waitKey();

  return 0;
}   