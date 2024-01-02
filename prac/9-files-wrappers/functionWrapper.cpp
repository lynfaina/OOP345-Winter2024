#include <iostream>
#include <functional>
using namespace std;

long mul(int x, int y) { // function
    return long(x) * y;
}

class Multiply { // functor
public:
    long operator()(int x, int y) {
        return long(x) + y;
    }
};


int main() {
    function<long(int, int)> a = mul; // wrapper for function
    // where long(int, int) is a signature
    // a is the name
    // a is set to mul which is the long mul() function
    function<long(int, int)> fa = Multiply(); // wrapper for functor
    // where long(int, int) is a signature
    // fa is the name
    // fa is set to Multiply() which is the class Multipy functor
        // () in Multiply means an instance of the class
    function<long(int, int)> la = [](int x, int y) { return long (x) * y; }; // wrapper for lambda
    // where long(int, int) is a signature
    // la is the name
    // la is set to [](int x, int y) { return long (x) * y; }; which is the lambda expression

    // auto abc = [](int x, int y) { return long (x) * y; };

    cout << a(5, 10) << endl;
    cout << fa(20, 10) << endl;
    cout << la(3, 10) << endl;
    // its like a variable that is holding a function in it
    // if you have function wrapper argument, 
    // you can pass any function with that signature with it to
    // and then use it in

    // instead of having five different signatures or five different syntaxes,
    // you can just have one function wrapper for all of them
    // with one function wrapper, you can pass a functor, pointer, lambda, you can pass everything
    // as long as the function wrapper matches the signature

    return 0;
}
    