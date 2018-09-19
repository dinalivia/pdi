# Exercise 1 - Negative of a region

This is the first exercise using OpenCV image manipulation. In this example, we'll be reading and processing a region of a given image in order to create a negative effect on it. To achive this goal, the following fomula is used to invert the color of the pixels: `pixel_color = 255 - pixel_color`. 

As the image used is in grayscale, we will be aplying it for one channel only. The region is seleted by a couple of for-loops that go through an area within the image, inverting its pixels, as shown below.

![Negative Region](../img/camera__.jpg "Negative region")
![Negative Region](../img/negative.jpg "Negative region")


```cpp
{{ #include ../../../negative.cpp }}
```



