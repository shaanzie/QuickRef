# Lecture 16 - Markers

- Everytime a reduction to L is made, the value of T type is just below it
  - Now, T.val is at a known place in the stack
  - So we can directly assign that value at that stage
  - This allows removal of copy rules

- Simulating the evaluation of inherited attributes

For a grammar of the form
```
S -> aAC    C.in = A.syn 
S -> bABC   C.in = A.syn
C -> X      C.syn = g(C.in)
```
We add a marker M as
```
S -> aAC    C.in = A.syn
S -> bABMC  M.in = A.syn; C.in = M.syn
C -> X      C.syn = g(C.in)
M -> null   M.syn = M.in
```
  - This gives M.syn = M.in = A.syn
  - Therefore, C.in is always at top-1
  - The scheme works only if grammar allows position of attribute to be predicted
  - Attributes are usually copies of another attribute
  - If these are not copies, this rule fails
  - Markers can also be used to simulate rules that are not copies
    - S -> aAC  { Ci = f(A.s) }
  - For this, S -> aANC, N.in = A.syn, C.in = N.syn works

- For a general rule A -> MNOP...Z
  - Introduce a marker for each nonterminal A -> BM CN .... EZ, and B -> null, C -> null, so on
  - Then, all markers contain inherited attributes, and the others have the synthesized values
  - Markers are kept only for synthesized attributes, reducing space

The general algorithm
```
Input: L attributed definitions
Output: A bottom up parser

Assume every non terminal has one inherited attribute and every grammar symbol has a synthesized attribute

For every production A -> X1..Xn, introduce n markers M1..Mn, and replace the production by
A -> M1X1...MnXn
M1..Mn -> null

Synthesized attribute X1.syn goes to value entry of X1
Inherited attribute X1.in goes to the value entry of M1

If the reduction is to marker Mj, and it belongs to A -> M1X1...MnXn, then
A.in is in position top - 2j + 2
X1.in is in position top - 2j + 3
X1.syn is in position top - 2j + 4

If reduction is to a non terminal A, then compute A.syn and push to stack
```

- At compile time
  - Lifetime of an attribute is when it is initialised to when it is used last
  - Remove space taken by that attribute when not in its lifetime