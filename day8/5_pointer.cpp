/**
 * Dynamic memory:
 * ===============
 *
 * 1. static  (stack)
 * 2. dynamic (heap)
 *
 * dynamic memeory:
 * ================
 * 1. new - to allocate memory
 * 2. delete - release the allocated memory
 *
 */
#include <iostream>
using namespace std;
class Student
{
    string name;
    int roll_num;
};
int main()
{
    int a = 10;
    Student s1;

    // dynamic memory
    //  data_type *variable_name = new data_type

    int *a1 = new int;
    *a1 = 20;
    cout << "The value in a1: " << *a1 << endl;

    // delete
    //  delete pointer_name or variable_name
    delete a1;
    return 0;
}