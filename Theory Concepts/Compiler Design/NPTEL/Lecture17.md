# Lecture 17 - Converting SDDs

- Suppose, for an S-attributed SDD 
```
A -> A1y    {A = g(A1, y)}
A -> X      {A = f(X)}
```
After removing left recursion,
```
A -> X {R.in = f(X)} R {A.s = R.s}
R -> y {R1.in = g(y, R)} R1 {R.s = R1.s}
R -> null   {R.s = R.i}
```
- This is L-attributed SDD and now we can use a top-down parser
- To convert
  - Remove left recursion
  - Follow parse tree rules
    - Inherited to the left and parent
    - Synthesized at the end

- For an L-attributed SDD, converting to S-attributed SDD
  - For every embedded rule, introduce a new non terminal
  - Rules all come to the RHS, and hence, this is S-attributed

```
E -> TR
R -> + T {print(+)} R
R -> - T {print(-)} R
R -> null
T -> num {print(num.val)}
```
transforms to
```
E -> TR
R -> + T M R
R -> - T N R
R -> null
T -> num    {print(num)}
M -> null   {print(+)}
N -> null   {print(-)}
```

- Inheriting attribute on parser stacks
  - Bottom up parser reduces RHS of A -> XY by removing XY from stack and putting A
  - Synthesized attributes of X can be inherited by Y by using Y.in = X.syn
  - We know the positions of each attribute on the stack, and hence can be pulled from the location easily