__kernel void mat_mul(__global float *A,
										  __global float *B,
											__global float *C,
											const int size)
{

	int x = get_global_id(0);
	int y = get_global_id(1);
	int k;

	float tmp = 0.0;

	// Matrix multiply	
	for (k = 0; k < size; k++) {
		tmp += A[y*size + k] * B[k*size + x];
	}

	C[y*size + x] = tmp;
}