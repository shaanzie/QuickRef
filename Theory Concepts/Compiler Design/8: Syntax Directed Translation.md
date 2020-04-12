# Syntax Directed Translation

Information associated with a language construct is done by attaching attributes to the grammar symbol representing the construct. A Syntax Directed Definition (SDD) specifies the value of the attributes by associated semantic rules with the grammar productions. For example,
```
E -> F + T          {E.code = F.code || T.code || '+'}
```
F can be represented as E<sub>1</sub> to distinguish it wrt E. E, F and T have the string attribute code, where F.code and T.code concatenate to form E. The position of the semantic action in the body determines the order in which the action is executed. SDDs are more readable, and hence more useful in specifications. But, translation schemes are more efficient, and hence more useful for implementations. 

The most general approach to syntax directed translation is to construct a parse tree, and then compute the values of the attributes of the nodes of the tree by visiting the nodes. 
- L attributed translations are those SDTs where all translations can be performed during parsing
- S attributed translations can be performed easily in connection with a bottom up parse

## Syntax Directed Definitions

A SDD is a CFG together with attributes and rules. Attributes are associated with grammar symbols and rules are associated with productions. We denote attributes at certain breakpoints to indicate the value of that symbol at that particular point in time. 

Attributes are of two types
- Synthesized
  -  For a nonterminal A at a parse tree node N is defined by the semantic rule associated with the production at N. Note that the production must have A at the head. 
  -  A synthesized attribute at a node N is defined only in terms of the attribute values at the children of N and at N itself.
- Inherited
  - For a nonterminal B at a parse-tree node N is defined by a semantic rule associated with the production at the parent of N
  - Production must have B in its body
  - Defined only in terms of attributes in N's parents, siblings and N itself.

An SDD that involves only synthesized attributs is called S-attributed. Each rule computes an attributed for the non terminal at the head of the production from attributes taken from the body of the production. An attribute grammar is one in which the rules define the value of an attribute purely in terms of the values of other attributes and constants.

### Evaluating an SDD at the nodes of a Parse Tree

A parse tree showing the values of its attributes is called an annotated parse tree. With synthesized attributes, we can evaluate attributes in any bottom-up order, such as that of a postorder traversal of the parse tree. For SDDs with both inherited and synthesized attributes, there is no guarantee that there is even one order in which to evaluate the attributes in the nodes. 

Inherited attributes are useful when the structure of a parse tree does not match the abstract syntax of the source code. 

## Evaluation Orders for SDDs

### Dependency Graphs

A dependency graph depicts the flow of information among the attribute instances in a particular parse tree; an edge from one attribute instance to another means that the value of the first is needed to compute the second. Edges express constraints implied by semantic rules.
1. For each parse tree node, the graph has a node for each attribute associated with the node
2. Every production creates an edge between dependent nodes, whether they are synthesized or inherited

A topological sort is followed for the ordering of evaluation. If there exists a cycle, there is no way to evaluate the SDD. 

### S-Attributed Definitions

When an SDD is S-attributed, any order of evaluation can be used which is bottom-up. We usually apply a functional postorder, where the attributes associated with node N are evaluated in the traversal.

### L-Attributed Definitions

In this, dependency graph edges can go from left to right, but not from right to left.
Each attribute must be 
1. Synthesized
2. Inherited, but with rules as follows. For A -> X1 X2 X3 .. Xn, and that there is an inherited attributed Xi.a computed by a rule where the rule uses only
   1. Inherited attributes associated with head A
   2. Either inherited or synthesized attributes associated with the occurence of symbols X1 X2 X3 ... X(i-1) located to the left of Xi.
   3. Inherited or synthesized attributes associated with this occurence of Xi itself, but in such a way that there are no cycles in the dependency graph formed.

## Applications of Syntax-Directed Translation

The main applications of SDTs are syntax trees, used as an intermediate representation. The nodes of the syntax tree are implemented by objects with suitable fields. Each object has an op field with the label of the node. If the node is a leaf, an additional field holds the lexical value for the leaf. If the node is an interior node, there are as many additional fields as children in the syntax tree.

### Construction of Syntax Trees

The nodes of the syntax tree are implemented with objects. Each object has an op field which is the label of that node, and has the following fields
1. If the node is a leaf, an additional field holds the lexical value for the leaf. 
2. If the node is an interior node, there are as many additional fields as children.

