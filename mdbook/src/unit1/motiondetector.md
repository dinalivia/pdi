# Exercise 5. Motion Detection

Analizing an image histogram, it is possible to observe several aspects of an image or a video, such as motion detection. In this example, we use the correlation between two frames of an video to determine if there was motion or not in it. 

To achive this goal, the OpenCV `CalcHist` function was used to get the histogram of the frame, and the comparison between two frames was perfomed by the `compareHist` function, through the correlation comparison.; 

### What does this program do? 
```
Create a VideoCapture object
Capture frame-by-frame
Calculate histogram by using the OpenCV function 
Display the source and equalized images in a window.
```

Calculates a histogram of a set of arrays:
`C++: void calcHist(const Mat* images, int nimages, const int* channels, InputArray mask, OutputArray hist, int dims, const int* histSize, const float** ranges, bool uniform=true, bool accumulate=false )`
OpenCV implements the function compareHist to perform a comparison. It also offers 4 different metrics to compute the matching, in this program we used the correlation as an metric.
`compareHist(histR, old_hist, CV_COMP_CORREL);`

This example was based on the [histogram.cpp](https://agostinhobritojr.github.io/tutorial/pdi/exemplos/histogram.cpp) algorithm and answers to the proposed exercises at [agostinhobritojr.github.io](https://agostinhobritojr.github.io/tutorial/pdi/#_exerc%C3%ADcios_3).

```cpp
{{ #include ../../../motiondetector.cpp }}
```
