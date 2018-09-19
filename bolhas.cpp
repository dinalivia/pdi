#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
  Mat image, mask;
  int width, height;
  int nobjects, holes, counter;

  // - Reading image --  
  CvPoint p;
  image = imread("img/bolhas.png",CV_LOAD_IMAGE_GRAYSCALE);
  
  if(!image.data){
    std::cout << "Couldn't load the file correctly\n";
    return(-1);
  }

  width=image.size().width;
  height=image.size().height;

  p.x = 0;
  p.y = 0;

  //  -- Excluding objects that touch the first and last lines --
  for(int i=0; i<height; i++){
    if(image.at<uchar>(0, i) == 255){ 
        floodFill(image,Point(i, 0), 0); 
    }
    if(image.at<uchar>(width-1, i) == 255){ 
        floodFill(image,Point(i, width-1), 0);
    }
  } 

  //  -- Excluding objects that touch the first and last columns --
  for(int i=0; i<width; i++){
    if(image.at<uchar>(i,0) == 255){ 
        floodFill(image,Point(0, i), 0);
    }
    if(image.at<uchar>(i,height-1) == 255){ 
        floodFill(image,Point(height-1, i), 0);
    }
  }

  //  -- Looking for objects and labeling them --
  nobjects=0; 
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(image.at<uchar>(i,j) == 255){ 
        // Found an white object 
        nobjects++;
        p.x=j;
        p.y=i;
        floodFill(image,p,nobjects);
      }
    }
  }

 //  -- Changing background Color --
  floodFill(image,Point(0,0),255);

 //  -- Looking for bubbles with holes --
  holes = 0; counter = 1;
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      if(image.at<uchar>(i,j) == 0 && (int)image.at<uchar>(i,j-1)>counter){ //se encontrar um buraco e já não tiver contado a bolha
  		// Found a bubble with a hole 
  		counter++;
  		p.x=j-1;
  		p.y=i;
  		floodFill(image,p,counter);
  	  }
  	}
  }

  std:: cout << "Number of bubbles: " <<  nobjects << " and number of bubbles with holes: " << counter <<std::endl;

  imwrite("labeling.png", image);
  imshow("janela", image); 
  waitKey();
  return 0;
} 