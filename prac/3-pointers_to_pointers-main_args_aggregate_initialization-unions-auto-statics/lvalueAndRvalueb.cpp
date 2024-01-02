#include <iostream>
#include <cmath>
using namespace std;

void display(int& a) {
    cout << "lvalue: " << a << endl;
}
void display(int&& a) { // right value with the &&
    cout << "rvalue: " << a << endl;
}

int main() {
    int i = 10;
    display(i); // left value 10
    display(123); // right value 123

    // added tests
    display(i = 20); // left value 20
    display(16789); // right value 16789
    display(i); // left value 20
    display((int)12.05); // right value 12
    display(i = (int)15.67); // left value 15
    display(static_cast<int>(std::ceil(15.67))); // rightvalue 16 // rounded up

    return 0;
}