#include <iostream>
using namespace std;

int main()
{
    double arr[5];
    cout << "Enter the values of an array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the " << i + 1 << " Element: " << endl;
        cin >> i[arr];
    }

    cout << "Array Elements: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " Element is: " << *(arr + i) << endl;
    }

    return 0;
}