#include <iostream>
using namespace std;

class Line { // Line functor
    char m_fill;
public:
    Line(char fill = '-') : m_fill(fill) { }; // default constructor
    // fill for it by default is dash ('-') 
    // and can set the fill to anything
    ostream& operator()(size_t len) {
        for (size_t i = 0; i < len; i++) cout << m_fill;
        return cout;
    }
    Line& operator=(char fill) {
        m_fill = fill;
        return *this;
    }
};

int main() {
    Line dash, star('*'); // instantiate dash and star objects
    // dash and star are Line objects
    dash(10) << endl;
    star(20) << endl;
    dash = '_'; // calls the copy assignment
    // dash set to underline ('_')
    dash(30) << endl;
    return 0;
}

// Functors are classes who overload the function call operator
// they can have constructor, destructor, dynamic memory as long as
// it makes sense for them to act like a function
