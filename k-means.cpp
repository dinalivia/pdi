#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <ctime>

using namespace cv;

int main( int argc, char** argv ){
  for(int i = 0; i < 10; i++){

    int nClusters = 20;
    Mat labels;
    int nRounds = 1;
    Mat centers;
    char name[30];

    if(argc!=3){
    exit(0);
    }

    Mat img = imread( argv[1], CV_LOAD_IMAGE_COLOR);
    Mat samples(img.rows * img.cols, 3, CV_32F);

    for( int y = 0; y < img.rows; y++ ){
      for( int x = 0; x < img.cols; x++ ){
        for( int z = 0; z < 3; z++){
          samples.at<float>(y + x*img.rows, z) = img.at<Vec3b>(y,x)[z];
      }
    }
    }

    kmeans(samples,
       nClusters,
       labels,
       TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 10000, 0.0001),
       nRounds,
       KMEANS_RANDOM_CENTERS,
       centers );


    Mat labeled( img.size(), img.type() );
    for( int y = 0; y < img.rows; y++ ){
      for( int x = 0; x < img.cols; x++ ){
      int indice = labels.at<int>(y + x*img.rows,0);
      labeled.at<Vec3b>(y,x)[0] = (uchar) centers.at<float>(indice, 0);
      labeled.at<Vec3b>(y,x)[1] = (uchar) centers.at<float>(indice, 1);
      labeled.at<Vec3b>(y,x)[2] = (uchar) centers.at<float>(indice, 2);
    }
    }
    sprintf(name,  "test%d.jpg", i);
    imwrite(name, labeled);
    //waitKey( 0 );
  }
}