#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    int weight;

public:
    Person()
    {
        cout << "Person Constructor" << endl;
    }
};

class Student : public Person
{
    int roll_num;

public:
    Student(string name, int age, int weight, int roll_num)
    {
        cout << "Student Constructor" << endl;
        this->name = name;
        this->age = age;
        this->weight = weight;
        this->roll_num = roll_num;
    }
    void display()
    {
        cout << "Student details: " << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
        cout << "Student Weight: " << weight << endl;
        cout << "Student Roll Number: " << roll_num << endl;
    }
};

int main()
{
    Student s1("pavan", 23, 50, 102);
    s1.display();
}