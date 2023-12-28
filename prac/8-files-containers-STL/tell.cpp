#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ifstream file("nums.bin", ios::binary);
    double v;
    file.seekg(0, ios::end); // go to the end of the file
    std::streampos s = file.tellg(); 
    cout << s << endl; // how many characters are in the file
    cout << s / sizeof(double) << endl; // how many records are in the file
    // tellg() is returning the size of the record
    return 0;
}