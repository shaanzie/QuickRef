#include "omp.h"

static long num_steps = 100000;
double step;
#define NUM_THREADS 2

// Using SPMD strategy

int main()
{
    int i, nthreads;
    double pi, sum[NUM_THREADS];

    step = 1.0/(double)num_steps;

    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {   

        int i, id, nthrds;
        double x;
        
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if(id == 0) 
            nthrds = nthreads;

        for(i = id, sum[id] = 0.0; i<num_steps; i += nthrds)
        {
            x = (i + 0.5)*step;
            sum[id] += 4.0 / (1.0 + x*x);
        }
    }    
    for(i = 0; i<NUM_THREADS; i++)
    {
        pi += sum[i] * step;
    }
    return 0;
}

/* 
Scalability is bad


This happens due to false sharing.
False Sharing: If independent data elements happen to sit on the same cache line, each update will cause the cache lines to "slosh back and forth" between threads. These shared cache lines impact scalability.
*/