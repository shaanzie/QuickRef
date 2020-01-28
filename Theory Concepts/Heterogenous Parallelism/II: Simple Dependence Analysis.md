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

