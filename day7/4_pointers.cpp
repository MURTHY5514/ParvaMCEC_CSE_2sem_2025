#include <iostream>
using namespace std;
int main()
{
    // varibale
    int a = 10;
    int *ptr = &a;
    *ptr = 101;
    // cout << "Value of a: " << a << endl;
    int b = 20;
    ptr = &b;
    *(&(*ptr)) = 30;
    cout << "Value of a: " << a << endl; //101
    cout << "Value of b: " << b << endl; //30

    return 0;
}