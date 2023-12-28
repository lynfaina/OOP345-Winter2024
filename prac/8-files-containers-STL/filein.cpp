#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main() {
    ifstream file("nums.txt"); // open the created nums.txt file from ostream
    double d;
    while (file >> d) { // one by one read from the file until it cannot read anymore
        cout << d << endl; 
    } 
    return 0; 
}