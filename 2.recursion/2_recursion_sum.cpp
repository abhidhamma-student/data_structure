#include <iostream>
#include <cassert>
#include <algorithm> // swap

using namespace std;

int Sum(int* arr, int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

/*
진행순서

RecurSum(arr, 3) = RecurSum(arr, 2) + arr[2]
RecurSum(arr, 2) = RecurSum(arr, 1) + arr[1]
RecurSum(arr, 1) = RecurSum(arr, 0) + arr[0]
RecurSum(arr, 0) = 0 => 여기서 리턴되서 위로 올라감 
*/
int RecurSum(int* arr, int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else
	{
		return RecurSum(arr, n - 1) + arr[n - 1];
	}
}

int main()
{
	// Sum vs RecurSum
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << Sum(arr, n) << endl;
	cout << RecurSum(arr, n) << endl;

	return 0;
}