#define NUMARRAYS 1000
#define ARRAYSIZE 100000000
import random;
code = """ 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ARRAYSIZE 100000
#define NUMARRAYS 1000000
#define _time(start_or_end) clock_gettime(CLOCK_REALTIME, &start_or_end)
static double time_elapsed(struct timespec start, struct timespec end);
int main()
{
    struct timespec start, end;
    int *a[NUMARRAYS];
    for(int i=0; i<NUMARRAYS; i++)
    {
        a[i] = (int *) malloc(ARRAYSIZE * sizeof(int));
    }
    _time(start);
    %s
    _time(end); 

    printf("%%lf",time_elapsed(start, end));
    for(int i=0; i<NUMARRAYS; i++)
    {
        free(a[i]);
    }
}

static double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}

"""
main = "for(int i=0;i<ARRAYSIZE;i++){\n"
for i in range(1000):
    num = random.randint(1,1000000)
    string = "a[%d][i] += %d;"
    string = (string% (i,num))
    main += "\t" + string + "\n"
main += "}"

print(code % main)
