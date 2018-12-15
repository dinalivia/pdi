# Exercise 2. K-means proccess

This example was based on the [kmeans.cpp](https://agostinhobritojr.github.io/tutorial/pdi/exemplos/kmeans.cpp) algorithm and answers to the proposed exercises at [agostinhobritojr.github.io]https://agostinhobritojr.github.io/tutorial/pdi/#_exerc%C3%ADcios_8).

The following steps were used to accomplish this effect:

## What does this program do?   
#### The k-means algorithm works according to the following steps:

1. Choose k as the number of classes for the vectors xi of N samples, i = 1,2, ⋯, N.
2. Choose m1, m2, ⋯, mk as initial approximations for the class centers.
3. Sort each sample xi using, for example, a minimum distance classifier (Euclidean distance).
4. Recalculate the averages mj using the result of the previous step.
5. If the new averages are consistent (do not change considerably), finalize the algorithm. If not, recalculate the centers and redo the classification.

```cpp
{{ #include ../../../k-means.cpp }}
```

