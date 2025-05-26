#include <iostream>
using namespace std;

class Camera
{
    int resolution;

public:
    Camera(int res) : resolution(res)
    {
        cout << "Camera Constructor" << endl;
    }
    void display_camera()
    {
        cout << "Camera resolution: " << resolution << endl;
    }
};

class Phone
{
    double phone_number;

public:
    Phone(double p_num) : phone_number(p_num)
    {
        cout << "Phone Constructor" << endl;
    }
    void dis_phone()
    {
        cout << "Phone Number: " << phone_number << endl;
    }
};

class SmartPhone : public Phone, public Camera
{
    int network_speed;

public:
    SmartPhone(int res, double p_num, int network) : Phone(p_num), Camera(res), network_speed(network)
    {
        cout << "SmartPhone Constructor" << endl;
    }

    void dis_smart_phone()
    {
        cout << "Smart phone details: " << endl;
        display_camera();
        dis_phone();
        cout << "Network speed: " << network_speed << endl;
    }
};

int main()
{
    SmartPhone s1(108, 1111111111, 30);
    s1.dis_smart_phone();
    return 0;
}