# Some Interesting Questions

## What are the pros and cons of Superscalar Architecture and Very Large Instruction Set Architecture?

| Superscalar                | VLIW                                           |
|----------------------------|------------------------------------------------|
| Dynamic Scheduling         | Static Scheduling                              |
| Complex Hardware           | Simpler Hardware                               |
| Can adapt to variable load | Uses a worst case scheduling                   |
| Compact Code               | Additional NOPs - Waste of space and Bandwidth |

## What is Sun & Ni's Law of Parallelism?

Sun and Ni's law is a memory-bounded speedup model which says that as computing power increases the corresponding increase in problem size is constrained by the system's memory capacity. In general, as a system grows in computational power, the problems run on the system increase in size. 
Sun & Ni's law states that the problem size must scale but be bounded by the memory capacity of the system.

## How can Data Hazards be solved?

1. Data forwarding
2. Synchronization mechanisms
3. Reordering of data - considered volatile
4. False dependency removal

## What is the law of diminishing returns?

The law of diminishing returns states that in production processes, adding more than one factor of production while keeping all other factors constant will at some point result in smaller per unit incremental returns.

## What is a tournament predictor?

Tournament predictors for branch prediction combine both global and local predictors. They use a selector to select the prediction outcome from one of them.

## What is Tomasulo's algorithm for dynamic scheduling?

Tomasulo's algorithm for dynamic scheduling uses register renaming to eliminate output and anti-dependence, as these are just name dependences. It uses reservation stations, which are buffers that fetch and store instruction operands as soon as they are available. Once all source operands are available, the instruction is sent for execution, provided there is no structural hazard.

## What is scoreboarding?

The scoreboard monitors each instruction waiting to be dispatched. Once it determines all the source operands and the required functional units are available, it dispatches the instruction so that it can be executed. However, it is limited as it does not handle WAR and WAW hazards well. 4

## What is the difference between dynamic instruction count and static instruction count?

The dynamic instruction count is the actual number of instructions executed by the CPU for a specific program execution, whereas static instruction count is the number of instructions the program has. 

## Parallelise the loop

```
for(i=3; i < N; i++)
{
    a[i] = a[i-3] + c[i];
}
```

## Create a 3-dimensional dependency graph with normalisation.

## Come up with a transformation and explain how it exploits locality.
1. Loop interchange (Column major layout)
```
for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
        A[j][i] += 1;
```

2. Loop fusion
```
for(i = 0; i<n; i++)
    A[i] = B[i] + 5
    C[i] = B[i] + 4
```
3. Loop fission
```
for(i = 0; i<n; i++)
    A[i] = B[i] + 5
for(i = 0; i<m; i++)
    B[i] = B[i-1] + 4
```
4. Loop blocking
```
float A[MAX, MAX], B[MAX, MAX];

for (i=0; i< MAX; i+=block_size) 
{
    for (j=0; j< MAX; j+=block_size) 
    {
        for (ii=i; ii<i+block_size; ii++) 
        {
            for (jj=j; jj<j+block_size; jj++) 
            {
                A[ii,jj] = A[ii,jj] + B[jj, ii];
            }
        }
    }
}

```
5. Loop unrolling
```
for(i = 0; i<15; i+=3)
    a[i] = a[i] + 3;
    a[i + 1] = a[i + 1] + 3;
    a[i + 2] = a[i + 2] + 3; 
```
6. Virtual register allocation
```
```
7. Loop distribution
```
for(i = 0; i<n; i++)
    A[i] = B[i] + 5
for(i = 0; i<m; i++)
    B[i] = B[i-1] + 4
```
8. Scalar Replacement
```
```
10. Loop peeling
```
A[0] += 1
for(i = 1; i<n; i++)
    A[i] += 1;
```

## What will be the point in the iteration space will the GCD exist for a weak SIV test?

## How do MISD examples work?

## How much speedup does this loop get with autovectorization?
```
for(int i = 0; i<256; i++)
    a[i] = b[i]*c[i];
```
Aside:  Try making a, b and c byte arrays.

## The addresses must be aligned to 256 bit boundaries, and if this is not satisfied, there is a performance issues in ARM, but this needs to be checked for x86.

## Doing Addition is free, in double precision. Why?

## Vectorize this code
```
for(int i = 0; i<N; i++)
{
    if(i%2)
        a[i] = b[i] + c[i];
    else
        a[i] = b[i] - c[i];
}
```