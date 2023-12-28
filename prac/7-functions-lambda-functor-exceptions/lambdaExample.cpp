#include <iostream>
using namespace std;
int main() {
    int a = 10;
    int i = 5;

    auto addI2A = [&](int i) { return a += i; }; // integer that accepts things with reference
    auto sub4 = [](int i) { return i - 4; };
    auto showA = [&]() { cout << "a: " << a << endl; }; // showA that accepts things with reference

    showA(); // shows the value of a // a = 10 // output: a: 10
    cout << addI2A(10) << endl; // add 10 to a // 10 is passed to i because it is a reference
    // a = 10 and i = 10
    // return 10 += 10 // output: 20
    showA(); // shows the value of a // a = 20 // output: a: 20
    cout << sub4(10) << endl; // subtract 10 to sub4 value // 10 is passed to i because it is a reference
    // i = 10
    // return 10 - 4 // output: 6

    [=](char ch) { // get the value of a and show it
    // [=] means it accesses the value of a without planning to change it
    // therefore, a remains the same (a = 20)
        for(int i = 0; i < a; i++) cout << ch; // output: ******************** // because a = 20
        cout << endl;
    }('*'); 
    showA(); // output: a = 20

    [&](char ch) { // by reference
    // adding to the value of i (i = 5)
        for(; i < 10; i++) cout << ch; // output: *****
        cout << endl;
    }('*');
    cout << "i: " << i << " a: " << a << endl; // output: i: 10 a: 20
    // because its reference, when we use i, the value of i was changed
    // as it went through, because now this is using i as an outsider
    // this one is shadowing the i

    auto refAnVal = [&i, a](char ch) { // i by reference but a not to be changed
        for(; i < a; i++) cout << ch; // output: ********** // a remains the same (a = 20)
        cout << endl;
    };
    refAnVal('*');
    cout << "i: " << i << " a: " << a << endl; // output: i: 20 a: 20
    // i is changed while a remains the same

    [a, &i](char ch) { // a not to changed while i by reference
        for(i = 0; i < a - 5; i++) cout << ch; // output: *************** // because i = 15 (a - 5)
        cout << endl;
    }('*');
    cout << "i: " << i << " a: " << a << endl; // output: i: 15 a: 20

    [&, a](char ch) { // everything by reference but a by value
        for(i = 0; i < a; i++) cout << ch; // output: ********************
        cout << endl;
    }('*');
    cout << "i: " << i << " a: " << a << endl; // output: i: 20 a: 20

    [=, &i](char ch) { // everything by value but i by reference
    // i value will be changed and a will remain the same
        for(i = 0; i < a; i++) cout << ch; // output: ***************
        cout << endl;
    }('*');
    cout << "i: "<< i << " a: " << a << endl; // output: i: 15 a: 20

    return 0;
}

// a function or a functor must always have a handle
// a lambda can be anonymous, you can pass it as an argument