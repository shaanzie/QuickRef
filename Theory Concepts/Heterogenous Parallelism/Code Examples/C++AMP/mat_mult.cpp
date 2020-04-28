#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <SDKDDKVer.h>
#include <iostream>
#include <amp.h>  
#include <ctime>
#include <cstdlib>
using namespace concurrency;

void MultiplyWithAMP() {
	int aMatrix[10000];
		int bMatrix[10000];
		int productMatrix[10000];

		srand((unsigned)time(NULL));

		for (int z = 0; z < 10000; z++) {
			aMatrix[z] = rand();
			bMatrix[z] = rand();
			productMatrix[z] = 0;
		}

	array_view<int, 2> a(100, 100, aMatrix);

	array_view<int, 2> b(100, 100, bMatrix);

	array_view<int, 2> product(100, 100, productMatrix);


	parallel_for_each(
		product.extent,
		[=](index<2> idx) restrict(amp) {
		int row = idx[0];
		int col = idx[1];
		for (int inner = 0; inner <2; inner++) {
			product[idx] += a(row, inner)* b(inner, col);

		}
	});


	product.synchronize();

}

int main()
{
	MultiplyWithAMP();
	//while (!(getchar() == 'A'));
    return 0;
}