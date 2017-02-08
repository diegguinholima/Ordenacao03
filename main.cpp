#include "Sortings.hpp"
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int size_file;
			
	cin >> size_file;

	int vetor[size_file];

	int var = atoi(argv[1]);

	for (int i = 0; i < size_file; i++)
	{
		int aux;
		cin >> aux;
		vetor[i] = aux;
	}

	int n = sizeof(vetor)/sizeof(vetor[0]);

	switch (var){
		case 1:
			Sortings::BucketSort(vetor, size_file);		
			break;
		
		case 2:
			Sortings::RadixSort(vetor, n);
			break;
		
		case 3:
			Sortings::CountingSort(vetor, n);
			break;
	}

	for (int i = 0; i < size_file; i++)
	{
		cout << vetor[i] << endl;;	
	}
	return 0;
}