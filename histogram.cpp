#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat image;
  int width, height;
  VideoCapture cap;
  vector<Mat> planes;
  Mat histR, motion, old_hist;
  int nbins = 64;
  float range[] = {0, 256};
  const float *histrange = { range };
  bool uniform = true;
  bool acummulate = false;

  // Start Camera
  cap.open(0);
  
  if(!cap.isOpened()){
    cout << "cameras indisponiveis";
    return -1;
  }
  
  // image size
  width  = cap.get(CV_CAP_PROP_FRAME_WIDTH);
  height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

  cout << "largura = " << width << endl;
  cout << "altura  = " << height << endl;

  // mat for histogram - analyzing only red here.
  int histw = nbins, histh = nbins/2;
  Mat histImgR(histh, histw, CV_8UC3, Scalar(0,0,0));

  // Motion alert
  motion = imread("img/motion_detected.png",CV_LOAD_IMAGE_COLOR);
  if(!motion.data)
    cout << "couldn't load image" << endl;

  namedWindow("window",WINDOW_AUTOSIZE);

  // faz uma vez para poder, calcular a primeira correlação, dar continuidade dentro do loop
  cap >> image;
  split (image, planes);
  calcHist(&planes[0], 1, 0, Mat(), histR, 1,
             &nbins, &histrange,
             uniform, acummulate);
  normalize(histR, histR, 0, histImgR.rows, NORM_MINMAX, -1, Mat());
  
  histR.copyTo(old_hist);

  while(1){
    histR.copyTo(old_hist);
    cap >> image;
    split (image, planes);
    calcHist(&planes[0], 1, 0, Mat(), histR, 1,
             &nbins, &histrange,
             uniform, acummulate);

    normalize(histR, histR, 0, histImgR.rows, NORM_MINMAX, -1, Mat());

    histImgR.setTo(Scalar(0));
    
    double compare = compareHist(histR, old_hist, CV_COMP_CORREL);
    cout << compare << endl;

    if ( compare < 0.01)
    {
      cout << "Motion detected\n";
      motion.copyTo(image(Rect(0, histh, motion.size().width, motion.size().height)));
    }

    for(int i=0; i<nbins; i++){
      line(histImgR,
           Point(i, histh),
           Point(i, histh-cvRound(histR.at<float>(i))),
           Scalar(0, 0, 255), 1, 8, 0);
    }
    histImgR.copyTo(image(Rect(0, 0       ,nbins, histh)));
    imshow("image", image);
    if(waitKey(30) >= 0) break;
    old_hist.copyTo(histR);

  }
  return 0;
}
