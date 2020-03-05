# Vectorization and Predication

## Flynn's Taxonomy

Flynn's Taxonomy says that, in two dimensions, Data streams and Instruction Streams, styles of organisation are given by
1. SISD - Single Instruction Single Data
   1. Single-Core Processors
   2. Example : Add<sub>32</sub> R1, R2, R3
2. SIMD - Single Instruction Multiple Data
   1. GPUs
   2. Intel SSE/AVX extensions
   3. Example : vAdd<sub>32</sub> X<sub>1</sub>[0..128], X<sub>2</sub>[0...128], X<sub>3</sub>[0...128]
3. MISD - Multiple Instruction Single Data
   1. Systolic Arrays
4. MIMD - Multiple Instruction Multiple Data
   1. VLIW
   2. Parallel Computers
   3. Example : VLIW instruction execution

Intel SIMD registers come in forms of
1. XMM0 - XMM15
   1. 128 bit registers
   2. SSE
2. YMM0 - YMM15
   1. 256 bit registers
   2. AVX, AVX2
3. ZMM0 - ZMM15
   1. 512 bit registers
   2. AVX-512

ZMM0 overlaps with YMM15, and YMM0 overlaps with XMM15. This is done to efficiently use the width of such long registers.

## Vectorization

If the code is simple, compiler will do the vectorization. The flags -O3 -mavx -mavx2 performs this auto-vectorization, on gcc.

Intrinsic SIMD instructions can be used instead of autovectorizing the code. 
For example
```
__m256 a, b, c;
__m256 d = _mm256_fmadd_ps(a, b, c);
```
Where __m256 are 256 bit multimedia registers. _mm256_fmadd_ps does floating point multiplication and add on these operands.

Similarly we can declare __m128 (128 bit vector containing 4 floats), __m128d (128 bit vector containing 2 doubles) and __m128i (128 bit vectors containing integers), and the same ofr __m256 and __m512.

_ps is single precision, _pd being double precisions, and _epiNNN is a packed signed integer and so on.

The instructions can be of various types
1. Initialisation
   1. _mm256_setzero_ps/pd/epi32/...
   2. _mm256_set_...
2. Load/Store : Address must be aligned by 256 bit
   1. _mm256_load_...
   2. _mm256_store_...
3. Masked read/write, strided reads, etc

For example
```
__mm256d t = _mm256_load_pd(double const * mem); // Loads 4 double values from mem to t
__mm256i v = _mm256_set_epi32(h,g,f,e,d,c,b,a); // Loads 8 integer values to v 
```

## Vertical Vector Instructions

Some vertical vector operations are
1. Add/Subtract/Multiply
2. Max/Min/GreaterThan/Equals
3. Reciprocal/Shifts
4. FMA (Fused Multiply Add)
   1. (a x b)+C, c - a x b, a x c + b

### Integer multiplication caveat

When a multiplication occurs, overflow might happen. 
This is handled by telling the processor to multiply the upper 2 or lower 2 registers. This is fine only if the values can be truncated.

## Horizontal Vector Instructions

1. Horizontal Add/Subtract
   1. _hadd instruction, to add values of the same vector, say if we want to add the first two values of the vector A, last two of A, first two of B and last 2 of B, in a single bit-array.
2. Shuffling/Permutation (Can be within 128 bit lanes or Accross 128 bit lanes)
   1. _shuffle
   2. _permute
      1. This is given by selecting the numbers through a select clause.
3. Blend
   1. Merges two vectors using a control.
4. Alignr
5. Helper Instructions
   1. Cast
   2. Convert
   3. Movemask

## Predication

Vectorisation can be done on very simple loops. But if the loops become complex, we can face a lot of issues.

In predication, we associate a boolean condition (predicate) with the issue, execution, or the commit of an instruction. The stage in which this predicate is tested is an implementation choice.

If the predicate is true, instruction is kept, else it is nullified.

Partial predication is when only a few opcodes can be predicated.
Full predication is when every instruction is predicated.

This is used in cases where branch predictors don't work very well.

Predication converts control dependence to data dependence. For example
```
if(C1)
      S1
      S3
      S5
      S7
      . 
      .
      .
      SN
else
      S2
      S4
      S6
      .
      .
      .
      SN
```
is converted to 
```
P <- C1
[P] S1
[P] S3
[P] S5
[P] S7
.
.
.
[P] SN

[!P] S2
[!P] S4
[!P] S6
.
.
.
[!P] SN
```

The benefits of predication are
1. Allows compiler to overlap execution of independent control constructs w/o code explosion
2. Allows compiler to reduce frequency of branch mispredictions
3. Reduces number of branch tests
4. Reduces number of multiple execution paths and hardware costs
5. Allows code movement in superblocks

This comes with certain cost
1. Increased fetch utilisation
2. Increased register consumption
3. Increased functional unit utilisation, if tested at commit time
4. Increased complexity of exception handling
5. Larger instructions impacting l-cache

Depending upon the implementation, the instructions may be executed from both sides of the branch into the pipeline. 

If predicated support exists, the hardware ensures that at the writeback stage, only those instructions are committed which need to be executed, based on the predicate.

This is beneficial for vectorisation, and minimising branch misprediction. This also ensures that the pipeline reaches the right state in the end. A branch need not be resolved for the prediction, and if a branch is mispredicted, we don't face any penalty.

The main issues with predication is Interrupt handling. It may cause some exceptions that may occur only because of predication, in an imprecise fashion. This usually happens when extra work is done when it is not necessary.

Once the predicate is resolved, the branch which goes the opposite way stops executing.

Partial predication is done by conditional moves.
```
CMOV R1, R2, R3
```
This moves R2 to R1 if R3 = 0.
Select and Nullify can also be used for partial predication.

In Full Predication, all instructions have a predicated version. In this, all registers can be used as predicate register.

## Aligned Access

Aligned access are used for better performance and low exceptions. In this, data is aligned to an n-byte boundary.
```
void* _mm_malloc(int size, int n)
int posix_memaligned( void **p, site_t n, size_t size)
```
Aligment is done for variable declarations as
```
__attribute__((aligned(n))) var_name
__declspec(align(n)) var_name
```
This is done for vectorization of these variables.
This is mentioned to the compuler using a #pragma vector aligned directive.