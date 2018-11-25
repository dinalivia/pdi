#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // std::sort
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

char *filename;
Mat image;

vector<KeyPoint> FindingBlobs(Mat &image, int minArea, int maxArea){

  // -------- FINDING BLOBS ----------

	// Setup SimpleBlobDetector parameters.
	SimpleBlobDetector::Params params;

	// Change thresholds
	params.minThreshold = 10;
	params.maxThreshold = 200;

	// Filter by Area.
	params.filterByArea = true;
	params.minArea = minArea;
    params.maxArea = maxArea;

	// Filter by Circularity
	params.filterByCircularity = true;
	params.minCircularity = 0.6;
    params.maxCircularity = 0.9;

	// Filter by Convexity
	params.filterByConvexity = true;
	params.minConvexity = 0.5;
    //params.maxConvexity =  0.5;

	// Filter by Inertiaå
	params.filterByInertia = true;
	params.minInertiaRatio = 0.01;

	// Storage for blobs
	vector<KeyPoint> keypoints;


#if CV_MAJOR_VERSION < 3   // If you are using OpenCV 2

	// Set up detector with params
	SimpleBlobDetector detector(params);

	// Detect blobs
	detector.detect( im, keypoints);
#else 

	// Set up detector with params
	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);   

	// Detect blobs
	detector->detect( image, keypoints);
#endif 

	// Draw detected blobs as red circles.
	// DrawMatchesFlags::DRAW_RICH_KEYPOINTS flag ensures
	// the size of the circle corresponds to the size of blob

    return keypoints;
}

bool point_x_comparator(const KeyPoint& p1, const KeyPoint& p2) {
    return (p1.pt.x < p2.pt.x);
}
bool point_y_comparator(const KeyPoint& p1, const KeyPoint& p2) {
    return (p1.pt.y < p2.pt.y);
}
bool point_comparator(const KeyPoint& p1, const KeyPoint& p2) {
    return (p1.pt.x*1000+p1.pt.y < p2.pt.x*1000+p2.pt.y );
}


int main(int argvc , char** argv){
    
    // ----  open image ----- //

        if (argvc != 2) {
            cerr << "Usage: " << argv[0] << " <img_path>" << endl;
            return 1;
        }

    filename = argv[1];
    image = imread(filename,IMREAD_GRAYSCALE);
	threshold(image, image, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);


    // ----  Resize image ----- //

    Size size(image.cols/2,image.rows/2);
    resize(image,image,size);//resize image


    // ----- Finding big Blobs ------ //

    vector<KeyPoint> keypoints = FindingBlobs(image, 500, 1500);

	Mat im_with_keypoints;
	drawKeypoints( image, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
    rectangle(im_with_keypoints, keypoints[0].pt,keypoints[3].pt, 127, 1, 8, 0);

    // Show blobs
    imwrite("img/gab_findblobs.jpg", im_with_keypoints);
	imshow("keypoints", im_with_keypoints );
	waitKey(0);
    
    // print blobs position
	for(int i=0; i < keypoints.size(); i++){
		printf("[%d,%d] \n", (int)keypoints[i].pt.x, (int)keypoints[i].pt.y);
	}

  
    // ----- Region of interest ------ //

    Rect roi(keypoints[0].pt,keypoints[3].pt);
    Mat ROI(image, roi);
	
	Size size2(174,607);
    resize(ROI,ROI,size2);//resize image


    // ----- Finding small Blobs ------ //

    keypoints = FindingBlobs(ROI, 100, 500);
	drawKeypoints( ROI, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
    //rectangle(im_with_keypoints, keypoints[0].pt,keypoints[3].pt, 127, 1, 8, 0);
    
    // Show blobs
    imwrite("img/gab_findAnswers.jpg", im_with_keypoints);
	imshow("Answers", im_with_keypoints );
	waitKey(0);


    // ------ Saving the CheatSheat ------ //

	stable_sort(keypoints.begin(), keypoints.end(), point_y_comparator); // sorting answers
	
	ofstream myfile;
  	myfile.open ("gabarito.txt");
	for(int i=0; i < keypoints.size(); i++){
		myfile << keypoints[i].pt;
	}
  	myfile.close();



  return 0;
}   

