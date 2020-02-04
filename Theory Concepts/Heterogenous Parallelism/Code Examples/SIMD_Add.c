#include<stdio.h>
#include <time.h>
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
    struct timespec start, end;
    int a[10000], b[10000], c[10000];
    
    _time(start);

    for(int i = 0; i<10000; i++)
    {
        if(i%2)
            a[i] = b[i] + c[i];
        else
            a[i] = b[i] - c[i];
    }
    _time(end);
    printf("%lf",time_elapsed(start, end));
    return 0;
}