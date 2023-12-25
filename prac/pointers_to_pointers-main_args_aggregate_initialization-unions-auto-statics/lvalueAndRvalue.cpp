#include <iostream>
using namespace std;

double tax = 0.7;
int value() {
    return 10;
}
double& taxValue() { // function returning a reference
// double& returning a reference of an entity that is
// scope is limited to the function
// its not going to die thats why taxValue is in the left side
// in the main function
    return tax;
}
int main() {
    int i;
    int* p;
    i = 6; // right value are usually temporary values / literal values
    p = &i;
    i = value();
    cout << taxValue() << endl;
    taxValue() = 0.13; // taxValue is in the left side
    cout << tax << endl;
    cout << taxValue() << endl;
}

// taxValue() is the temporary value therefore it is in the right side
// while double& is on the left side because it once initialized as 0.7
// and will not gonna change