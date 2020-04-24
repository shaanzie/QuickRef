# Lecture 23 - 3 - Address Code

- We need to generate
  - Generate temp names
  - Attributes for code
  - Attributes for temp names

- For example, E -> F + G, we generate
  - E.p = newtmp();
  - E.c = F.c || G.c || gen(E.p = F.p + G.p)
