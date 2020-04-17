#include<omp.h>

#define NPOINTS 1000
#define MXITR 1000

// void testpoint(void);

struct d_complex {
    double r;
    double i;
};
struct d_complex c;

void testpoint(struct d_complex);

int numoutside = 0;

int main() {

    int i, j;
    double area, error, eps = 1.0e-5;
    // #pragma omp parallel for default(shared) private(c, eps) // Causes race, make j private
    #pragma omp parallel for default(shared) private(c, j) firstprivate(eps)
    for(i = 0; i<NPOINTS; i++) {
        for(j = 0; j<NPOINTS; j++) {
            c.r = -2.0 + 2.5*(double)(i)/(double)(NPOINTS) + eps;
            c.i = 1.125 * (double)(j)/(double)(NPOINTS) + eps;
            testpoint(c);
        }
    }
    area = 2.0 * 2.5 * 1.125 * (double)(NPOINTS*NPOINTS-numoutside)/(double)(NPOINTS*NPOINTS);
    error = area/(double)(NPOINTS);
    printf("Area: &lf", area);  
}

void testpoint(struct d_complex c) {

    struct d_complex z;
    int iter;
    double temp;

    z = c;
    for(iter = 0; iter < MXITR; iter++) {

        temp = (z.r*z.i+z.i*z.i) + c.r;
        z.i = z.r*z.i*2 + c.i;
        z.r = temp;
        if((z.r*z.r + z.i*z.i) > 4.0) {
            #pragma omp atomic          // Make access to structure atomic, rather than use a global
            numoutside++;
            break;
        }
    }
    return;

}