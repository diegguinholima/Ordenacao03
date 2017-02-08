#include "Sortings.hpp"
#include <utility>
#include <iostream>

using namespace std;

void Sortings::CountingSort(int vetor[], int n)
{
	int idx = 0;
	int k, min, max;
 
	min = max = vetor[0];
	for(int i = 1; i < n; i++) {
		min = (vetor[i] < min) ? vetor[i] : min;
		max = (vetor[i] > max) ? vetor[i] : max;
	}
 
	k = max - min + 1;
	/* creates k buckets */
	int *B = new int [k]; 
	for(int i = 0; i < k; i++) 
		B[i] = 0;

	for(int i = 0; i < n; i++)
	 B[vetor[i] - min]++;
	
	for(int i = min; i <= max; i++) 
		for(int j = 0; j < B[i - min]; j++) 
			vetor[idx++] = i;
 
	delete [] B;
}