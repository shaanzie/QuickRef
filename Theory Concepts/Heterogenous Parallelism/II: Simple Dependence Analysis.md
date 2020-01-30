# Simple Dependence Analysis

The dependence direction vector is D(i, j) is defined as a vector of length n such that
```
D(i, j)(k) = {

    "<" if d(i, j)(k) > 0
    "=" if d(i, j)(k) = 0
    ">" if d(i, j)(k) > 0

}
```

where there is a dependence from statement S1 on iteration i of a loop next of n loops and statement S2 on iteration j, and d(i, j) denotes this distance as i(k) - j(k).

For example:
```
    DO I = 1, N
        DO J = 1, M
            DO K = 1, L
S1          A[I + 1, J, K - 1] = A[I, J, K] + 10
            END
        END
    END
```
S1 has a true dependence on itself. The distance vector is given by 
`(1, 0, -1)` and the direction vector is given by `(<, =, >)`.
The direction vector has a * when a loop index variable is not involved in a dependence. It is a union of <= and =>.

A dependence cannot exist if it has a direction vector whose leftmost non "=" component is not "<" as this would imply that the sink of the dependence occurs before the source. The reverse may or may not be true.

A dependence exists if and only if there exists a and b such that a is lexographically lesser than b as vectors and fi(a) = gi(b) for all 1 <= i <= m, for the system
```
    DO i1 = L1, U1, S1
        DO i2 = L2, U2, S2
            ...
                DO iN = LN, UN, SN
S1                A(f1(i1....iN)...fM(i1....iN)) = ....
S2                  .... = A(g1(i1....iN).....gM(i1....iN))
                ENDDO
            ...
        ENDDO
    ENDDO
```

This is a direct application of loop dependence theorem. To achieve parallelism in a program, the solution should not exist.

The Delta notation represents the index values at the source and sink. For
```
    DO I = 1, N
S       A(I + 1) = A(I) + B
    ENDDO
```
1. The iteration at source is I(0).
2. The iteration at sink is I(0) + del*I
3. Forming an equality gets us I(0) + 1 = I(0) + del*I

Solving this gives del*I = 1. This is a carried dependence with distance vector (1) and direction vector (<).

This simple dependency testing is used as there is no coupling, and the index variable is not repeated for other indices.

The type of dependency analysis is defined by the category of the iteration as
1. ZIV - Zero index variable (Iteration value is constant, no variable)
2. SIV - Single index variable (1 variable)
3. MIV - Multiple index variable (Coupled variables)

For example,
```
A(5, I + 1, j) = A(1, I, k) + C
```
1. The first subscript is ZIV.
2. The second subscript is SIV.
3. The third subscript is MIV.

A subscript is separable if its indices do not occur in any other subscripts. Otherwise, it is called a coupled subscript.

For example,
```
A(I + 1, j) = A(k, j) +  C
```
Here, both the subscripts are separable.
And in this example,
```
A(I, j, j) = A(I, j, k) + C
and
A(I, J, K) = A(I, K, J) + C
```
The second and third subscripts are coupled.

This is done because coupling can cause imprecision in dependence testing.

Dependence testing is done in the following steps overall:
1. Partition subscripts of a pair of array references into separable or coupled groups.
2. Classify them as ZIV, SIV or MIV
3. Apply single subscript tests
   1. ZIV Test
   2. SIV Test
      1. Strong SIV
      2. Weak SIV
         1. Weak-zero SIV
         2. Weak crossing SIV
   3. SIV Tests in complex iteration spaces

### ZIV Test

A ZIV test is given by
```
    DO j = 1, 100
S       A(e1) = A(e2) + B(j)
    END
```
e1 and e2 are constants or loop invariant symbols. If (e1-e2) != 0, no dependence exists.

### Strong SIV Test

Strong SIV subscripts are of the form <ai + c<sub>1</sub>, ai + c<sub>2</sub>>.
For example, some strong SIV subscripts are <i + 1, i> and <4i + 2, 4i + 4>.

We calculate d = (c<sub>1</sub> - c<sub>2</sub>) / a and if the |d| <= U - L, dependence exists, where U and L are the upper and lower limits of the loop.

### Weak SIV Tests

Weak SIV subscripts are of the form <a<sub>1</sub>i + c<sub>1</sub>, a<sub>2</sub>i + c<sub>2</sub>>.
For example, some weak SIV subscripts are <i + 1, 2i + 2> and <4i + 3, 2i + 7>.

For this, we say for

a<sub>1</sub>i - a<sub>2</sub>i = c<sub>2</sub> - c<sub>1</sub>,

If the gcd(a<sub>1</sub>, a<sub>2</sub>) divides c<sub>2</sub> - c<sub>1</sub> and the quotient falls between U and L, then a dependency exists.

