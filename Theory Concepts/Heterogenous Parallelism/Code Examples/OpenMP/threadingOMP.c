#include "omp.h"

int main()
{
    double A[1000];
    omp_set_num_threads(4);

    // Data here sits on the heap and is available globally
    #pragma omp parallel
    {
        // Data here is private to the thread and is stored on the stack
        int ID = omp_get_thread_num();
        pooh(ID, A);
    }
    printf("all done\n");
}