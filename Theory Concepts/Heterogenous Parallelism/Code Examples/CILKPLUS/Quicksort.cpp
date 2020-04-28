#include <cilk/cilk.h>
#include "cilktime.h"
#include <bits/stdc++.h>

using namespace std;

void qsort(int * begin, int * end) {
	if (begin != end) {
		--end; 
		int * middle = partition(begin, end,
				bind2nd(less<int>(), *end));
		using swap;
		swap(*end, *middle);    
		qsort(begin, middle);
		qsort(++middle, ++end); 
	}
}

int qmain(int n) {
	int* a = new int[n];

	for (int i = 0; i < n; ++i)
		a[i] = i;

	random_shuffle(a, a + n);
	cout << "Sorting " << n << " integers" << endl;

	unsigned long long start_ticks = cilk_getticks();
	qsort(a, a + n);
	unsigned long long end_ticks = cilk_getticks();

	// Confirm that a is sorted and that each element contains the index.
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] >= a[i + 1] || a[i] != i) {
			cout << "Sort failed at location i=" << i << " a[i] = " << a[i]
					<< " a[i+1] = " << a[i + 1] << endl;
			delete[] a;
			return 1;
		}
	}

	unsigned long long ticks = end_ticks - start_ticks;
	cout << "Sort succeeded in " << ticks << " milliseconds." << endl;
	delete[] a;
	return 0;
}

int main(int argc, char* argv[]) {
	int n = 10 * 1000 * 1000;
	if (argc > 1) {
		n = atoi(argv[1]);
		if (n <= 0) {
			cerr << "Invalid argument" << endl;
			cerr << "Usage: qsort N" << endl;
			cerr << "       N = number of elements to sort" << endl;
			return 1;
		}
	}

	return qmain(n);
}