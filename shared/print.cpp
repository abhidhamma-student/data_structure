#include <iostream>
#include <iomanip>      // std::setw
using namespace std;

// array 출력
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 각 loop 확인
void printLoop(int arr[], int size, int loopSequence)
{
    printf("loop%d: ", loopSequence);
    printArray(arr, size);
}

void printBinarySearchLoop(int* arr, int n, int left, int right)
{
	cout << "[" << left << "," << right << "]" << endl;

	cout << "Indices: ";
	for (int i = left; i <= right; i++)
		cout << setw(2) << i << " ";
	cout << endl;

	cout << "Values : " << setw(2);
	for (int i = left; i <= right; i++)
		cout << setw(2) << arr[i] << " ";
	cout << endl;
}