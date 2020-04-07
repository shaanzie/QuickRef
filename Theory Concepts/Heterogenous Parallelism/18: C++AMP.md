# C++AMP

- Uses the header file amp.h
- Example

```
#include<amp.h>

using namespace concurrency;

void AddArrays(int n, int* pA, int* pB, int* pSum)
{
    array_view<int, 1> a(n, pA);    // Array view wraps data to operate
    array_view<int, 1> a(n, pB);    // Type of array and length
    array_view<int, 1> a(n, pSum);

    parallel_for_each(              // Parallel for loop
        sum.extent,[=](index<1> i) restrict(amp)    // Index = Thread_ID
        {                                           // Restrict ensures code complies to C++AMP
            sum[i] = a[i] + b[i]
        }
    )
}
```

- `index<N>` - N dimensional point
- `extent<N>` - Number of units in each dimension
- `array_view<T, N>` - View on existing data
  - Dense in least significant dimension
  - Element of type T and rank N
  - Rectangular
  - Access anywhere
- `parallel_for_each` - Executes kernel for each point in the extent, async
- `restrict` - informs the compiler to conform to C++AMP rules
  - Allows only C++ types
  - All functions are inlinable
- `array<N>` - Container for arrays, interchangeable with array_view for most cases

- parallel_for_each uses a tiled overhead approach
  - Schedule threads in tiles
  - tiled_index accepted as thread IDs.
- 