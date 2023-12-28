#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ifstream file("nums.bin", ios::binary);
    double d;
    while (file.read((char*)&d, sizeof(d))) { // start reading the file, go form the beginning to the end
        cout << d << endl;
    }
    cout << "*******************" << endl;
    file.clear();
    file.seekg(std::streampos(2 * sizeof(double))); // exact position
    file.read((char*)&d, sizeof(d));
    cout << d << endl;
    file.seekg(-2 * std::streamoff(sizeof(double)), ios::cur); // ios::cur, ios::beg, ios::end
    // need to be cast to be able to go back and forth
    // ios::cur should be the first one
    // ios::cur shows the direction from where
    // -2 * std::streamoff(sizeof(double)) if we go back and forth
    // from current location, go 2 backwards and read and print again
    file.read((char*)&d, sizeof(d));
    cout << d << endl;
    return 0;
}