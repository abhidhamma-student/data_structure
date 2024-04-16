#include <iostream>
using namespace std;
#include "../shared/print.cpp"

int *insertionSort(int arr[], int size);

int main()
{
    cout << "Insertion Sort" << endl;
    int array[] = {5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, size);
    printf("\n");

    int *sortedArray = insertionSort(array, size);

    printf("\n");
    printf("Sorted array: ");
    printArray(array, size);
    printf("\n");

    return 0;
}

/*
삽입 정렬

자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 
자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 방식
(이미 정렬된 배열에 새로운 값을 삽입한다고 해서 삽입정렬)
*/
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

        printLoop(arr, size, i + 1); // 각 loop 확인
    }
    return arr;
}