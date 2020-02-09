# Bottom-Up Parsing

A bottom-up parse corresponds to the construction of a parse tree for an input string beginning at the leaves and working towards the root.

## Reductions

Bottom-up parsing can be thought of as the process of "reducing" a string w to the start symbol of the grammar. At each reduction step, a specific substring matching the body of the production is replaced by the nonterminal at the head of that production.

This is a rightmost type of derivation where the sentential form is replaced by the production.

## Handle Pruning

Informally, a handle is a substring that matches the body of a production, and whose reduction represents one step along the reverse of a rightmost derivation.

For example, if S => aAw => acw, then production A -> c in the position following a is a handle of acw. The RHS must always be a set of terminals in this case.

A rightmost derivation in reverse can be obtained by handle pruning. We start with a string of terminals w to be parsed. If w is a sentence of the grammar, then let w = ln, ln is the nth right sentential form of some as yet unknown right derivation
```
S = l0 => l1 => l2 => ..... => ln = w
```
For this, we locate the handle bn in ln, and replace bn with the head of the relevant production An -> bn to obtain the previous right sentential form ln.

## Shift Reduce Parsing

SR parsing is a form of bottom-up parsing in which a stack holds grammar symbols and an input buffer holds the rest of the string to be parsed.

During a left to right scan of the input string, the parser shifts zero or more input symbols onto the stack, until it is ready to reduce a string b of grammar symbols on TOS. Then it reduces b to the head of the appropriate production.

There are four possible actions
1. Shift - Shift next input on TOS
2. Reduce - Locate left end of the stack and replace string with nonterminal
3. Accept - Announce successful completion of parsing
4. Error - Discover syntax error and call an error recovery routine.

The use of a stack allows the handle to eventually appear on the TOS, but never inside.

## Conflicts during Shift Reduce Parsing

There are CFGs where SR Parsing cannot be used. Here, there can be ambiguity on whether to shift or reduce (shift/reduce conflict) or which of the several reductions to make (reduce/reduce). These grammars do not fall under the LR(k) class of grammars.

Another conflict occurs when we know we have a handlem but the stack contents and next input symbol are insufficient to determine which production should be used in a reduction.

