# More Powerful LR Parsers

The previous LR parsing techniques are extended to use a symbol of lookahead on the input. There are two different methods
1. The canonical LR or just LR method, which makes full use of the lookahead symbols. This uses a large set of items, called the LR(1) items.
2. The lookahead-LR or LALR method, which is based on the LR(0) set of items, and has fewer states than typical parsers based on the LR(1) items.

## Canonical LR(1) Items

In some situations of SLR parsing, when state i appears on the TOS, the variable prefix on the stack is such that it cannot be followed by the next input in any right-sentential form.

For this, more information needs to be carried which rules out invalid reductions. This is done by splitting states when necessary, and each state is arranged to indicate what input symbols can follow a handle on the TOS.

This is done by including a second component of a terminal symbol. The general form then becomes A->a.b, c, where A -> ab is a production and c is a terminal or $. This is called an LR(1) item, and the 1 indicates the lookahead.

We say LR(1) item [A -> a.b, c] is valid for a prefix p, if there is a derivation S => dAw => dabw where
1. p = da and
2. Either c is the first symbol of w, or w is e and c is $.

## Constructing LR(1) Sets of Items

To build the collection of LR(1) set of items, its the same principle as the canonical collection of sets of LR(0) items. But in this, we consider a lookahead, and is the first of the symbol following the production the rule that derives it.

LALR parsing tables just combine sets of LR(1) items that do not differ in LR(0) itemsets, to make parsing more efficient by reducing the number of sets of elements to validate.

## Shorthand for Parsers

LL(0) : Top down, No lookahead 
LL(k) : Top down, k lookaheads
LR(0) : Reductions in the whole row of a state
SLR(1) : Reduction only in follow set of LHS of production getting reduced
LALR(1) : Remove redundant entries from CLR(1) with same LR(1) items
CLR(1) / LR(1) : Entries based on unique LR(1) + lookahead items