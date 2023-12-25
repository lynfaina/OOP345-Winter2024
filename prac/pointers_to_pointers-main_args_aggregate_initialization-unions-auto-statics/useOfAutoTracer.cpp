#include <iostream>
using namespace std;

// created a class to trace the code and show debugging information
// to activate and deactivate tracing
// nameless class, this class is tracer, does not have a name
class {
    bool m_trace{}; // trace is false by default
public:
    auto& trace(bool value = true) { // set by default to true
        m_trace = value;
        return *this;
        // used auto& to return *this
    }
    // overloaded operators
    auto& operator<<(const char* message) { // Prints the message only if tracing is enabled
        if(m_trace) cout << (message ? message : "(NULLstr)");
        return *this;
    }
    auto& operator<<(int val) { // Prints the integer value only if tracing is enabled
        if(m_trace) cout << val;
        return *this;
    }
    auto& operator<<(double val) { // Prints the double value only if tracing is enabled
        if(m_trace) cout << val;
        return *this;
    }
    auto& operator<<(char ch) { // Prints the character only if tracing is enabled
        if(m_trace) cout << ch;
        return *this;
    }
} tracer;

int main() {
    tracer.trace(); // activate tracing
    // tracer.trace(false); // deactivate tracing
    // or don't initialize tracer
    int a, b = 10, c = 30;

    tracer << "adding b and c in a\n"; 
    a = b + c;
    tracer << "the value is " << a << "\n";

    return 0;
}