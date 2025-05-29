#include <iostream>
using namespace std;
int main()
{
    int arr[3] = {10, 20, 30};
    cout << "print arr: " << arr << endl;
    cout << "Address of 1 ele: " << &arr[0] << endl;
    cout << "Value: " << *(arr + 1) << endl;

    int *ptr = arr;
    cout << "Value using pointer: " << *(ptr + 2) << endl;
    cout << "Before: " << arr[1] << endl;
    //*(ptr + 1) = *(ptr + 1) * 2;
    *(arr + 1) = *(arr + 1) * 2;
    cout << "After: " << arr[1] << endl;

    ptr = &arr[1];
    ptr++; // 1008  ptr = ptr+1;
    ptr = arr;
    cout << "value: " << *ptr << endl;
    cout << "First element: " << arr[0] << endl;
    cout << "First element: " << *(arr + 0) << endl;
    cout << "First element: " << *(ptr + 0) << endl;
    cout << "First element: " << ptr[0] << endl;
    cout << "First element: " << 0 [ptr] << endl;
    cout << "First element: " << 0 [arr] << endl;

    return 0;
}