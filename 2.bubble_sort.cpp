#include <iostream>
using namespace std;
#include "shared/print.cpp"

int *bubbleSort(int arr[], int size);

int main()
{
    cout << "Bubble Sort" << endl;
    int array[] = {5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, size);
    printf("\n");

    int *sortedArray = bubbleSort(array, size);

    printf("\n");
    printf("Sorted array: ");
    printArray(array, size);
    printf("\n");

    return 0;
}

/*
버블정렬

사이즈만큼의 횟수를 돌면서 
바로 옆에 있는 값이 더 크면 바꾸는 방식
*/
int *bubbleSort(int arr[], int size)
{
    int i, j, minIndex;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }

        printLoop(arr, size, i + 1); // 각 loop 확인
    }
    return arr;
}