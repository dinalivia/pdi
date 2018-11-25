# Exercise 6. Laplacian of a Gaussian filter

This example was based on the [filtroespacial.cpp](https://agostinhobritojr.github.io/tutorial/pdi/exemplos/filtroespacial.cpp) algorithm and answers to the proposed exercises at [agostinhobritojr.github.io](https://agostinhobritojr.github.io/tutorial/pdi/#_exerc%C3%ADcios_4).

This program adds one more function to the provided example. Through this new function, the laplacian of the gaussian of a captured image can be calculated by pressing the key "z" and the filtered image is displayed.

Comparing both laplacian and laplacion of gauss filters results, it is possible to conclude that the second filter returns a better filtering, as we can observe more easily the borders and cornes of the image.

```cpp
{{ #include ../../../laplgauss.cpp }}
```
