# Array Dependence Analysis

gprof is the default profiler that gcc uses. A profiler is a tool that helps identify where a program spends its time, at the level of individual statements. The common outcome of most profiling studies show most of the program time is spent in loops.

For the code snippet 
```
for(i=0; i<N; i++) 
    a[i] = b[i] + c[i];
```
the speedup is scaled to a factor 1/N, if run on N threads. If N >> Number of cores, speedup is determined by the iteration space of the loop.

But if the code becomes 
```
for(i = 1; i < N; i++) 
    a[i] = a[i-1] + c[i];
```
there exists a true dependence and a loop carried dependence (As the dependence translates to multiple iterations).

However, if the code becomes 
```
for(i = 2; i<N; i++) 
    a[i] = a[i-2] + c[i];
```
the loop can be parallelised by setting one thread computing the even iterations and another computing the odd iterations. If i begins from 3, and we have only two threads, we can cascade compute by running loops for 2 and 3 in the same thread, and on thread of incremental update by 1.

<b>An affine function is a function of one or more variables which can be expressed as a sum of a constant, plus constant multiples of the variables.</b> They are also sometimes called linear functions.

Examples:
```
a[i]
a[i+j-1]
```
Examples of non-affine functions
```
a[i*j]          - non-linear, non-affine
a[2*i + 1, i*j] - linear, non-linear, non-affine
```
Iteration space is the set of iterations whose IDs are given by the values held by the loop index variables.
```
for(i = 2; i<=100; i+=3)
    Z[i] = 0;
```
The iteration space is {2,5,8,...,98}.

The iteration space can be normalised by rewriting the above loop as
```
for(in = 0; in <= 32; in++)
    Z[2 + 3*in] = 0;
```
Here, 2 + 3*in allows the loop to be unchanged.

For nested loops normalisation can be done as well.
```
for(i=3; i<=7; i++)
    for(j = 6; j >= 2; j -= 2)
        Z[i.j] = Z[i, j+2] + 1;
```
Dependences in vectors remain the same as scalars, i.e, Flow, Anti and Output dependences.

A dependence graph is drawn to show data dependence between statements within a loop. Dependence distance is given by the dependence index positions. (1 for A[i] = A[i-1] + 1).

For the loops
```
for(i = 3; i<= 7; i++)
    for(j = 6; j >= 2; j -= 2)
        Z[i, j] = Z[i, j + 2] + 1;
```
Normalising would give
```
for(i = 0; i <= 4; i++)
    for(j = 0; j <= 2; j++)
        Z[i + 3, 6- 2*j] = Z[i + 3, 6 - 2*j + 2] + 1;
```