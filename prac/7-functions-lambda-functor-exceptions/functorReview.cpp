#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;

class Add { // class called Add
public:
    int operator()(int a, int b) { // overload the call operator
        return a + b; // add function inside with operator function called overload in it
    }
};

class Line {
    char m_fill{'*'};
    ostream& m_ostr{std::cout};
public:
    Line(){};
    Line(char fill, ostream& ostr = std::cout) : m_fill{fill}, m_ostr{ostr} {};
    // pass an ostream reference to print the Line and initialized it to cout
    // but can change to whatever you want
    void operator()(uintptr_t len) {
        for(uintptr_t i = 0; i < len; m_ostr << m_fill; i++);
        m_ostr << endl;
    }
};

int main() {
    ofstream f("line.txt");
    Line divider('-'), fileDivider('=', f);
    // Line divider with dash and Line fileDivider with assignment that is
    // writing something in a file called line.txt
    Add addFunctor, heehaw; // instantiate Add
    int x = addFunctor(2, 3); // can use the object addFunctor as a function
    // function object
    divider(50); // gonna show the divider on the screen
    cout << x << endl;
    x = heehaw(5, 6);
    fileDivider(70); // show the fileDivider on the file line.txt
    cout << x << endl;
}

// Functors are classes with the function call opeartor overloaded in them
// good thing about creating functors is that you can actually give state to your function