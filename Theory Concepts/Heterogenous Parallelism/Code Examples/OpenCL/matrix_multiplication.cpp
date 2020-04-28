
#include <stdio.h>
#include <stdlib.h>
#include <opencl.h>


int main(int argc, char** argv) {

	// Allocation of pointers for array data
	cl_float *a_data;
	cl_float *b_data;
	cl_float *c_data;
	
	// Accept argument to determine dimension of array
	const int N = atoi(argv[1]);
	
	cl_int size = N;
	cl_int count = N*N;

	// OpenCL declarations
	cl_uint num_devs_returned;
	cl_context_properties properties[3];
	cl_device_id device_id;
	cl_int err;
	cl_platform_id platform_id;
	cl_uint num_platforms_returned;
	cl_context context;
	cl_command_queue command_queue;
	cl_program program;
	cl_kernel kernel;
	cl_mem a_in, b_in, c_out;

	// OpenCL Workgroups
	size_t global[2];
	size_t local[2];
	
	FILE *fp;
	long filelen;
	long readlen;
	char *kernel_src; // char string to hold kernel source

	int x,y;
	int data=0;

	// Sequential memory allocation for arrays
	a_data = malloc(sizeof(cl_float)*count);
	b_data = malloc(sizeof(cl_float)*count);
	c_data = malloc(sizeof(cl_float)*count);

	// Initialization of arrays with data
	// Initializing C to 0 should help clear cache
	for(y=0;y<size;y++) {
		for(x=0;x<size;x++) {
			a_data[y*size+x]= 1;
			b_data[y*size+x]= 2;
			c_data[y*size+x]= 0;
			data++;
		}
	}

	// Checking file length of OpenCL Kernel
	fp = fopen("matrix_mul_kernel.cl","r");
	fseek(fp,0L, SEEK_END);
	filelen = ftell(fp);
	rewind(fp);

	// Read kernel into OpenCL Kernel Source
	kernel_src = malloc(sizeof(char)*(filelen+1));
	readlen = fread(kernel_src,1,filelen,fp);
	if(readlen!= filelen) {
		printf("error reading file\n");
		exit(1);
	}

	// ensure the string is NULL terminated
 	kernel_src[filelen+1]='\0';

	// Get the OpenCL Platform IDs
	err = clGetPlatformIDs(1, &platform_id, &num_platforms_returned);
	if (err != CL_SUCCESS) {
		printf("Error getting platform IDs");
		exit(1);
	}
	
	// Get the OpenCL Device IDs
	err = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devs_returned);
	if (err != CL_SUCCESS) {
		printf("Error getting device IDs");
		exit(1);
	}

	properties[0] = CL_CONTEXT_PLATFORM;
	properties[1] = (cl_context_properties) platform_id;
	properties[2] = 0;


	// Create OpenCL Context using properties
	context = clCreateContext(properties, 1, &device_id, NULL, NULL, &err);
	if (err != CL_SUCCESS) {
		printf("Error creating context");
		exit(1);
	}

	// Command Queue with profiling enabled for timing information
	command_queue = clCreateCommandQueue(context, device_id, CL_QUEUE_PROFILING_ENABLE, &err);
	if (err != CL_SUCCESS) {
		printf("Error creating command queue");
		exit(1);
	}

	// Create Program using kernel source
	program = clCreateProgramWithSource(context, 1, (const char **) &kernel_src, NULL, &err);
	if (err != CL_SUCCESS) {
		printf("Error creating program");
		exit(1);
	}

	// Build the program
	err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	if (err != CL_SUCCESS) {
		printf("Error building program");
		exit(1);
	}

  // Build kernel to be executed
	kernel = clCreateKernel(program, "mat_mul", &err);
	if (err != CL_SUCCESS) {
		printf("Error creating kernel");
		exit(1);
	}


	// Create buffers for global memory access
	a_in  = clCreateBuffer(context, CL_MEM_READ_ONLY|CL_MEM_COPY_HOST_PTR, sizeof(cl_float)*count,
												a_data, NULL);
	b_in  = clCreateBuffer(context, CL_MEM_READ_ONLY|CL_MEM_COPY_HOST_PTR, sizeof(cl_float)*count,
												b_data, NULL);
	c_out = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(cl_float)*count, NULL, NULL);


	// Set kernel arguments so that they can be passed correctly
	err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &a_in);
	err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &b_in);
	err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &c_out);
	err |= clSetKernelArg(kernel, 3, sizeof(cl_int), &size); // for adding
	if (err != CL_SUCCESS) {
		printf("Error setting kernel arguments");
		exit(1);
	}

	global[0] = size;
	global[1] = size;

	local[0] = 8;
	local[1] = 8;

	cl_event event;  // new event for profiling
	err = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global, local, 0, NULL, &event);
	if (err != CL_SUCCESS) {
		printf("Error placing kernel in command queue: %d", err);
		exit(1);
	}

	clWaitForEvents(1, &event);
	cl_ulong time_start = (cl_ulong)0;
	cl_ulong time_end   = (cl_ulong)0;
  clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_START, sizeof(cl_ulong),
																 &time_start, NULL);
	clGetEventProfilingInfo(event, CL_PROFILING_COMMAND_END, sizeof(cl_ulong),
																 &time_end, NULL);

	unsigned long runtimegpu = (unsigned long)((time_end - time_start)); // time in nsec
  unsigned long totalops   = 2*(unsigned long)size*(unsigned long)size*(unsigned long)size;
	printf("Using matrices of size N = %d\n", size);
	printf("Execution time in usec: %lu nsec\n", runtimegpu);
	printf("Total operations: %lu FLOP\n", totalops);
	printf("Total bandwidth:  %lu GFLOP/s\n", totalops/runtimegpu);
	
	

	err = clEnqueueReadBuffer(command_queue, c_out, CL_TRUE, 0, sizeof(cl_float)*count,c_data, 0, NULL, NULL);

	clFinish(command_queue);


	// Clean up of OpenCL structures
	clReleaseMemObject(a_in);
	clReleaseMemObject(b_in);
	clReleaseMemObject(c_out);
	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);


	printf("Success\n");

	printf("\nMatrix A\n");
	for (y = 0; y < size; y++) {
		for (x = 0; x < size; x++) {
			printf("%.2f ", a_data[y*size + x]);
		}
		printf("\n");
	}
	printf("\nMatrix B\n");
	for (y = 0; y < size; y++) {
		for (x = 0; x < size; x++) {
			printf("%.2f ", b_data[y*size + x]);
		}
		printf("\n");
	}
	printf("\nMatrix C\n");
	for (y = 0; y < size; y++) {
		for (x = 0; x < size; x++) {
			printf("%.2f ", c_data[y*size + x]);
		}
		printf("\n");
	}


	// Clean up of normal structures
	free(kernel_src);
	free(a_data);
	free(b_data);
	free(c_data);
	return 0;
}