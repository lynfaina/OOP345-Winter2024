#include <iostream>
#include <cstdint>
using namespace std;
void sum(int a, int b) {
    cout << (a+b) << endl;
}
void prod(int a, int b) {
    cout << (a*b) << endl;
}
auto main() -> int {
    cout << "Pointer to a function" << endl;
    int x = 10;
    int y = 5;
    // pointer to a function
    // this pointer can hold the address of any function that accepts two integers and returns a pointer to void
    void (*funcptr)(int, int) = nullptr;
    // to create a pointer that hold the same address of the function
    // repeat the signature of the function which is void(int, int)
    // and name of the function as pointer
    // don't put variable names because we don't know what functions we are calling
    // void *funcptr(int, int) = nullptr; // if you did like this, its still a function prototype
    // this means that this function is returning a void pointer
    // to be a pointer to a function that returns void, do this void (*funcptr)(int, int) = nullptr;
    // to tell the compiler that * is not belong to the void, it belongs to the name of the function
    // void (*funcptr)(int, int) {}; // aggregate initialization setting it to nullptr

    funcptr = sum; // we use now the funcptr to call the sum function
    // to check that the funcptr and the sum function have the same address
    // they are both pointing to the same location in memory
    // everytime you compile and run it, the address are different
    // everytime you calling it, it goes somewhere else in memory
    // each one is using a piece of memory
    cout << uintptr_t(sum) << endl;
    cout << uintptr_t(funcptr) << endl;
    // (*funcptr)(10, 20); // C language call for a pointer to a function
    funcptr(10, 30); // C++ call for a pointer to a function
    // C++ already knows that funcptr is a pointer to a function

    funcptr = prod; 
    cout << uintptr_t(prod) << endl;
    cout << uintptr_t(funcptr) << endl;
    funcptr(10, 30); // call the prod function

    return 0;

}