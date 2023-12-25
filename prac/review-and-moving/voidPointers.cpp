#include <iostream>
using namespace std;

// void pointers
// the address of the void pointer relates to no type
// target of the void pointer doesn't have a meaning
// if you're using void pointer, you need to use casting
// any type o address is a void pointer
void copyMem(void* des, const void* src, size_t size) {
    // templated cast / static_cast
    // used for conversions that are known to be safe at compile-time
    // type safety
    // to state your intention to change between two relative types
    // to tell the compiler if what type of cast you want
    char* cdes = static_cast<char*>(des);
    const char* csrc = static_cast<const char*>(src);
    for (size_t i = 0; i < size; i++) {
        cdes[i] = csrc[i];
        // ((char*)des)[i] = ((const char*)src)[i];
    }
}

int main() {
    double a = 1234.56789;
    double b;
    copyMem(&b, &a, sizeof(double));
    cout << b << endl;
    return 0;
}


// dynamic_cast
// used for safe downcasting in polymorphic class hierarchies
// (classes with virtual functions)
/*
class Base {
    virtual void foo() {}
};

class Derived : public Base {
    // ...
};

Base* basePtr = new Derived;
Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

if (derivedPtr != nullptr) {
    // Successfully casted to Derived
}

*/


// reinterpret_cast
// performs low-level, unsafe type conversions between unrelated types
/*
int intValue = 42;
char* charPtr = reinterpret_cast<char*>(&intValue);

*/


// const_cast
// used to add or remove the 'const' qualifier from a variable
/*
const int constValue = 42;
int* nonConstPtr = const_cast<int*>(&constValue);

*/