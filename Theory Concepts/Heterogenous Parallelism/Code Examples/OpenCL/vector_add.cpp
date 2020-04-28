#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <opencl.h>

const char *kernelSource =                                       "\n" \
"#pragma OPENCL EXTENSION cl_khr_fp64 : enable                    \n" \
"__kernel void vecAdd(  __global double *a,                       \n" \
"                       __global double *b,                       \n" \
"                       __global double *c,                       \n" \
"                       const unsigned int n)                    \n" \
"{                                                               \n" \
"    int id = get_global_id(0);                                  \n" \
"                                                                \n" \
"    if (id < n)                                                 \n" \
"        c[id] = a[id] + b[id];                                  \n" \
"}                                                               \n" \
                                                                "\n" ;

int main( int argc, char* argv[] )
{
    unsigned int n = 100000;
    double *h_a;
    double *h_b;
    double *h_c;
    cl_mem d_a;
    cl_mem d_b;
    cl_mem d_c;

    cl_platform_id cpPlatform;        
    cl_device_id device_id;           
    cl_context context;               
    cl_command_queue queue;           
    cl_program program;               
    cl_kernel kernel;                 

    size_t bytes = n*sizeof(double);

    h_a = (double*)malloc(bytes);
    h_b = (double*)malloc(bytes);
    h_c = (double*)malloc(bytes);

    int i;
    for( i = 0; i < n; i++ )
    {
        h_a[i] = sinf(i)*sinf(i);
        h_b[i] = cosf(i)*cosf(i);
    }

    size_t globalSize, localSize;
    cl_int err;

    localSize = 64;

    globalSize = ceil(n/(float)localSize)*localSize;

    err = clGetPlatformIDs(1, &cpPlatform, NULL);
    err = clGetDeviceIDs(cpPlatform, CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);

    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);

    queue = clCreateCommandQueue(context, device_id, 0, &err);

    program = clCreateProgramWithSource(context, 1,
                                        (const char **) & kernelSource, NULL, &err);

    clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

    kernel = clCreateKernel(program, "vecAdd", &err);

    cl_mem d_test = clCreateBuffer(context, CL_MEM_READ_WRITE, 3 * bytes, NULL, NULL);
    d_a = d_test;
    cl_buffer_region dPtrRegion;
    dPtrRegion.origin = bytes;
    dPtrRegion.size = bytes;
    d_b = clCreateSubBuffer(d_test, CL_MEM_READ_ONLY, CL_BUFFER_CREATE_TYPE_REGION, &dPtrRegion, &err);
    dPtrRegion.origin = bytes * 2;
    dPtrRegion.size = bytes;
    d_c = clCreateSubBuffer(d_test, CL_MEM_WRITE_ONLY, CL_BUFFER_CREATE_TYPE_REGION, &dPtrRegion, &err);


    err = clEnqueueWriteBuffer(queue, d_a, CL_TRUE, 0,
                               bytes, h_a, 0, NULL, NULL);
    err |= clEnqueueWriteBuffer(queue, d_b, CL_TRUE, 0,
                                bytes, h_b, 0, NULL, NULL);

    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_a);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_b);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &d_c);
    err |= clSetKernelArg(kernel, 3, sizeof(unsigned int), &n);

    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, &localSize,
                                 0, NULL, NULL);

    clFinish(queue);

    clEnqueueReadBuffer(queue, d_c, CL_TRUE, 0,
                        bytes, h_c, 0, NULL, NULL );
    double sum = 0;
    for(i=0; i<n; i++)
        sum += h_c[i];
    printf("final result: %f\n", sum/n);

    // release OpenCL resources
    clReleaseMemObject(d_a);
    clReleaseMemObject(d_b);
    clReleaseMemObject(d_c);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    free(h_a);
    free(h_b);
    free(h_c);

    return 0;
}