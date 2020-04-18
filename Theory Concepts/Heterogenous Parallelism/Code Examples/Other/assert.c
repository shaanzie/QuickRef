#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<assert.h>

int p(int x) {
    return x*x;
}

void main() {
    int z;
    if(getc(stdin) == 'a')
        z = p(6) + 6;
    else
        z = p(-7) - 7;
    assert(z == 42);
    printf("%d", z);
    return 0;
}