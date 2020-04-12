# Intermediate Code Generation

## DAG for Expressions

A DAG has leaves corresponding to atomic operands and interior nodes corresponding to operators. A node N in a DAG has more than one parent if N represents a common subexpression. 

## Three Address Code

In 3AC, there is atmost one operator on the right side of an instruction. 