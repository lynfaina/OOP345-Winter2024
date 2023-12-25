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

// Statics
// to create utility classes
// classes that carry functionalities but they don't have any properties
// belongs to the class not instances
constexpr int ReadBufferSize = 50;
class Cstr { // create a class Cstring 
public:
    Cstr() = delete;
    // all the action of cpy, len, allocNcpy, read
    // they could be static functions
    // therefore when we use them, we don't need to instantiate Cstr anymore
    static void cpy(char* des, const char* src) {
        while(*des++ = *src++); // strcpy (fix for gcc on linux)
        // copy characters from src to des until it encounters the null terminator
    }
    static int len(const char* str) {
        const char* end = str;
        while(*end++); // iterate trhough the string until it encounters the null terminator
        return static_cast<int>(end - str) - 1; // length of the string
    }
    static void allocNcpy(char*& des, const char* src) {
        des = new char[len(src) + 1]; // allocate memory for the string
        cpy(des, src);
    }
    static char* read(istream& is) { // reading any size of Cstr dynamically and return it
        char* data = new char[ReadBufferSize];
        char* str = data;
        int noOfBuffers = 1;
        bool done;
        do {
            done = true;
            cin.getline(str, ReadBufferSize, '\n'); // if cin fails, it means entry was greater than 50
            // to read data from the input stream
            if(cin.fail()) {
                noOfBuffers++; // keep track of number of buffers to add
                char* temp = new char[(ReadBufferSize - 1) * noOfBuffers + 1]; // allocate bigger memory
                Cstr::cpy(temp, data); // copy the already read test into temp
                delete[] data; // delete the old (too short) memory
                data = temp; // point to the newly large allocated memory
                str = data + (ReadBufferSize - 1) * (noOfBuffers - 1); // set the read pointer to continue reading
                cin.clear(); // clear cin to read again
                done = false; // we are not done yet
            }
        } while(!done); // go back and continue reading if not done
        allocNcpy(str, data);
        delete[] data;
        return str;
    }
};

int main() {
    tracer.trace(); // activate tracing
    // tracer.trace(false); // deactivate tracing
    // or don't initialize tracer
    int a, b = 10, c = 30;

    tracer << "adding b and c in a\n"; 
    a = b + c;
    tracer << "the value is " << a << "\n";

    // any place you include Cstr in the main code
    // you can call all the functions using the class name
    // Cstr::cpy() and such...

    return 0;
}