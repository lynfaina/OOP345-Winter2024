#include <iostream>
#include "CStr.h"
#include "Tracer.h"
using namespace std;
using namespace sdds;

class Name {
private:
    char* m_value{};
public:
    // default constructor
    Name(const char* value = nullptr) { 
        if(value) {
            CStr::allocNcpy(m_value, value); // allocates and copy
        }
        tracer << "Create " << m_value << nl; // tracer prints the message // 11th line output: Create (A) temporary nameless object
    }
    // copy constructor
    Name(const Name& N) { // copying the value of such
        tracer << "Copy " << N.m_value << nl << " using: "; // 7th line output: Copy (A) // 8th line output: using: 
        // N.m_value will be the value of m_value which allocNcpy during the instantiation (default constructor)
        operator=(N);  // calling the assignment operator
    }
    // copy assignment
    Name& operator=(const Name& N) {
        if(this != &N) { // checks for self copying
            tracer << "Assign " << m_value << " to " << N.m_value << nl; // 8th line output: Assign (NULLstr) to (A)
            // 12th line output: Assign (A) to temporary nameless object
            // 16th line output: Assign temporary nameless object(A) to (A)
            // m_value will be (NULLstr) then N.m_value
            delete[] m_value; // deletes the old value
            CStr::allocNcpy(m_value, N.m_value); // allocates and copy
        }
        return *this;
    }
    // destructor
    ~Name() {
        tracer << "Remove " << m_value << " from memory" << nl; // 12th line output // 18th line output // 19th line output
        // since its a temporary nameless object, then it will destroyed
        // 13th line output: Remove temporary nameless object from memory
        // 19th line output: Remove (A) from memory
        // 20th line output: Remove (NULLstr)(A) from memory
        delete[] m_value;
    }
    // standard print
    ostream& print(ostream& os = cout) const { // receives a reference of cout by default
        return os << (m_value ? m_value : "(Nullstr)"); // shows the value, if the value is exists
        // safe empty state status simply says that its null string
        // if there is nothing in here, it shows nullstr
        // if there is something, it shows the value
    }
    istream& read(istream& is = cin) {
        delete[] m_value; // deletes whatever value have
        m_value = CStr::read(is); // reads a dynamic string from the console, puts it in value
        return is; // returns the istream
    }
};

// standard overloading for insertion and extraction operators
ostream& operator<<(ostream& os, const Name& N) {
    return N.print(os);
}
istream& operator>>(istream& is, Name& N) {
    return N.read(is);
}



int main() {
    cout << "Good afternoon OOP345!" << endl; // 1st line output
    // tracer.trace(true); // set the tracer to true
    // when tracer is set to false, it will print this
    /*  
        Good afternoon OOP345!
        Name: Nicole
        Hello Nicole
        B: Nicole
        A: Jack
        A: Nicole
        B: Nicole 
    */
    tracer.trace(); // or you can remove true because it was set true as default 
    Name A; // create an object A // calls the default constructor // 2nd line output: Create (NULLstr)
    cout << "Name: "; // 3rd line output
    tracer << "cin >> A;" << nl; // 3rd line output: Name: cin >> A:
    cin >> A; // 4th line input
    cout << "Hello " << A << endl; // 5th line output: Hello (A)
    tracer << "Name B = A;" << nl; // 6th line output 
    // calls the const Tracer& Tracer::operator<<(const char* message) const method
    Name B = A; // calls the copy constructor
    cout << "B: " << B << endl; // 9th line output: B: (A)
    // B = A because B is a const object and it doesn't destroyed
    tracer << "A = \"Jack\";" << nl; // 10th line output
    A = "Jack"; // calls the default constructor because Jack is a temporary nameless object
    // because compiler always tries to cast and make things work
    cout << "A: " << A << endl; // 14th line output: A: temporary nameless object because (A) once assigned to the temporary nameless object
    tracer << "A = B;" << nl; // 15th line output
    A = B; // calls the copy assignment
    cout << "A: " << A << endl; // 17th line output: A: (A)
    cout << "B: " << B << endl; // 18th line output: B: (A)
    return 0;
}



// when you return something to a function, copy constructor will be called
// to create that temporary nameless object
// if you pass something to an object to another object,
// then that temporary nameless object gets passed to the other object
// now that other object has a copy of the temporary nameless object (it receives a copy)
// then use the temporary nameless object to dynamically allocate memory, copying, etc.
// and throw away the temporary nameless object and the destructor will be called
// and all the temporary nameless objects will be destroyed and removed from memory
