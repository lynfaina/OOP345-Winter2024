#include <iostream>
using namespace std;

// Lambda Expressions
// something like functors
// auto
int main () {
    // Lambda called hello
    auto hello = []() { // Lambda function, added () because we don't wanna pass anything
    // returns nothing and receives nothing
        return "Hello there!";
    };
    // because its auto hello from the return statement knows
    // it is supposed to return a constant character pointer
    // you can pass this to a pointer to a function

    cout << hello() << endl;

    return 0;
}