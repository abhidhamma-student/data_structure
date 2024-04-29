#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

int BinarySearch(int *arr, int size, int x)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2; // 정수 나누기 (버림)

        cout << "middle " << middle << endl;

        if (x < arr[middle])
        {
            right = middle - 1;
            cout << "right " << right << endl;
        }
        else if (x > arr[middle])
        {
            left = middle + 1;
            cout << "left " << left << endl;
        }
        else
        {
            cout << "Found " << middle << endl;
            return middle;
        }
    }

    cout << "Not found" << endl;
    return -1; // Not found
}

int RecurBinarySearch(int *arr, int left, int right, int x) // size 대신에 left, right
{
    if (left <= right)
    {
        int middle = (left + right) / 2;
        cout << "middle " << middle << endl;

        if (x < arr[middle])
        {
            right = middle - 1;
            cout << "right " << right << endl;
            return RecurBinarySearch(arr, left, right, x);
        }
        else if (x > arr[middle])
        {
            left = middle + 1;
            cout << "left " << left << endl;
            return RecurBinarySearch(arr, left, right, x);
        }
        else
        {
            cout << "Found " << middle << endl;
            return middle;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << BinarySearch(arr, size, -2) << endl;
    cout << RecurBinarySearch(arr, 0, size - 1, -2) << endl;

    return 0;
}
