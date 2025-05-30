#include <iostream>
#include <fstream>
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
    /**
     * ios::in --> read mode
     * ios::out ---> write mode
     * ios::app ---> append mode=
     * ios::end --> go for end of the file.
     * ios::binary --> binary mode
     */
    double a = 10;
    cout << "Size of a: " << sizeof(a) << endl;

    Student s1;

    // write mode
    ofstream fout("students.dat", ios::binary); // data file it stor binary data
    s1.input();
    /**
     * write() --> method to write a binary adta to file.
     * read() --> method to read binary adta from file.
     */
    fout.write((char *)&s1, sizeof(s1));
    fout.close();

    // read mode
    Student s2;
    ifstream fin("students.dat", ios::binary);
    fin.read((char *)&s2, sizeof(s2));
    s2.display();

    return 0;
}