#include <iostream>
using namespace std;

int main() {
    int a = 17; // a = 0, b = 8, c = 450
    int b = 017; // a = 17, b = 8, c = 450
    int c = 0x17; // a = 17, b = 15, c = 450
    cout << a << " " << b << " " << c << endl; // a = 17, b = 15, c = 23
    return 0;
}


// c-string is a character array terminated by a null character