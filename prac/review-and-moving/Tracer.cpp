#include <iostream>
#include "Tracer.h"
using namespace std;
//using namespace sdds;
namespace sdds {
    Tracer& tracer = Tracer::instantiate(); // file scope
    // make to a variable so everybody can use it
    // it creates a static one, returns its reference so this Tracer becomes
    // a new name for T which is a variable that is just created once
    Tracer& Tracer::instantiate() { // create only one object
        static Tracer T; // this is a member of the Tracer class,
        // it call its constructor
        // Tracer gets created 
        return T; // and then return it
        // the second time this function is hit, because its static
        // its not gonna get created again
        // e.g. if somebody calls Tracer::instantiate() twice
        // it will only create one object, its going to get
        // the reference of the first object
    }
    Tracer& Tracer::trace(bool value) { // set by default to true
        m_trace = value;
        return *this;
    }
    // overloaded operators
    const Tracer& Tracer::operator<<(const char* message) const { // Prints the message only if tracing is enabled
        if(m_trace) cout << (message ? message : "(NULLstr)");
        return *this;
    }
    const Tracer& Tracer::operator<<(int val) const { // Prints the integer value only if tracing is enabled
        if(m_trace) cout << val;
        return *this;
    }
    const Tracer& Tracer::operator<<(double val) const { // Prints the double value only if tracing is enabled
        if(m_trace) cout << val;
        return *this;
    }
    const Tracer& Tracer::operator<<(char ch) const { // Prints the character only if tracing is enabled
        if(m_trace) cout << ch;
        return *this;
    }
}

/* int main() {
    tracer.trace(); // activate tracing

    int a, b = 10, c = 30;

    tracer << "adding b and c in a\n"; 
    a = b + c;
    tracer << "the value is " << a << "\n";

    return 0;
} 
 */