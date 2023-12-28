#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ofstream file("nums.bin", ios::binary); // created an ofstream of type file and called it nums.txt
    // nums.bin for binary file
    // create this as ios::binary // optional

    vector<double> d{ 10.1, 11.232, 12.23, 13.43, 14.5, 15.6, 16.7, 17.8 }; // created a double vector // more values
    for (auto& v : d) { // an iterator for the double vector
    //  file.write(address of a byte, how many bytes);
        file.write((const char*)(&v), sizeof(v)); // put those values right in a file
        // write into it with the write function
        // a write function receives a constant character pointer (const char*) and the number of bytes
        // so you are telling to the compiler go to this 
        // address byte by byte (address of a byte) 
        // up to these many things (how many bytes) write, dump it into the file

        // file.write((const char*)(&v), sizeof(v));
        // &v is the address of the double d
        // added const char* to cast into it because it receives a constant character pointer
        // sizeof(v) is the number of bytes

        // what happens is, to the sizeof(v), 
        //go to the address of the double and write in into the file
    } 
    return 0; 
}