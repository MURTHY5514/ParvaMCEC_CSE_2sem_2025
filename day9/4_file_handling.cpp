#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
    int a, b;
    cout << "Enter two  numbers: " << endl;
    cin >> a >> b;
    int res = a + b;
    ofstream fout("4_file_handling.txt");
    fout << "The sum of " << a << " and " << b << " is: " << res;
    fout.close();

    ifstream fin("4_file_handling.txt");
    string line;
    // getline(fin,line);
    while (getline(fin, line))
    {
        cout << line << endl;
    }
    fin.close();
    cout << line << endl;
}