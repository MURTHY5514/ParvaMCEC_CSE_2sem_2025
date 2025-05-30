#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    // creating object for writing file
    ofstream fout;

    // opeing fiel in write mode
    fout.open("1_file_handling.txt"); // it will open the file in write mode. if file is not present in the "cwd" it will craete a new file with specified name.

    // insert some data.
    fout << "Hello world 1234\n";

    // close the file.
    fout.close();
    cout << "File is closed" << endl;
}