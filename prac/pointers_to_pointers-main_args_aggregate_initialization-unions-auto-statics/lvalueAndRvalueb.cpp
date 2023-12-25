#include <iostream>
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
    return 0;
}