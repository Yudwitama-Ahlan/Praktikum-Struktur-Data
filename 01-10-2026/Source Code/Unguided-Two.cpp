#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z)
{
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z)
{
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main()
{
    int a = 4, b = 6, c = 8;

    cout << "Sebelum ditukar : a = " << a << ", b = " << b << ", c = " << c << endl;
    tukarPointer(&a, &b, &c);
    cout << "Setelah Call by Pointer   : a = " << a << ", b = " << b << ", c = " << c << endl;

    a = 4;
    b = 6;
    c = 8;

    cout << "\nSebelum ditukar : a = " << a << ", b = " << b << ", c = " << c << endl;
    tukarReference(a, b, c);
    cout << "Setelah Call by Reference : a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}