#include <iostream>
using namespace std;

#include "../shared/print.cpp"
#include "../shared/insertion_sort.cpp"

/*
요약: 정렬이 되어있을때는 조기종료를 할 수 있어서 count를 더 효율적으로 할수 있다

SequentialSearch - 배열 arr에 x가 있으면 index 반환, 없으면 -1 반환
Count - 배열 arr에 x가 몇 번 나오는지 반환
SortedCount - 정렬된 배열에서 x가 몇 번 나오는지 반환

*/

int SequentialSearch(int* arr, int n, int x);
int Count(int* arr, int n, int x);
int SortedCount(int* arr, int n, int x);
int SortedCountHelper(int* arr, int n, int x, int start); // start 사용

int main()
{
    cout << "Sequencial Search(Linear Search)" << endl;
   // 정렬되지 않은 데이터를 가정

	int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2 , 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// 복잡한 알고리즘이나 자료구조를 개발할 때는 
	// 실수할 가능성이 적은 단순한 방법을 기준으로 삼아요.

    cout << "Count number" << endl;
	cout << "Count 9 = " << Count(arr, n, 9) << endl;
	cout << "Count 2 = " << Count(arr, n, 2) << endl;
	cout << "Count 8 = " << Count(arr, n, 8) << endl;
	cout << "Count 1 = " << Count(arr, n, 1) << endl;
	cout << endl;

    cout << "Find number index(-1 is not exist)" << endl;
	cout << "Search 2 = " << SequentialSearch(arr, n, 2) << endl;
	cout << "Search 5 = " << SequentialSearch(arr, n, 5) << endl;
	cout << "Search 9 = " << SequentialSearch(arr, n, 9) << endl;
	cout << endl;

	insertionSort(arr, n);

	printArray(arr, n);

	cout << "Sorted Count 9 = " << SortedCount(arr, n, 9) << endl;
	cout << "Sorted Count 2 = " << SortedCount(arr, n, 2) << endl;
	cout << "Sorted Count 8 = " << SortedCount(arr, n, 8) << endl;
	cout << "Sorted Count 1 = " << SortedCount(arr, n, 1) << endl;
	cout << endl;

    return 0;
}

int SequentialSearch(int* arr, int n, int x)
{
	int i;
	for (i = 0; i < n && arr[i] != x; i++);
	if(i == n) return -1;
	else return i;
}

int Count(int* arr, int n, int x)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == x)
		{
			count += 1;
		}
	}
	return count;
}

int SortedCount(int* arr, int n, int x)
{
	int i = SequentialSearch(arr, n, x);

	if (i >= 0)
		return SortedCountHelper(arr, n, x, i + 1) + 1;
	else
		return 0;
}

int SortedCountHelper(int* arr, int n, int x, int start) // start 사용
{
	int count = 0;
	for (int i = start; i < n; i++)
	{
		if(arr[i] == x)
			count++;
		else
			break; // 정렬이 된 배열이기 떄문에 조기종료할 수 있다
	}

	return count;
}