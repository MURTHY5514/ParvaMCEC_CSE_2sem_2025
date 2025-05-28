#include <iostream>
using namespace std;

class Message
{
public:
    void sendMessage(string email, string message)
    {
        cout << "Email sent successfully: " << endl;
        cout << "Email: " << email << endl;
        cout << "Message: " << message << endl;
    }
    void sendMessage(long long ph, int otp)
    {
        cout << "OTP sent successfully: " << endl;
        cout << "Phone Number: " << ph << endl;
        cout << "OTP: " << otp << endl;
    }
};

int main()
{
    Message m1;
    m1.sendMessage("some@gmail.com", "Hello world");
    m1.sendMessage(9980976656, 123);
}