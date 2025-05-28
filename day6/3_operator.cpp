#include <iostream>
using namespace std;
/**
 * complex:
 * ========
 *  2+i3
 *  3+i2
 * ======
 *  5+i5
 *
 *  operator overloading:
 * ======================
 *  return_type operator  op (class_name &obj1)
 *
 *  Complex operator + (Complex &c2)
 */
class Complex
{
    int real;
    int img;

public:
    Complex()
    {
        this->real = 0;
        this->img = 0;
    }
    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void display()
    {
        cout << "The Result is: " << real << "+i" << img << endl;
    }
    Complex operator+(Complex &c2)
    {
        Complex temp;
        temp.real = real + c2.real;
        temp.img = img + c2.img;
        return temp;
    }
};

int main()
{
    Complex c1(4, 2);
    Complex c2(3, 2);
    c1.display();
    c2.display();
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}