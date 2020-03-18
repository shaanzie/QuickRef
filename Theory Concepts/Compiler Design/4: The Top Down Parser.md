
# Top down Parsing

Top down parsing is a problem of constructing a parse tree for the input string, from the root to leaves. This is done to find the leftmost derivation of a string.

At each step, the problem is to determine what production is applied for a non terminal, and then subsequent terminal symbols are matched.

There are mainly two types
1. Recursive Descent Parsing - Backtracking + finding right production
2. Predictive Parsing - Special case of RDP (No backtracking) + lookahead

The class of grammars for which we can construct predictive looking k symbols ahead in the input is called the LL(k) class.

### Recursive Descent Parser

An RDP program consists of a set of procedures, one for each non terminal. Execution begins with the procedure for the start symbol, which halts and announces success if its procedure body scans the entire input string. 

The general RDP may require backtracking, or more scans on the input. This is generally not required, and hence, top down parsers aren't used that frequently.

Backtracking is implemented by choosing a set of productions rather than just one, and upon failure, trying the remaining productions.

### First and Follow

First and Follow allows to choose which production to apply, based on the next input symbol. During panic-mode error recovery, sets of tokens produced by follow can be used as synchronization tokens.

First(a), where a is a string of grammar symbols, is the set of terminals that begin strings derived from a.

Follow(A), for a nonterminal A, is the set of terminals a that can appear immediately to the right of A, in some sentential form. If A is the rightmost symbol in some form, then $ is in the Follow(A).

To compute first(X)
1. If X is a terminal, then first(X) = {X}.
2. If X is a non terminal, and X -> Y<sub>1</sub>Y<sub>2</sub>Y<sub>3</sub>, then place first(Y<sub>i</sub>) in first(X).
3. If X -> e, place e in first(X)

To compute follow(A)
1. Place $ in follow(S), where S is the start symbol
2. If there is a production A->aBb, then everything in first(b) except e is in follow(B).
3. If there is a production A->aB, or a production A -> aBb, where first(b) contains e, then everything in follow(A) is in follow(B).

### LL(1) Grammars

Predictive parsers can be constructed from LL(1) grammars, where the first L stands for scanning input from left to right, and the second for producing the leftmost derivation, and the 1 for using 1 input symbol for lookahead.

A grammar is in LL(1) only if whenever A -> a | b are two distinct productions of the grammar, the following conditions hold
1. For no terminal d do both a and b derive strings beginning with d.
2. At most one of a and b can derive the empty string
3. If e is in first(b), then first(a) and follow(A) are disjoint.

To construct a predictive parsing table
1. For each terminal in first(a), add A->a to M[A, a].
2. If e is in First(a), then for each terminal b in follow(A), add A->a to M[A, b]. If e is in first(a) and $ is in follow(A), add A->a to M[A, $] as well.

If a grammar is ambiguous, its parsing table will have two production entries for a single cell.

### Non Recursive Predictive Parsing

A nonrecursive predictive parser can be built by maintaining a stack explicitly, rather than implicit recursive calls. 

If w is the input matched so far, the stack holds a sequence of grammar symbols a such that S => wa.

The parser is controlled by a program that considers X, the symbol on the top of the stack, and <i>a</i>, the current input symbol.
If X is a nonterminal, then the parser choses an X production by consulting M[X, a] of the parsing table. Otherwise, it checks for a match between the terminal X and a.

### Error Recovery

An error is detected during predictive parsing when the terminal on top of the stack does not match the next input symbol or when the nonterminal A is on top of the stack and M[A, a] is an error.

<b>Panic Mode</b>

Panic mode recovery is based on the idea of skipping over symbols on the input until a token in a selected set of synchronizing tokens appears. Its effectiveness depends on the choice of synchronization set.

Some heuristics for error handling in panic mode are as follows
1. As a starting point, place all symbols in Follow(A) into the synchronizing set for non terminal A. If we skip tokens until an element of Follow(A) is seen and pop A from the stack, it is likely that parsing can continue.
2. It is not enough to use follow(A) as the synchronizing set for A. We add at a lower level construct the symbols that begin higher level constructs.
3. If we add symbols in First(A) to the synchronizing set for nonterminal A, then it may be possible to resume parsing according to A if a symbol in First(A) appears in the input.
4. If a nonterminal can generate the empty stringm then the production deriving e can be used as default, to postpone error detection, but cannot cause an error to be missed, reducing the number of non terminals to be considered for error detection.

<b>Phrase-level Recovery</b>

Phrase level recovery is implemented by filling blank entries in the predictive parsing table with pointers to error routines. These routines modify the input, and this is questionable due to
1. The steps carried out by the parser may not correspond to the derivation of any word in the language
2. Ensuring no possibility of infinite loops.
