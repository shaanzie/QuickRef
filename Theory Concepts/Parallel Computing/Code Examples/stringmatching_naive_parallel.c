#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<omp.h>

#define NUM_THREADS 4

int count=0;

void search(char *t,int start,int end,char *p)
{
    int i,j;
    int n=end-start+1;
    int m=strlen(p);
    for(i=start;i<=end-m;i++)
    {
        for(j=0;j<m;j++)
            if(t[i+j]!=p[j])
                break;

        if(j==m){
            printf("pattern found at index %d\n",i);
            count++;
        }
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

    int bs=strlen(text)/NUM_THREADS;
    int rem=strlen(text)%NUM_THREADS;
    int tid,start,end;

    #pragma omp parallel num_threads(NUM_THREADS) private(tid,start,end) shared(text,pat,rem,bs,m)
    {
    tid=omp_get_thread_num();
    
    if(tid==0)
    {
        #pragma omp critical (part1)
        {
        start=tid;
        end=bs-1;
        search(text,start,end,pat);
        }
    }
    else
    {
        #pragma omp critical (part2)
        {
        start=(tid*bs)-lenp;
        end=(tid*bs)+bs-1;
        search(text,start,end,pat);
        }
    }
    }
    if(rem!=0)
    search(text,(NUM_THREADS+1)*bs,strlen(text),pat);

    printf("Total number of matches = %d\n",count );
    return 0;
}