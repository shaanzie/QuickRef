
import random 

numarr = 1000

initcode = """
int i;
"""

forcode = """
    for(int i=0;i<ARRAYSIZE;i++)
    {
        a[%d][i] += 45 + %d;
    }
"""

code = """
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYSIZE 100000
#define NUMARRAYS 1000000

#define _time(start_or_end) clock_gettime(CLOCK_REALTIME, &start_or_end)

static double time_elapsed(struct timespec start, struct timespec end)
{
    double t;
    t = (end.tv_sec - start.tv_sec);                  //diff of tv_sec
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001; //add diff of tv_nsec too
    return t;
}

int main()
{
    int i;
    struct timespec start, end;
    int *a[NUMARRAYS];
    for(i=0; i<NUMARRAYS; i++)
    {
        a[i] = (int *) malloc(ARRAYSIZE * sizeof(int));
    }

    _time(start);
    %s
    _time(end); 

    printf("%%lf",time_elapsed(start, end));


    for(i=0; i<NUMARRAYS; i++)
    {
        free(a[i]);
    }
}

"""


forst = ""
for i in range(0, numarr):
    forst += forcode % (i, random.randint(1, 1000000))

print(code % (forst))