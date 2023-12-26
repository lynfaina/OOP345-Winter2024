#include <iostream>
using namespace std;

/* class Foo {
public:
    void func(int, int); // create the function here
}; */

// Functor
class Add {
    size_t m_noOfCalls{};
public:
    // operator overloading
    int operator()(int num1, int num2) { // operator() because we are overloading the function called operator
    // overload the function and pass int num1 and num2
        m_noOfCalls++;
        return num1 + num2;
    }
    operator size_t()const {
        return m_noOfCalls;
    }
    double operator()(double num1, double num2) { // operator() because we are overloading the function called operator
    // overload the function and pass int num1 and num2
        m_noOfCalls++;
        return num1 + num2;
    }
};

int main() {
    /* Foo func;
    func(10, 20); // trying to use that class thingy like a function */
    /* Foo F;
    F.func(10, 20); // to able to call the function */ 
    // but we want that F itself to be a function
    // we can do operator overloading to do that
    Add add; // create an instance of the class
    int a = 10, b = 20, c;
    cout << "Functor using operator overloading" << endl;
    cout << endl;
    c = add(a, b);
    cout << "a + b = " << c << " in integer" << endl;
    a = add(c, b);
    cout << "c + b = " << a << " in integer" << endl;

    // use the double overload directly
    double d = add(22.13, 10.11);
    cout << "Sum of two double num is " << d << endl;

    cout << endl;
    cout << size_t(add) << " times called!" << endl;
    return 0;
}

// Class
// mechanism that can pass the functionality around
// you put the function in the class
// put an action inside the class
// create an instance and pass the instance

// in here, the function has a state
// a function called with logic does not have a state, its series of code that gets executed
// in here, you can put variables over there and check and see how many times it gets called

// any class that overloads the function call operator is a functor
