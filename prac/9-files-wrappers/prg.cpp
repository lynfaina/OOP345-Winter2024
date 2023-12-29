#include <iostream>
#include <fstream>
#include <vector>
#include "Employee-copy.h"
using namespace std;
bool showRec(int row, ifstream& F) {
    Employee E; // create an Employee
    F.clear(); // clear fstream
    F.seekg(0); // go to the beginning of the file
    // seekp the absolute location that you want to go to the file and read from there 
    int i;
    for(i = 0; F && i < row; i++) { // starts reading until you get to the row
        F >> E;
    }
    if (F) {
        cout << i << ": " << E << endl;
    }
    else {
        cout << "End of file was reached!" << endl;
    }
    return bool(F);
}
int main() {
    Employee E;
    int i = 0;
    ifstream file("employee.txt");
    while(file >> E) { // overloaded the insertion and extraction
    // extract the Employee from the file and keep going until the file ends
        cout << (++i) << ": " << E << endl;
    }
    cout << "==========================" << endl;
    showRec(10, file);
    showRec(100, file);
    return 0;
}

// sequential file where we actually create the Employee
// which we use the file

// seekp and seekg are two functions that we have in files 
// this is how the iostream is inherited