# Exercise 2. Pointillism art

This section uses Canny Edge Detection, developed by John F. Canny in 1986, to create pointillism arts. 
To achieve this goal, we can simulate a painting by drawing circles that work out as a pointillism art. The example below perform the desired effect of pointillism through image processing.

The following steps were used to accomplish this effect:

## What does this program do?   
#### The program allows 4 different adjustments in the image
1. Apply canny algorithm on an image.
2. Use the edges identified by the canny algorithm to draw circles on them;
3. Uses the Canny threshold  
Increasing Canny algorithm’s threshold and, for each new pair generated, draw increasingly less small circles on each position found.
3. Regulate the variable C, which controls the slope of the function as it transitions between γLγL and γHγH.
4. Adjust the variable D0D0;

Use the borders identified by the canny algorithm to draw on the respectively points of the generated image;

Increasing Canny algorithm’s threshold and, for each new pair generated, draw increasingly less small circles on each position found.

I chose the second one, due to it’s practicity to implement and that we could easily input a trackbar to increase or decrease the threshold of the borders of the algorithm, so it is seen on the following gif:

This example implements an homomorphic filter based on the [dft.cpp](https://agostinhobritojr.github.io/tutorial/pdi/exemplos/dft.cpp) algorithm and answers to the proposed exercises at [agostinhobritojr.github.io](https://agostinhobritojr.github.io/tutorial/pdi/#_exerc%C3%ADcios_6).

The Homomorphic filter is based on the following function:

![Equation](../img/equation_homomorphic.png "Equation")

## What does this program do?   
#### The program allows 4 different adjustments in the image
1. Regulate the low frequency component γLγL (referring to illumination);
2. Regulate the high frequency component γHγH (referring to reflectance);
3. Regulate the variable C, which controls the slope of the function as it transitions between γLγL and γHγH.
4. Adjust the variable D0D0;

Original image
![Original image](../img/original_homomorphic.png "Original")

Filtered image
![Filtered image](../img/filtered_homomorphic.png "Filtered")

```cpp
{{ #include ../../../homomorphic.cpp }}
```

git