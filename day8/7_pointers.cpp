#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int roll_num;

public:
    void input()
    {
        cout << "Enter student name: " << endl;
        cin >> name;
        cout << "Enter student roll_num: " << endl;
        cin >> roll_num;
    }
    void display()
    {
        cout << "Student name: " << name << endl;
        cout << "Student roll_num: " << roll_num << endl;
    }
};
int main()
{
    // int arr[3];

    // Student students[3];

    // for (int i = 0; i < 3; i++)
    // {
    //     students[i].input();
    //     students[i].display();
    // }
    Student s1;
    s1.input();
    s1.display();

    return 0;
}