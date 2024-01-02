#include <iostream>
#include <functional>
using namespace std;

// a function that draws a line
// ostream& line(char ch, int len) {
//     for (; len > 0; len--, cout << ch);
//     return cout;
// }

void inc(int& x, int& y) {
    ++x;
    ++y;
}

// template <typename T, size_t size>
// class Array {
//     T data[size]{};
//     T garbage{}; // when index goes off size, send a garbage value
// public:
//     Array() = default;
//     T& operator[](size_t index) {
//         // T& temp;
//         T* temp = garbage; // set to the address of garbage
//         // if (index >= size) {
//         if (index < size) {
//         //     temp = garbage;
//         // } else {
//             temp =& data[index]; // temp is address of data
//         }
//         // return temp;
//         return *temp;
//     }
//     // cannot create a reference
//     // it has to be initialized
//     // you can use a pointer because
//     // you cannot use a reference
// };

int main() {
    int a = 10, b = 10;
    auto addone = bind(inc, a, b);
    // auto addone = bind(inc, ref(a), b); // forced to be a reference
    // bind cannot bind anything by reference
    // so when you bind it, its gonna bind the values
    // it doesn't do by reference

    addone();
    cout << "a: " << a << ", b: " << b << endl;



    // auto hr = bind(line, '-', 70); 
    // // hr(horizontal rule) to be binding of the line function with dashes and 70 characters
    // // returns a function binding

    // hr() << endl; // call auto hr

    return 0;
}

// binding
// to bind a specific type of 
// function call to only one function call with no arguments