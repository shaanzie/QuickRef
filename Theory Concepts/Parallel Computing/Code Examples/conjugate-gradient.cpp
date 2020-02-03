
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string.h>

#ifdef OPENMP
#include <omp.h>
#endif

using namespace std;


/******************************************************************************/
/* Set the variable parameters for the simulation here. Note that             */
/* the number of threads for the OpenMP implementation can be set             */
/* at the command line.                                                       */
/******************************************************************************/

//! Number of nodes in the i & j directions
#define NUM_NODES 256

//! Flag controlling whether to write Tecplot mesh/solution files (Yes=1,No=0)
#define VISUALIZE 1

//! Iteration frequency with which to print to console and write output files
#define FREQUENCY 50

//! Convergence criteria in terms of orders reduction in the L2 norm
#define TOLERANCE 1e-12


/******************************************************************************/
/* Function prototypes. All necessary functions are contained in this file.   */
/******************************************************************************/

//! Allocates and initializes all of the arrays needed in the program
void allocate_arrays(double **A, int **rowA, int **colA, double **x, double **b,
                     int n_nodes);

//! Driver routine for the conjugate gradient method
void conjugate_gradient(double *A, int *rowA, int *colA, double *x, double *b,
                        int n_nodes, double tol, bool viz, int freq);

//! Subroutine for calculating a sparse matrix-vector product
void sp_mv_product(double *result, double *A, int *rowA, int *colA, double *x,
                   int n);

//! Subroutine for adding a vector to another multiplied by a constant
void daxpy(double *result, double alpha, double *x, double *y, int n);

//! Subroutine for calculating the dot product of two length n vectors
double dot_product(double *x, double *y, int n);

//! Subroutine for taking the L-2 norm of a vector
double vector_norm(double *vec, int n);

//! Subroutine for performing a deep copy of a vector
void vector_copy(double *vec_in, double *vec_out, int n);

//! Subroutine for writing solution information to Tecplot files
double write_output(double *x, int n_nodes);

//! Subroutine for deallocating all dynamic memory in the program
void deallocate_arrays(double *A, int *rowA, int *colA, double *x, double *b);


/******************************************************************************/
/* Main function driving the high-level solver execution.                     */
/******************************************************************************/

int main(int argc, char* argv[]) {
  
  //! Local variables and settings (defined above) for the poisson problem
  
  bool viz = VISUALIZE;
  int freq = FREQUENCY, n_nodes = NUM_NODES, n = (n_nodes-2)*(n_nodes-2);
  double tol = TOLERANCE, center_sol, StartTime, StopTime, UsedTime;
  
  //! Check for number of threads for the OpenMP version
  
#ifdef OPENMP
  int n_threads = omp_get_num_procs();
  if (argc != 2){
    printf( "\n   !!! Error !!!\n" );
    printf( " Incorrect thread number specification.\n");
    printf( " Proper usage: ./cg_openmp [n_threads]\n\n");
    exit(1);
  } else {
    n_threads = atoi(argv[1]);
  }
  omp_set_num_threads(n_threads);
#endif
  
  //! Print initial message to console
  
  printf("\n");
  printf("#============================================#\n");
  printf("# Conjugate Gradient (CG) Poisson solver.    #\n");
  printf("#============================================#\n\n");
  
  //! Pointers to arrays that we need throughout the solver
  
  double *A, *x, *b;
  int *rowA, *colA;
  
  //! Allocate memory and initialize the grid and solution arrays
  
  allocate_arrays(&A, &rowA, &colA, &x, &b, n_nodes);
  
  //! Start the timer for benchmarking
  
  StartTime = double(clock())/double(CLOCKS_PER_SEC);
#ifdef OPENMP
  StartTime = omp_get_wtime();
#endif
  
  //! Solve the system using the Conjugate Gradient method
  
  conjugate_gradient(A, rowA, colA, x, b, n, tol, viz, freq);
  
  //! Stop the timer
  
#ifdef OPENMP
  StopTime = omp_get_wtime();
  UsedTime = StopTime-StartTime;
#else
  StopTime = double(clock())/double(CLOCKS_PER_SEC);
  UsedTime = StopTime-StartTime;
#endif
  
  //! Write a Tecplot solution file and report center solution
  
  if (viz) center_sol = write_output(x, n_nodes);
  
  //! Free all memory used by the solver
  
  deallocate_arrays(A, rowA, colA, x, b);
  
  //! Print the total time for performance benchmarking.
  
#ifdef OPENMP
  cout << "\nCompleted in " << fixed << UsedTime << " seconds with ";
  cout << n_threads << " threads." << endl;
#else
  cout << "\nCompleted in " << fixed << UsedTime;
  cout << " seconds in serial." << endl;
#endif
  
  //! Print final message to console
  
  if (viz) {
    printf("Solution at domain center: %1.15f\n", center_sol);
    printf("#============================================#\n\n");
  } else printf("#============================================#\n\n");
  
  return 0;
}

void allocate_arrays(double **A, int **rowA, int **colA, double **x,
                     double **b, int n_nodes) {
  
  //! Perform allocation using temporary pointers
  
  int offset = (n_nodes-2);
  int n_unknowns = offset*offset;
  int *rowA_temp, *colA_temp;
  double *A_temp, *x_temp, *b_temp;
  
  //! Compute the global mesh spacing squared, and constant RHS
  
  double h2 = pow(1.0/((double)n_nodes-1.0),2.0);
  
  //! Allocate 1D arrays
  
  x_temp = new double[n_unknowns];
  b_temp = new double[n_unknowns];
  
  //! Initialize solution and rhs vectors.
  //! RHS is k, set to 1.0 for the assignment.
  
  for (int i = 0; i < n_unknowns; i++) {
    x_temp[i]  = 0.0;
    b_temp[i]  = 1.0*h2;
  }
  
  //! Allocate A matrix. We will use the CSR format for the sparse matrix
  //! First get nnz, which is the total number of matrix entries for the
  //! Poisson problem. Set up the rowA vector as we go.
  
  rowA_temp = new int[n_unknowns+1];
  int i_unknown = 0, nnz = 0;
  rowA_temp[0] = nnz;
  
  for (int i = 0; i < offset; i++) {
    for (int j = 0; j < offset; j++) {
      
      //! Increment nnz depending on whether we're a corner,
      //! boundary, or interior node (i.e., how many neighbors).
      
      if (i == 0 && (j == 0 || j == offset-1))
        nnz += 3;
      else if (i == offset-1 && (j == 0 || j == offset-1))
        nnz += 3;
      else if (i == 0 || i == offset-1)
        nnz += 4;
      else if (j == 0 || j == offset-1)
        nnz += 4;
      else
        nnz += 5;
      
      //! Increment the row pointer
      
      rowA_temp[i_unknown+1] = nnz;
      i_unknown++;
      
    }
  }
  
  //! Allocate the arrays for the CSR representation of matrix A
  
  A_temp    = new double[nnz];
  colA_temp = new int[nnz];
  
  //! Initialize our discrete Poisson matrix
  
  int row_start, k = 0;
  
  for (int i = 0; i < offset; i++) {
    for (int j = 0; j < offset; j++) {
      
      //! Store the start index of the row more clearly
      
      row_start = rowA_temp[k];
      
      //! Build the A matrix depending on our location.
      
      if (i == 0 && j == 0) { //! top left corner
        
        A_temp[row_start]   = -4;
        A_temp[row_start+1] = 1;
        A_temp[row_start+2] = 1;
        
        colA_temp[row_start]   = k;
        colA_temp[row_start+1] = k+1;
        colA_temp[row_start+2] = k+offset;
        
      } else if (i == 0 && j == offset-1) { //! top right corner
        
        A_temp[row_start]   = 1;
        A_temp[row_start+1] = -4;
        A_temp[row_start+2] = 1;
        
        colA_temp[row_start]   = k-1;
        colA_temp[row_start+1] = k;
        colA_temp[row_start+2] = k+offset;
        
      } else if (i == offset-1 && j == 0) { //! bottom left corner
        
        A_temp[row_start]   = 1;
        A_temp[row_start+1] = -4;
        A_temp[row_start+2] = 1;
        
        colA_temp[row_start]   = k-offset;
        colA_temp[row_start+1] = k;
        colA_temp[row_start+2] = k+1;
        
      } else if (i == offset-1 && j == offset-1) { //! bottom right corner
        
        A_temp[row_start]   = 1;
        A_temp[row_start+1] = 1;
        A_temp[row_start+2] = -4;
        
        colA_temp[row_start]   = k-offset;
        colA_temp[row_start+1] = k-1;
        colA_temp[row_start+2] = k;
        
      } else if (i == 0) { //! top row
        
        A_temp[row_start]   = 1;
        A_temp[row_start+1] = -4;
        A_temp[row_start+2] = 1;
        A_temp[row_start+3] = 1;
        
        colA_temp[row_start]   = k-1;
        colA_temp[row_start+1] = k;
        colA_temp[row_start+2] = k+1;
        colA_temp[row_start+3] = k+offset;
        
      } else if (i == offset-1) { //! bottom row
        
        A_temp[row_start]   = 1;
        A_temp[row_start+1] = 1;
        A_temp[row_start+2] = -4;
        A_temp[row_start+3] = 1;
        
        colA_temp[row_start]   = k-offset;
        colA_temp[row_start+1] = k-1;
        colA_temp[row_start+2] = k;
        colA_temp[row_start+3] = k+1;
        
      } else if (j == 0) { //! left column
        
        A_temp[row_start]   = 1;
        A_temp[row_start+1] = -4;
        A_temp[row_start+2] = 1;
        A_temp[row_start+3] = 1;
        
        colA_temp[row_start]   = k-offset;
        colA_temp[row_start+1] = k;
        colA_temp[row_start+2] = k+1;
        colA_temp[row_start+3] = k+offset;
        
      } else if ( j == offset-1) { //! right column
        
        A_temp[row_start]   = 1;
        A_temp[row_start+1] = 1;
        A_temp[row_start+2] = -4;
        A_temp[row_start+3] = 1;
        
        colA_temp[row_start]   = k-offset;
        colA_temp[row_start+1] = k-1;
        colA_temp[row_start+2] = k;
        colA_temp[row_start+3] = k+offset;
        
      } else { //! interior
        
        A_temp[row_start]   = 1;
        A_temp[row_start+1] = 1;
        A_temp[row_start+2] = -4;
        A_temp[row_start+3] = 1;
        A_temp[row_start+4] = 1;
        
        colA_temp[row_start]   = k-offset;
        colA_temp[row_start+1] = k-1;
        colA_temp[row_start+2] = k;
        colA_temp[row_start+3] = k+1;
        colA_temp[row_start+4] = k+offset;
        
      }
      
      //! Increment our counter for the unknown index
      
      k++;
      
    }
  }
  
  //! Set the pointers to the correct memory for use outside the function
  
  *A    = A_temp;
  *rowA = rowA_temp;
  *colA = colA_temp;
  *x    = x_temp;
  *b    = b_temp;
  
}

void conjugate_gradient(double *A, int *rowA, int *colA, double *x, double *b,
                        int n, double tol, bool viz, int freq) {
  
  //! Initial variables.
  
  int iter = 0;
  double resid, resid0, resid2, alpha, beta;
  
  //! Allocate auxiliary vectors for the CG algorithm
  
  double *r = new double[n];
  double *p = new double[n];
  double *mv_product = new double[n];
  
  //! Initialize the rOld and pOld
  
  sp_mv_product(mv_product, A, rowA, colA, x, n);
  daxpy(r, -1.0, mv_product, b, n);
  vector_copy(r, p, n);
  
  //! Initialize the residual
  
  resid  = vector_norm(r,n)/vector_norm(b,n); resid0 = resid;
  if (viz) {
    printf("  Iteration         Residual \n");
    printf("  -------------------------- \n");
    printf("    %6d     %13e \n", iter, resid/resid0);
  }
  
  while ( resid/resid0 > tol && iter < n ) {
    
    //! CG iteration
    
    iter  = iter + 1;
    
    //! Sparse matrix-vector product (major portion of the work)
    
    sp_mv_product(mv_product, A, rowA, colA, p, n);
    
    //! Compute the alpha step
    
    resid2 = dot_product(r, r, n);
    alpha  = resid2/dot_product(p, mv_product, n);
    
    //! Update the value of the solution
    
    daxpy(x, alpha, p, x, n);
    
    //! Residual update (mv_product still holds A*p)
    
    daxpy(r, -1.0*alpha, mv_product, r, n);
    
    //! Compute the beta value
    
    beta = dot_product(r, r, n)/resid2;
    
    //! Update the p vector
    
    daxpy(p, beta, p, r, n);
    
    //! Convergence criteria.
    
    resid = vector_norm(r,n)/vector_norm(b,n);
    
    //! Output to console if requested
    
    if (viz && (iter%freq == 0))
      printf("    %6d     %13e \n", iter, resid/resid0);
    
  }
  
  //! Print final residual to screen
  
  if (viz && (iter%freq != 0))
    printf("    %6d     %13e \n", iter, resid/resid0);
  
  //! Free memory and exit
  
  delete [] r;
  delete [] p;
  delete [] mv_product;
  
}

void sp_mv_product(double *result, double *A, int *rowA, int *colA, double *x,
                   int n) {
  
  //! Compute the sparse matrix-vector product (CSR format)
  
  int row_ind, index;
  
#ifdef OPENMP
#pragma omp parallel for default(none) \
private(row_ind,index) shared(result,A,rowA,colA,x,n)
#endif
  for (row_ind = 0; row_ind < n; row_ind++) {
    result[row_ind] = 0.0;
    for (index = rowA[row_ind]; index < rowA[row_ind+1]; index++) {
      result[row_ind] += A[index]*x[colA[index]];
    }
  }
  
}

void daxpy(double *result, double alpha, double *x, double *y, int n) {
  
  //! Compute the addition of a vector with a vector times a constant
  
  int i;
  
#ifdef OPENMP
#pragma omp parallel for default(none) \
private(i) shared(result,alpha,x,y,n)
#endif
  for (i = 0; i < n; i++) {
    result[i] = alpha*x[i] + y[i];
  }
  
}


double dot_product(double *x, double *y, int n) {
  
  //! Compute the dot product of the provided vectors
  
  double result = 0.0; int i;
  
#ifdef OPENMP
#pragma omp parallel for default(none) \
private(i) shared(x,y,n) ordered reduction(+:result)
#endif
  for (i = 0; i < n; i++) {
    result = result + x[i]*y[i];
  }
  
  return result;
}


double vector_norm(double *vec, int n) {
  
  //! Compute the L-2 norm of the provided vector
  
  double norm = 0.0; int i;
  
#ifdef OPENMP
#pragma omp parallel for default(none) \
private(i) shared(vec,n) ordered reduction(+:norm)
#endif
  for (i = 0; i < n; i++) {
    norm += vec[i]*vec[i];
  }
  norm = sqrt(norm);
  
  return norm;
}


void vector_copy(double *vec_in, double *vec_out, int n) {
  
  //! Copy input vector into output vector
  
  int i;
  
#ifdef OPENMP
#pragma omp parallel for default(none) \
private(i) shared(vec_out,vec_in,n)
#endif
  for (i = 0; i < n; i++) {
    vec_out[i] = vec_in[i];
  }
  
}

double write_output(double *x, int n_nodes) {
  
  //! Write tecplot files at each iteration for visualization. The below
  //! is the Tecplot ascii format. Check if files were requested first.
  
  char cstr[200];
  double center_sol = 0.0;
  
  strcpy(cstr, "solution.dat");
  ofstream sol_file;
  sol_file.precision(15);
  sol_file.open(cstr, ios::out);
  sol_file << "TITLE = \"Visualization of a Poisson solution\"" << endl;
  sol_file << "VARIABLES = \"x\", \"y\", \"f\"";
  sol_file << endl;
  sol_file << "ZONE DATAPACKING=BLOCK I=" << n_nodes << ", J=" << n_nodes;
  sol_file << endl;
  
  //! Write the x-coordinates
  
  for (int j = 0; j < n_nodes; j++) {
    for (int i = 0; i < n_nodes; i++) {
      sol_file << (double)i/(double)(n_nodes-1) << " ";
    }
    sol_file << endl;
  }
  
  //! Write the y-coordinates
  
  for (int j = n_nodes-1; j >= 0; j--) {
    for (int i = 0; i < n_nodes; i++) {
      sol_file <<  (double)j/(double)(n_nodes-1) << " ";
    }
    sol_file << endl;
  }
  
  //! Create a 2D array for more easily writing the solution. Note
  //! that we are hard-coding the boundaries to the zero Dirichlet value.
  
  double **solution = new double*[n_nodes];
  for (int i = 0; i < n_nodes; i++) {
    solution[i] = new double[n_nodes];
  }
  
  //! Initialize sol values. Note that we are hard-coding the boundaries
  //! to the zero Dirichlet value.
  
  int k = 0, center = n_nodes/2;
  for (int i = 0; i < n_nodes; i++) {
    for (int j = 0; j < n_nodes; j++) {
      if (i == 0 || j == 0 || i == n_nodes-1 || j == n_nodes-1) {
        solution[i][j] = 0.0;
      } else {
        solution[i][j] = x[k];
        if (i == center && j == center) center_sol = x[k];
        k++;
      }
    }
  }
  
  //! Write the solution
  
  for (int i = 0; i < n_nodes; i++) {
    for (int j = 0; j < n_nodes; j++) {
      sol_file << solution[i][j] << endl;
    }
  }
  sol_file.close();
  
  //! Free memory
  
  for (int i = 0; i < n_nodes; i++)
    delete [] solution[i];
  delete [] solution;
  
  //! Return the value at the center of the domain
  
  return center_sol;
  
}

void deallocate_arrays(double *A, int *rowA, int *colA, double *x, double *b) {
  
  //! Deallocation of all dynamic memory in the program.
  
  delete [] A;
  delete [] rowA;
  delete [] colA;
  delete [] x;
  delete [] b;
  
}