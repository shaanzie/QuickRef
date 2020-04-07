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

