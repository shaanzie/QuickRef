#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void search(char *t,char *pat)
{
    int n=strlen(t);
    int m=strlen(pat);
    int i,j;
    for(i=0;i<=n-m;i++)
    {
        for(j=0;j<m;j++)
            if(t[i+j]!=pat[j])
                break;

        if(j==m)
        printf("Pattern found at index %d\n",i);
    }
    return;
}

int main()
{
    char pat[10];
    char *text;
    int n,m,i=0;
    size_t size = 0;

    FILE *fp = fopen("gene.txt", "r");
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    rewind(fp);
    text = malloc((size + 1) * sizeof(*text));
    fread(text, size, 1, fp);
    text[size] = '\0';

    scanf("%s",pat);
    int lenp=strlen(pat);
    printf("Length of pattern: %d\n",lenp);
    printf("Length of pattern: %lu\n",strlen(text));

    search(text,pat);

    return 0;
}