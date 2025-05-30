#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    // demo for seekg and tellg
    ifstream fin("file.txt");

    fin.seekg(0, ios::end);
    int pos;
    pos = fin.tellg();
    cout << "Size of file: " << pos << " bytes" << endl;

    fin.seekg(48);
    string line;
    getline(fin, line);

    cout << line << endl;
    fin.close();
}