# Introduction to LR Parsing

LR(k) parsing is L for left to right scanning of input, R for constructing rightmost derivation in reverse, and k is the number of lookahead symbols.

LR parsers are table driven, much like the non recursive LL parsers. LR parsing is attractive because
1. LR parsers can be constructed to recognize virtually all programming language constructs for which CFGs can be written
2. The LR parsing method is the most general non backtracking shift-reduce parsing method known, and is efficient.
3. An LR parser can detect syntactic errors as soon as possible to do so.
4. The class of LR grammars is a subset of grammars that can be parsed with LL grammars.

The principal drawback of the LR method is that it uses too much work to construct an LR parser by hand for a typical programming language grammar, and a LR parser generator is needed.

## Items and the LR(0) Automaton

An LR parser makes shift-reduce decisions by maintaining states to keep track of where we are in a parse. States represent sets of items.

An LR(0) item of a grammar G is a production of G with a dot at some position of the body.
```
A -> .XYZ
A -> X.YZ
A -> XY.Z
A -> XYZ.
```

The production A -> e generates only A -> .

One collection of sets of LR(0) items, called canonical LR(0) collection, provides the basis to construct a DFA that is used in making parsing decisions. Such an automaton is called an LR(0) automaton, which represents the items.

To construct a canonical LR(0) collection, we define an augmented grammar, GOTO and CLOSURE.

### Augmented Grammar

Add a production S' -> S to indicate to the parser when it should stop parsing and announce acceptance.

### Closure Of ItemSets

If I is a set of items for a grammar G, then closure(I) is the set of items where
1. Initially, add every item I into the closure(I)
2. If A -> a.Bb is in closure(I) and B->l is a production, then add B -> .l to the closure(I) if not already there.

The set of items generated are divided into
1. Kernel Items - Initial item S' -> .S, and all items with the dots not on left end
2. Non kernel items - All items with dots at the left end, except S' -> S.

Each set of items is formed by taking the closure of a set of kernel items, helping them to be described with minimal space.

### GOTO function

GOTO(I, X) is defined to be the closure of the set of all items A->aX.b such that A -> a.Xb is in I. This is used to define the transitions in the LR(0) automaton.

### Use of the LR(0) Automaton

The idea behind simple LR or SLR parsing is the construction from the grammar of the LR(0) automaton. 

The start state is the closure of S' -> S, and GOTO defines the state transitions between each state.

Shift reduce decisions are made as follows
1. If a string s takes the LR(0) automaton from the start state 0 to some state j, then, shift on the next input symbol a if j has a transition on a.
2. Otherwise, choose another production from state j

A reduction in a stack design is done by popping the body of the production from the stack and pushing the head of the production onto the stack.

## The LR Parsing Algorithm

The LR parser broadly consists of 
1. Input
2. Output
3. Stack
4. Driver Program
5. Parsing Table (Action and GOTO)

The driver program is the same, only the parsing table changes. When a parser shifts a symbol, the state is changed, where each state summarises the information contained in the stack below it.

### Structure of the LR parsing table

The parsing table consists of GOTO and ACTION.
1. The ACTION function takes as arguments a state i and a terminal a or $. The value of ACTION[i, a] can have one of four forms
   1. Shift j, where j is a state. This shifts input a onto the stack but uses j to represent a.
   2. Reduce A -> b.
   3. Accept
   4. Error
2. The GOTO dunction maps a state i and a non terminal A to state j.

### The LR Parser configuration

A configuration of the LR parser is a pair :

(s<sub>0</sub>s<sub>1</sub>...s<sub>m</sub>, a<sub>i</sub>a<sub>i+1</sub>...a<sub>n</sub>$)

Where the first component is the stack contents and the second is the remaining input. This represents the right sentential form

X<sub>1</sub>X<sub>2</sub>...X<sub>m</sub>a<sub>i</sub>a<sub>i+1</sub>...a<sub>n</sub>

in essentially the same way a shift-reduce parser would. The only difference is that the stack holds state from which the grammar can recover.

### Behavior of the LR parser

The next move of the parser is determined by reading the current input and state, and causing the entry in the ACTION to occur.
1. If ACTION[s, a] = shift s, the parser executes a shift, where it shifts the next state to TOS.
2. If Action[s, a] = reduce A -> b, then a reduce move is executed.
3. Accept
4. Error

## Constructing SLR Parsing Tables

The method is outlined as
1. Construct C = {I0, I1, ..., In}, the collection of sets of LR(0) items for G'.
2. State i is constructed from I<sub>i</sub>. The parsing actions are determined as
   1. If A -> a.Ab is in I and GOTO(I, A) = J, then set ACTION[i, A] to shift j
   2. If A -> a. is in I, then set ACTION[i, A] to reduce A -> a for all a in FOLLOW(A).
   3. If S' -> S. is in I, then set ACTION[i, $] to accept.
   4. Any conflicting actions result in the grammar not being in SLR(1).
3. The goto transitions for state i are constructed for all nonterminals A using the rule: If GOTO(I, A) = J, then GOTO[i, A] = j.
4. All entries not defined by 2 and 3 are made error. 
5. The initial state of the parser is the one constructed from the set of items containing S' -> .S.

This forms the SLR(1) table for the grammar.

## Viable Prefixes

The prefixes of right sentential forms that can appear on the stack of a shift reduce parser are called viable prefixes, which does not continue past the right end of the rightmost handle of that sentential form. By this, it is always possible to add terminal symbols to the end of a viable prefix to obtain a right sentential form.



