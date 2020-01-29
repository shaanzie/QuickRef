#define _GLIBCXX_USE_CXX11_ABI 0
#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <chrono>
#include <ctime>
#include <string.h>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

  void generateMergeSortData (int* arr, size_t n);
  void checkMergeSortResult (int* arr, size_t n);

#ifdef __cplusplus
}
#endif

void bubblesort1(int * A, int n) {
  for (int i = 0; i < n; ++i)
  {
    for (int j = 1; j < n; ++j)
    {
      if (A[j] < A[j-1])
      {
        int temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
      }
    }
  }
}

void bubblesort11(int * A, int n, int g, int nbthreads) {
  cout<<"bubblesort"<<endl;
  for (int i = 0; i < n; ++i)
  {
    
      #pragma omp for
      for (int j = 1; j < n; j+=2)
      {
        if (A[j] < A[j-1])
        {
          int temp = A[j];
          A[j] = A[j-1];
          A[j-1] = temp;
        }
      }

      #pragma omp barrier

      #pragma omp for
      for (int j = 2; j < n; j+=2)
      {
        if (A[j] < A[j-1])
        {
          int temp = A[j];
          A[j] = A[j-1];
          A[j-1] = temp;
        }
      }
      #pragma omp barrier
  }
}


// void swap(int * A, first, last) {
//   for (int i = first; i < last; ++i)
//   {
//     if (A[j] < A[j-1])
//     {
//       int temp = A[j];
//       A[j] = A[j-1];
//       A[j-1] = temp;
//     }
//   }
// }

void bubblesort(int * A, int n, int granularity, int nbthreads) {
  int first, last;

  for (int i = 0; i < ceil(n/2); ++i)
  {
    #pragma omp parallel
    {
      #pragma omp for
      for(int k=0; k<n; k+=granularity)
      {
        first = k;
        last = k+granularity;
        if (last >= n)
          last = n-1;
        
        for (int j = first; j < last; j+=2)
        {
          if (A[j+1] < A[j])
          {
            int temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
          }
        }
      }
      // #pragma omp taskwait
      #pragma omp for
      for(int k=0; k<n; k+=granularity)
      {
        first = k;
        last = k+granularity;
        if (last >= n)
          last = n-1;
        
        for (int j = first+1; j < last; j+=2)
        {
          if (A[j+1] < A[j])
          {
            int temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
          }
        }
      }      
    }

    // #pragma omp taskwait
  }
}

int main (int argc, char* argv[]) {

  //forces openmp to create the threads beforehand
#pragma omp parallel
  {
    int fd = open (argv[0], O_RDONLY);
    if (fd != -1) {
      close (fd);
    }
    else {
      std::cerr<<"something is amiss"<<std::endl;
    }
  }
  
  if (argc < 5) {
    std::cerr<<"Usage: "<<argv[0]<<" <n> <nbthreads> <schedule> <granularity>"<<std::endl;
    return -1;
  }

  int * arr = new int [atoi(argv[1])];

  generateMergeSortData (arr, atoi(argv[1]));
  
  //write code here

  int n = atoi(argv[1]);
  int nbthreads = atoi(argv[2]);
  int granularity = atoi(argv[4]);
  if(granularity%2 != 0)
    granularity-=1;
  if(granularity<4)
    granularity=4;
  if(granularity>n)
    granularity=n;

  std::chrono::time_point<std::chrono::system_clock> start, end;

  omp_set_num_threads(nbthreads);

  // bubblesort(arr, n);
  // int *tempArr = new int [atoi(argv[1])];
  // tempArr = (int*)malloc(n*sizeof(int));

  #pragma omp parallel
  {
     //#pragma omp single
    //{
      bubblesort11(arr, n, granularity, nbthreads);
    //}
  }

  checkMergeSortResult (arr, atoi(argv[1]));

  start = std::chrono::system_clock::now();

  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  //cout<<"num of threads: "<<omp_get_num_threads()<<endl;
  std::cerr<<elapsed_seconds.count()<<endl;
  // std::cout<<sum<<endl;
  
  delete[] arr;

  return 0;
}