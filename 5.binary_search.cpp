#include <iostream>
#include <cassert>
using namespace std;

#include "shared/print.cpp"
#include "shared/insertion_sort.cpp"
#include "shared/count.cpp"


// 이진탐색 - 정렬된 배열에서 찾는 경우 
// 반으로 나누는 전략으로 찾는 범위를 줄일 수 있다
int binarySearch(int* arr, int n, int x)
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		printBinarySearchLoop(arr, n, left, right);

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
		cout << "==================" << endl;
		// break; // 임시: 무한루프 방지
	}

	cout << "Not found" << endl;
	return -1; // Not found
}

int main()
{
	// 정렬된 배열 (임의의 배열 사용 가능, 여기서는 디버깅 편의를 위해 index와 같은 값)
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int arr[] = { 2, 4, 5, 5, 6, 8, 9, 10, 12, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);

	assert(n > 0);

	// 정렬이 안된 배열은 미리 정렬

	binarySearch(arr, n, 5);

	//for (int x = 0; x < n; x++)
	//	cout << x << " " << BinarySearch(arr, n, x) << endl;

	return 0;
}
