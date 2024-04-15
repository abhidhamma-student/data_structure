#include <iostream>
using namespace std;

int Count(char *arr, int n, char x)
{
    int count = 0;
    for (int i = 0; i < n; i++) // start index 사용
    {
        if (arr[i] == x)
            count++;
    }

    return count;
}
