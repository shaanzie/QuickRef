#include <stdio.h>
#include <stdlib.h>

typedef int T;                  
#define compLT(a,b) (a < b)
#define compEQ(a,b) (a == b)

typedef struct Node_ {
    T data;                     
    struct Node_ *forward[1];  
} Node;

typedef struct {
    Node *hdr;                 
    int listLevel;             
} SkipList;

SkipList list;               

#define NIL list.hdr

Node *insertNode(T data) {
    int i, newLevel;
    Node *update[15+1];
    Node *x;
    x = list.hdr;
    for (i = list.listLevel; i >= 0; i--) {
        while (x->forward[i] != NIL 
          && compLT(x->forward[i]->data, data))
            x = x->forward[i];
        update[i] = x;
    }
    x = x->forward[0];
    if (x != NIL && compEQ(x->data, data)) return(x);

    for (newLevel = 0; rand() < RAND_MAX/2 && newLevel < 15; newLevel++);

    if (newLevel > list.listLevel) {
        for (i = list.listLevel + 1; i <= newLevel; i++)
            update[i] = NIL;
        list.listLevel = newLevel;
    }

    if ((x = malloc(sizeof(Node) + 
      newLevel*sizeof(Node *))) == 0) {
        printf ("insufficient memory (insertNode)\n");
        exit(1);
    }
    x->data = data;
    for (i = 0; i <= newLevel; i++) {
        x->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = x;
    }
    return(x);
}

void deleteNode(T data) {
    int i;
    Node *update[15+1], *x;
    x = list.hdr;
    for (i = list.listLevel; i >= 0; i--) {
        while (x->forward[i] != NIL 
          && compLT(x->forward[i]->data, data))
            x = x->forward[i];
        update[i] = x;
    }
    x = x->forward[0];
    if (x == NIL || !compEQ(x->data, data)) return;

    for (i = 0; i <= list.listLevel; i++) {
        if (update[i]->forward[i] != x) break;
        update[i]->forward[i] = x->forward[i];
    }

    free (x);
    while ((list.listLevel > 0)
    && (list.hdr->forward[list.listLevel] == NIL))
        list.listLevel--;
}

Node *findNode(T data) {
    int i;
    Node *x = list.hdr;

    for (i = list.listLevel; i >= 0; i--) {
        while (x->forward[i] != NIL 
          && compLT(x->forward[i]->data, data))
            x = x->forward[i];
    }
    x = x->forward[0];
    if (x != NIL && compEQ(x->data, data)) return (x);
    return(0);
}

void initList() {
    int i;

    if ((list.hdr = malloc(sizeof(Node) + 15*sizeof(Node *))) == 0) {
        printf ("insufficient memory (initList)\n");
        exit(1);
    }
    for (i = 0; i <= 15; i++)
        list.hdr->forward[i] = NIL;
    list.listLevel = 0;
}

int main(int argc, char **argv) {
    int i, *a, maxnum, random;

    // command-line: skl maxnum [random]

    maxnum = atoi(argv[1]);
    random = argc > 2;

    initList();

    if ((a = malloc(maxnum * sizeof(*a))) == 0) {
        fprintf (stderr, "insufficient memory (a)\n");
        exit(1);
    }

    if (random) {
        for (i = 0; i < maxnum; i++) a[i] = rand();
        printf ("ran, %d items\n", maxnum);
    } else {
        for (i = 0; i < maxnum; i++) a[i] = i;
        printf ("seq, %d items\n", maxnum);
    }

    for (i = 0; i < maxnum; i++) {
        insertNode(a[i]);
    }

    for (i = maxnum-1; i >= 0; i--) {
        findNode(a[i]);
    }

    for (i = maxnum-1; i >= 0; i--) {
        deleteNode(a[i]);
    }
    return 0;
}