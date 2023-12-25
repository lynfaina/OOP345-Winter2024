#include <iostream> // cin and cout
#include "Student.h" // for global scope
using namespace std;

int main() {
    cout << "Hello OOP345!" << endl;
    int mark = 60; // function scope
    int i;
    cout << MinPassGrade; // global scope accessible here
    // while const int MaxStdNoLength is not accessible here
    cout << ">";
    cin >> i;
    if (i < 0) {
        int i = 4; // block scope
        // accessible within the if statement only
        // it shadows the i outside
        // you cannot change the i outside the if statement
    } else {

    }
    return 0;
}