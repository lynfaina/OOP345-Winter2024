#include <iostream>
using namespace std;

int main() {
    int a{5}; // another way to initialize instead of using the assignment operator
    int b{}; // initializing to its default value or null
    int c[40]{};
    double d[20]{1.1,2.2};

    cout << a << endl;
    cout << b << endl;

    // added tests
    cout << c[1] << endl; // 0
    cout << d[3] << endl; // 0

    return 0;
}

// initialization 


// setting