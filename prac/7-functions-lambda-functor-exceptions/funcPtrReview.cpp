#include <iostream>
using namespace std;
void add(int a, int b) { // function add that receives an integer a and b
    cout << a << "+" << b << "=" << (a+b) << endl;
}
int main() {

    void (*funcPtr)(int, int) = add; // prototype for function add
    // *funcPtr becomes an address for the function add
    // = add to set it to the name of the function therefore the address
    // of the function will go to funcPtr
    (*funcPtr)(10, 2); // C // call the funcPtr using the pointer
    funcPtr(10, 2); // C++
    // hence we can pass the logic from one place to another
    // purpose:
    // if you want the logic to be passed as data
    // and you want to have different logics passed to your program
    return 0;
}

// pointer to function review
// functions like every package of data, they sit in memory
// they have an address and you can hold that address in some place
// write the prototype of the function, and the you put the name of the prototype
// inside the parenthesis and put an asterisk beside it, that makes name of that prototype
// a pointer to a function that can hold the address e.g. void (*funcPtr)(int, int) = add;


// exceptions are exceptional things that are not supposed to happen
// in usual circumstances and that's not a user interface, in user
// interface, deep always happen, its not an exception