#include "Sortings.hpp"
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Sortings::BucketSort(int vetor[], int size_file)
{
  
  int minValue = vetor[0];
  int maxValue = vetor[0];

  for (int i = 1; i < size_file; i++)
  {
    if (vetor[i] > maxValue)
      maxValue = vetor[i];
    if (vetor[i] < minValue)
      minValue = vetor[i];
  }

  int bucketLength = maxValue - minValue + 1;
  vector<int>* bucket = new vector<int>[bucketLength];

  for (int i = 0; i < bucketLength; i++)
  {
    bucket[i] = vector<int>();
  }

  for (int i = 0; i < size_file; i++)
  {
    bucket[vetor[i] - minValue].push_back(vetor[i]);
  }

  int k = 0;
  for (int i = 0; i < bucketLength; i++)
  {
    int bucketSize = bucket[i].size();

    if (bucketSize > 0)
    {
      for (int j = 0; j < bucketSize; j++)
      {
        vetor[k] = bucket[i][j];
        k++;
      }
    }
  }
}