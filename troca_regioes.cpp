#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
  Mat image = imread("img/camera__.jpg",CV_LOAD_IMAGE_GRAYSCALE);
 
  if(!image.data)
    cout << "nao abriu camera__.jpg" << endl;

  namedWindow("janela",WINDOW_AUTOSIZE);

  imshow("janela", image);  
  waitKey();

  int x = 0, y = 0, width = image.rows/2, height = image.cols/2;
  Mat image2; 
  image.copyTo(image2);

 // creating Regions of Interest
  Rect rois[4] = { 
        Rect(     0,      0, width, height),
        Rect(width,      0, width, height),
        Rect(     0, height, width, height),
        Rect(width, height, width, height)
        };

  // copying regions and swapping them   
  Mat region1 (image, rois[3]);
  region1.copyTo(image2(rois[0]));

  Mat region2 (image, rois[2]);
  region2.copyTo(image2(rois[1]));

  Mat region3 (image, rois[1]);
  region3.copyTo(image2(rois[2]));

  Mat region4 (image, rois[0]);
  region4.copyTo(image2(rois[3]));

  imwrite("swapping.jpg", image2);
  imshow("janela", image2);  
  waitKey();

  return 0;
}   