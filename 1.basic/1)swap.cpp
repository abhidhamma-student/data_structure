#include <iostream>
using namespace std;

void SwapPtr(int* i, int* j)
{
    int temp = * i;
    *i = *j;
    *j = temp;
}

void SwapRef(int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}

typedef struct {
    int a;
    int b;
} Pair;

Pair SwapValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    Pair result = {x, y};
    return result;
}



int main()
{
    int a = 10;
    int b = 20;

    SwapPtr(&a, &b);
    cout << "SwapPtr: " << a << " " << b << endl;

    SwapRef(a, b);
    cout << "SwapRef: " << a << " " << b << endl;

    Pair swapped = SwapValue(a, b);
    cout << "SwapValue: " << swapped.a << " " << swapped.b << endl;

    return 0;
}