#include <iostream>
using namespace std;
#include "../shared/print.cpp"

int *selectionSort(int arr[], int size);

int main()
{
    cout << "Selection Sort" << endl;
    int array[] = {5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, size);
    printf("\n");

    int *sortedArray = selectionSort(array, size);

    printf("\n");
    printf("Sorted array: ");
    printArray(array, size);
    printf("\n");

    return 0;
}

/*
선택정렬

사이즈만큼 돌면서 가장 작은 값을 찾아서 맨 앞으로 보내는 방식
(한 자리씩 선택해서 정렬한다고 해서 선택정렬)
*/
int *selectionSort(int arr[], int size)
{
    int i, j, minIndex;

    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);

        printLoop(arr, size, i + 1); // 각 loop 확인
    }

    return arr;
}