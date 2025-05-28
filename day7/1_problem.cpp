#include <iostream>
using namespace std;
class Shape
{
public:
    virtual void calculateArea()
    {
        cout << "Area not define for generic shape:" << endl;
    }
};
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    void calculateArea() override
    {
        double res = 3.14 * radius * radius;
        cout << "the area of the circle is :" << res << endl;
    }
};
class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void calculateArea() override
    {
        double res = length * width;
        cout<<"the area of the rectangle is :" << res << endl;
    }
};
class Triangle : public Shape
{
private:
    double base;
    double height;
    public :
    Triangle(double b, double h) : base(b), height(h) {}
    void calculateArea() override
    {
        double res =0.5* base * height;
        cout<< "the area of the Triangle is :" << res << endl;
    }
};
int main()
{
    Circle c1(2.3);
    c1.calculateArea();
    Rectangle r1(4.0, 5.8);
    r1.calculateArea();
    Triangle t1(3.0, 8.7);
    t1.calculateArea();
    return 0;
}
