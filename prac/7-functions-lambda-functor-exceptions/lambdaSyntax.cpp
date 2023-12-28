// a callable object is a class that has operator function called overloaded in it
// Lambda expression by nature is a functor


/*
[capture_clause](parameter_list) -> return_type {
    // body of lambda
};

anonymous function created within a scope so you need
to tell to the compiler how does this thing deal with
the variables outside of the scope

capture_clause: Specifies which outside variables are available
    for the lambda.
parameter_list: The parameters just like in a regular function.
return_type: Optional. If omitted, its inferred from the
    return statements in the lambda.
    if you put a return type, you're dictating what the
    return type its gonna be
    e.g. if you make a return type of double and you return
    an integer, it will be casted to a double as return type
    but if you don't put the return type, automatically it
    will have the type of the return it is returning
    note: do not have multiple return statements in a function
          a function must have one point of entry and one point of exit
          especially in a Lambda expression, if you have two return types
          with two different types, it will be an error
body: The code to be executed when the lambda is invoked.

Let's break down the components:

1- Capture Clause: Determines how variables from the enclosing
    scope are captured for use inside the lambda.
    Capture Clause has nothing to do with the parameter list.
    Capture Clause has everything to do with the variables outside
    of the lambda.

    []: No variables are captured. Nothing is captured from the outer scope.
    [=]: Captures all used variables by value. It have access to all the values
         outside but it cannot change them back. If it accesses any of those
         values, the values come in by value, not reference. Read only access to
         values outside.
    [&]: Captures all used variables by reference. If you have a value outside
         inside your lambda, you change it, the value changes outside of the function.
         Read, write, access to values outside of the lambda.
    [x, &y]: Captures x by value and y by reference. x is accessed by value
             and y is accessed by reference.

2- Parameter List: Just like regular function parameters.

3- Return Type: It's optional. If omitted, its inferred 
    from the return statements in the lambda.

4- Body: Contains the code to be executed when
    the lambda is called.
*/

#include <iostream>
using namespace std;
int main() {
    // A lambda function to add two numbers
    // the same as cout << [](int a, int b) -> int { return a + b; }(10, 20) << endl;
    auto add = [](int a, int b) -> int { // using the handle add and put auto because
    // we don't know what is the type
    // auto add = [] is nothing
        return a + b;
    };

    std::cout << add(3, 4) << std::endl; // output: 7

    // the same as auto add = [](int a, int b) -> int { return a + b; };
    cout << [](int a, int b) -> int { return a + b; }(10, 20) << endl;
    // this has nothing to do with the function
    // int a, int b and return a + b which means this is the anonymous function
    // and calling it

    // if we don't put -> int, it would be okay because
    // the sum of a + b is an integer therefore it would have
    // been an integer

    // cout << [](double a, double b) -> double { return a * b; }(10, 20) << endl;
    // the whole idea of lambda is to create something anonymous,
    // anonymous action that you want to make

    return 0;
}