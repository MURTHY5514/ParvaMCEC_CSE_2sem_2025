/**
 * Pointers:
 * =========
 * * pointer is variable that stores the address of another variable
 * ex:
 * ===
 *  //int variable(a).
 *  int a;
 *  a = 10;
 *
 *  & ---> ADDRESS OPEARTOR
 *  * ---> value operator/ dreference operator
 *
 *  int a = 10;
 *
 *  &a ---> address of a
 *
 *
 *  int *ptr = &a;
 *
 */

#include <iostream>
using namespace std;
int main()
{
    // varibale
    int a = 10;
    cout << "Address of a: " << &a << endl;

    int *ptr = &a;

    cout << "Ptr Address: " << &ptr << endl;

    cout << "Value of a using a: " << a << endl;
    cout << "Value of a using ptr: " << *ptr << endl;
    cout << "Value of a : " << *(&a) << endl;
    cout << "Value of a: " << *(*(&ptr)) << endl;
    cout << "Value of a : " << *(&(*ptr)) << endl;

    cout << "Ptr value: " << ptr << endl;
    cout << "Ptr value: " << &a << endl;
    cout << "Ptr value: " << *(&ptr) << endl;
    cout << "Ptr value: " << *(&ptr) << endl;
    cout << "Ptr value: " << &(*(*(&ptr))) << endl;

    return 0;
}