#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ofstream file("nums.txt"); // created an ofstream of type file and called it nums.txt
    vector<double> d{ 10.123456, 11.2343545, 13.43434}; // created a double vector 
    for (auto& v : d) { // an iterator for the double vector
        file << v << " "; // put those values right in a file
    } 
    return 0; 
}