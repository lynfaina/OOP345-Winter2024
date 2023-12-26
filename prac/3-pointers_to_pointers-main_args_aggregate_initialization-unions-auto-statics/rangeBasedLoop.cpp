#include <iostream>
#include <cstdint> // if unsigned doesn't work, for uintptr_t
using namespace std;

// can't do this
// array size is only known in local valuable 
// if its a primitive array, you can do it only in the same scope
// you cannot pass an array somewhere else
// this is an error
// we cannot passed an array to a function and use a range based loop
/* void prnArray(int arr[]) {
    for(auto& e : arr) {

    }
} */

int main() {
    int a[]{10, 20, 30, 40, 50, 60}; // primitive array, doesn't know what is its size
    // collections are not primitive
    // range based loop / for loop in C++
    // other programming language has loop called foreach loop
    for(int& el : a) {
        // cout << unsigned(&el) << ": " << el << endl;
        cout << uintptr_t(&el) << ": " << el << endl; 
        // an integer type designed to hold pointer values
    }

    cout << "\n" << endl;

    // collections
    // array of things
    // if you don't know what is the type of element that is
    // inside the collection, you can use auto keyword
    for(auto& e : a) { 
    // element of the array automatically gets the type of the element of the array
    // and auto turns to the type of the element
    // then e becomes an integer
        // cout << unsigned(&el) << ": " << el << endl;
        cout << uintptr_t(&e) << ": " << e << endl; 
        // an integer type designed to hold pointer values
    }
    return 0;
}


// smart arrays
// compound collections / composite collections  which they know their size
// and can passed an array to a function and use a range based loop
// but in primitive array, you can't do that