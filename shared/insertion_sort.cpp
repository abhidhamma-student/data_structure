#include <iostream>
using namespace std;

int *insertionSort(int arr[], int size)
{
    int i, j, minIndex;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    return arr;
}