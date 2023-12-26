#include <iostream>
#include <cstdint>
using namespace std;
void add(int a, int b) {
    cout << a << "+" << b << "=" << (a+b) << endl;
}
void sub(int a, int b) {
    cout << a << "-" << b << "=" << (a-b) << endl;
}
void mul(int a, int b) {
    cout << a << "x" << b << "=" << (a*b) << endl;
}
void divid(int a, int b) {
    cout << a << "/" << b << "=" << (a/b) << endl;
}
auto main() -> int {
    cout << "Pointer to a function" << endl;
    void (*func[4])(int, int) = {add, sub, mul, divid};
    // created the function pointer, 4 of them, initialized to add, sub, mul, divid
    for(int i = 0; i < 4; i++) { // for loop to call the 4 functions
        func[i](10, 2);
    }

    return 0;
}