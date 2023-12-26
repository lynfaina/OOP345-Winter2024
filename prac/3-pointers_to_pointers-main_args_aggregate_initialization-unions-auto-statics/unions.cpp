#include <iostream>
using namespace std;

// Union
// it does not create the variables in sequence
// member variables inside the Union overlaps
// all start in the same place in memory / overwrites
union Vars {
    double a;
    int b;
    char c[7];
};

int main() {
    Vars V;
    cout << sizeof(Vars) << endl; // 8 because double has the highest size
    cout << alignof(Vars) << endl; // 8 because double has the highest alignment
    cout << unsigned(&V.a) << endl; // the address of the first member which is double
    cout << unsigned(&V.b) << endl; // the address of the second member which is int which
                                    // which both of these are the same address   
    V.a = 123456.789; // set to double
    cout << V.a << endl; // double value printed
    V.b = 123456; // set to int
    cout << V.b << endl; // int value printed
    for(int i = 0; i < 7; i++) { // set the char to set of characters
        V.c[i] = 'A' + i; 
    }
    for(int i = 0; i < 7; i++) {
        cout << V.c[i]; // ABCDEFG
    }
    cout << endl;
    // different values for each member
    cout << V.a << endl; 
    cout << V.b << endl;

    // anything you write, overwrites the other one
    // when you need to look at a piece of memory with different types of filters,
    // you create a Union

    return 0;
}