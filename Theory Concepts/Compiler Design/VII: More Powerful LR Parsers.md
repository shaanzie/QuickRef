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

