#include <iostream>
using namespace std;

void faa();
void foo();

int main() {
    cout << "OOP345" << endl; // 1st line output
    foo(); // calls foo function
    cout << "end of foo" << endl; // 3rd line output
    for (int i = 0; i < 10; i++) {
        // i = 0, 0 < 10, i = 1
        // i = 1, 1 < 10, i = 2
        // i = 2, 2 < 10, i = 3
        // i = 3, 3 < 10, i = 4
        // i = 4, 4 < 10, i = 5
        // i = 5, 5 < 10, i = 6
        // i = 6, 6 < 10, i = 7
        // i = 7, 7 < 10, i = 8
        // i = 8, 8 < 10, i = 9
        // i = 9, 9 < 10, i = 10
        // i = 10, 10 < 10, i stops
        faa();
    }
    cout << endl;
    return 0;
}

void faa() {
    static int s = 0;
    cout << s << " ";  // 4th line output
    // prints 0 1 2 3 4 5 6 7 8 9
    // s = 0
    // s = 1
    // s = 2
    // s = 3
    // s = 4
    // s = 5
    // s = 6
    // s = 7
    // s = 8
    // s = 9
    s++;
    // s = 1
    // s = 2
    // s = 3
    // s = 4
    // s = 5
    // s = 6
    // s = 7
    // s = 8
    // s = 9
    // s = 10
}
// static
// the variable doesn't die
// the value never wiped out until the program ends
// global lifetime but limited scope

void foo()  {
    int a = 10;
    while (a--) {
        cout << a << " "; // 2nd line output
        // prints 9 8 7 6 5 4 3 2 1 0
    }
    cout << endl;
}