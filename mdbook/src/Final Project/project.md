# Multiple choice test autocorrection

This is the project.
This is the template [Gabarito](https://dinalivia.github.io/pdi/img/Gabarito.png)

The Homomorphic filter is based on the following function:

![gabarito](../img/Gabarito.png "gabarito")

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

