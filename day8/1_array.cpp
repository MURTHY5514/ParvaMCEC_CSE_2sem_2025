#include <iostream>
using namespace std;

int main()
{
    /**array
        data_type var_name[size];
        int arr[5];

        access:
        =======
        var_name[index]
        arr[4]
        n-1
    */

    int arr[5];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    cout << "1st: " << arr[0] << endl;
    cout << "2nd: " << arr[1] << endl;

    return 0;
}