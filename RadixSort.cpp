#include "Sortings.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

 
int getMax(int vetor[], int n)
{
    int max = vetor[0];
    for (int i = 1; i < n; i++)
        if (vetor[i] > max)
            max = vetor[i];
    return max;
}

void countSort(int vetor[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(vetor[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(vetor[i] / exp) % 10] - 1] = vetor[i];
        count[(vetor[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        vetor[i] = output[i];
}
   
void Sortings::RadixSort(int vetor[], int n)
{
    int m = getMax(vetor, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(vetor, n, exp);
}