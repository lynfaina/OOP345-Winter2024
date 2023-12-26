#include <iostream>
using namespace std;

void setToZero(int* val) { // integer pointer
    *val = 0;
}
void setToZero(int& val) { // reference
    val = 0;
}

int main () {
    int a = 10, b = 20;
    setToZero(&a); // pass by reference / address of a
    // sets the  value at the address of a to 0
    setToZero(b);
    // directly sets the value of b to 0

    cout << a << endl;
    cout << b << endl;

    return 0;
}


// pointer
// declared using * e.g. int* ptr;
// can be assigned as nullptr
// can be reassigned to point to diff variables
// dereference operator e.g. int value = *ptr
// can be declared without initialization
// can take pointers as parameters, allowing to modify the values indirectly
// used in dynamic memory allocation (new and delete)

// reference
// declared using & e.g. int& ref = someVal;
// must always be initialized and cannot be nullptr
// cannot be changed to refer to another variable
// aliases for existing variables
// can be access by using reference name e.g. int value = ref;
// must be initialized when declared, cannot be re-initialized
// can take references as parameters
// used for creating aliases, function parameters, and as return types for functions