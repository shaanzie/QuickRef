# Sorting in Parallel

Sorting can be internal or external, where in internal sorting, the number of elements to be sorted is small enough to fit in the process' main memory, whereas external sorts store auxillary memory.
Sorting can be comparison based or non-comparison based.

## Issues in Sorting on Parallel Computers

1. Where the Input and Output Sequences are stored
   1. Sequences can reside in only one process, or be distributed
2. How comparisons are performed
   1. One element per process
      1. Compare exchange
      2. Send both elements to both processes, and each process compares received element with its own and retains the appropriate one
   2. More than one element per process
      1. A block of n/p elements per processor
      2. Compare split operation where each process merges the two blocks and keeps the appropriate half of the merged block.

## Bubble Sort and its Variants

### Odd-Even Transposition

The odd-even transposition sorts n elements in n phases (n is even), each of which requires n/2 compare-exchange operations. The algorithm alternates between odd and even phases, wherein the odd phase, elements with odd indices are compared with their right neighbours, and if they are out of sequence, they are exchanged. In an even phase, the same thing happens for even indices. This gives a parallel runtime of O(n).

To obtain cost optimality, fewer processes are used, with each process assigned a block of n/p elements, which gets sorted internally. After this, the processes execute p phases (p/2 odd and p/2 even), performing compare-split operations.

The parallel runtime is given by T<sub>p</sub> = O(n/p log (n/p)) + O(n) + O(n).

### Shellsort

The main limitation of the odd even transposition sort is that it moves elements only one position at a time. Shellsort moves elements over long distances.

Each process is assigned to a block of n/p elements, where the processes are considered to be arranged in a logical one dimensional sequence, and the ordering of processes in the array define the global ordering of the sorted sequence.
During the first phase, processes that are far away from each other in the array compare-split their elements. During the second phase, the algorithm switches to a odd-even transposition sort. The odd and even phases are performed only as long as the blocks on the processes are changing. Because of the first phase, the number of odd even phases may be substantially smaller than p.

This in complexity translates to T<sub>p</sub> = O(n/p log(n/p)) + O(n/p log p) + O(ln/p). The value of l denotes the phases and the performance of shell sort depends on this value.

## Quicksort
 
### Shared Address Space Parallel Formulation

Each process is assigned a continuous block of n/p elements. The algorithm selects a pivot element, rearranges its assigned block of elements with two subblocks, same as the quicksort partitioning scheme. Then, the algorithm partitions the processes into two groups, and one sorts the elements smaller than the pivot, and the other larger than the pivot.

In order to globally rearrange the elements of A into the smaller and larger subarrays, each element's position must be known at the end of the rearrangement. This is done by concatenating all the blocks in increasing order of process label.

There are 4 key steps needed to be performed
1. Determine and broadcast the pivot
2. Locally rearrange the array
3. Determine locations of each element in the rearrangement
4. Perform global rearrangement

The complexity is T = O(n/p log(n/p)) + O(n/p log p) + O(log<sup>2</sub>p).

### Message Passing Parallel Formulation

In the MP version, each process stores n/p elements of the array. This array is also partitioned around a particular pivot element using a two phase approach. The first phase is the same as the shared address space approach. In the next phase, the algorithm first determines which processes will be responsible for recursively sorting the larger than the pivot subarrays. After this, the processes are partitioned into smaller-than-pivot and larger groups, and then the recursion ends when each subarray is assigned to a single process.

