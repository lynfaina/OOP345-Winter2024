#include <iostream>
#include <fstream>
#include <vector>
#include "Employee-copy.h"
using namespace std;
bool showRec(size_t row, ifstream& F) { // to know which row, receive the file show the record from the file
// this showRec jumps to the place that we want and picks up the employee that we want
// and bring it back, no delimiter needed, no sequential search needed
    Employee E; // create an Employee
    F.clear();
    F.seekg(std::streampos((row - 1) * sizeof(Employee))); // seek to exactly row number that we have to the size of the Employee
    // e.g. if we want the 1st one, that 1-1 then 0 multiply the size of Employee
    // e.g. if we want the 10th one, that 10-1 then 9 multiply the size of Employee
    // and thats gonna be the address
    F.read((char*)&E, sizeof(Employee)); // read from the file // read will gonna fail if showRec is 22
    if (F)
        cout << row << ": " << E << endl;
    else
        cout << "Record out of bound!" << endl;
    return !F.fail();
}
int main() {
    Employee E;
    int i = 0;
    ifstream file("employee.bin", ios::binary);
    while (!file.read((char*)&E, sizeof(Employee)).fail()) {
        cout << ++i << ": " << E << endl;
    }
    cout << "=======================" << endl;
    showRec(12, file); // will show the 12th record
    showRec(22, file); // Record out of bound because records are just until 19

    return 0;
}


// binary files reading and writing becomes much faster but the file becomes bigger 