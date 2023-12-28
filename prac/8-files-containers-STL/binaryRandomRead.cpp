#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ifstream file("nums.bin", ios::binary);
    double v;
    file.read((char*)&v, sizeof(v)); // read to the size of v
    cout << v << endl; // reads the first value
    // if its bin file, the size of each double is exactly 8 bytes
    // if its text file, e.g. 10.1 will ocupy 4 bytes, 11.232 will ocupy 6 bytes and so on
    // each one of them will have a separate number of bytes because its written as text
    // file.seekg(address from the beginning of the file)
    // it called seekg because ifstream and ofstream they are both multiple inherited into fstream
    // seekg means seek for getting
    // seekp means seek for putting
    file.seekg(sizeof(v) * 3); // seek for reading to size of multipy by 3
    file.read((char*)&v, sizeof(v)); // and read again
    cout << v << endl; // read the 4th value // skipped first 3 values or skipped 24 bytes
    return 0;
}