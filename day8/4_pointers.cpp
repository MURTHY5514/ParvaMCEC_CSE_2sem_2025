/**
 * cout of even and odd numbers in an array
 * [1, 2, 3, 4, 5, 6, 7, 8]
 */

#include <iostream>
using namespace std;
int main()
{
    int arr[8] = {1, 2, 13, 5, 6, 17, 8};
    int *ptr = arr;
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < 7; i++)
    {
        if ((i[ptr] % 2) == 0)
        {
            evenCount++; // evenCout = evenCout+1;
        }
        else
        {
            oddCount++;
        }
    }
    cout << "Even Cout: " << evenCount << endl;
    cout << "Odd Cout: " << oddCount << endl;
}