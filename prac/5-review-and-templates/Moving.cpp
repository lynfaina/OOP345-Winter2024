// Review lvalue, xvalue, prvalue
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
        if (value) {
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
    // move constructor
    Name(Name&& N) {
        operator=(move(N)); // need to include move, if not,  Name& operator=(const Name& N) will be called
        // but we don't want that to happen
        // move(N) to extract an L value of an object
        // move means that this operator= function should be moved
        // when nameless object are created and they are about to die, they will move
        // move means && reference will be called instead of & reference
    }

    // copy assignment
    Name& operator=(const Name& N) {
        if (this != &N) { // checks for self copying
            tracer << "Assign " << m_value << " to " << N.m_value << nl; // 8th line output: Assign (NULLstr) to (A)
            // 12th line output: Assign (A) to temporary nameless object
            // 16th line output: Assign temporary nameless object(A) to (A)
            // m_value will be (NULLstr) then N.m_value
            delete[] m_value; // deletes the old value
            CStr::allocNcpy(m_value, N.m_value); // allocates and copy
        }
        return *this;
    }

    // move assignment
    Name& operator=(Name&& N) {
        // not const Name& N anymore because we want to move 
        // the value from the other one to this one
        // therefore we need to be able to change it
        // move reference and not constant
        if (this != &N) { // the same in copy assignment
            tracer << " Move assign " << N.m_value << " into " << m_value << " by assignment " << nl;
            delete[] m_value; // get rid of the current date // delete the value of the current one
            m_value = N.m_value; // point to the same thing // move the value of the other one
            // thats when a shallow copying causes trouble
            // because when the destructor of both are called,
            // the first one deletes, the second one crashes
            N.m_value = nullptr; // to prevent that // set the value to null
        }
        return *this; // the same in copy assignment
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

Name getName() {
    Name N; // creates a name
    cout << "Enter a name: "; // ask for a name
    cin >> N; // receives a name
    return N; // returns it by value
    // returning a temporary nameless object
}



/* int main() {
    cout << "Good afternoon OOP345!" << endl; // 1st line output
    // tracer.trace(true); // set the tracer to true
    // when tracer is set to false, it will print this

        Good afternoon OOP345!
        Name: Nicole
        Hello Nicole
        B: Nicole
        A: Jack
        A: Nicole
        B: Nicole

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
} */


int main() {
    tracer.trace(false);
    Name A = "Fred"; // calls the default constructor
    Name B = A; // calls the copy constructor
    Name C; // calls no argument constructor, this is nothing
    cout << "A: " << A << endl; // A: Fred
    cout << "B: " << B << endl; // B: Fred
    cout << "C: " << C << endl; // C: (Nullstr)
    tracer << " C = move(A);" << nl;
    C = move(A); // calls the move constructor
    cout << "A: " << A << endl; // A: (Nullstr)
    cout << "B: " << B << endl; // B: Fred
    cout << "C: " << C << endl; // C: Fred
    tracer << "Name D = getName();" << nl;
    Name D = getName(); // calls the Name getName() method // xvalue
    // getName() is returning an xvalue
    // and its returning a nameless value that is about to die
    // it doesn't move or copy because it's a temporary nameless object
    cout << "D: " << D << endl; // D: temporary nameless object
    tracer << "D = getName();" << nl;
    D = getName(); // Left side has already an existing D 
    // and its gonna assign the nameless value to right side
    // assigning the existing D object to a nameless object
    // calls the Name getName() method
    // calls the move assignment
    // the destructor of the nameless object will be called
    // but its nothing to delete because it sets to null
    cout << "D: " << D << endl; // D: temporary nameless object
    tracer << "Name E = move(B);" << nl;
    Name E = move(B); // calls the move constructor
    // calls the move assignment
    cout << "E: " << E << endl; // E: Fred
    cout << "B: " << B << endl; // B: (Nullstr)
    C = "prvalue"; // lvalue C, prvalue "prvalue" // pure right value
    B = Name("Xvalue"); // lvalue B, xvalue Name("Xvalue)
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
    cout << "Xval: " << (Name("Xvalue/glvalue") = "some value") << endl; // xvalue can be like this
    // it can be at left or right side but its still a temporary nameless object    
    // generalized left value = lvalue and xvalue
    // C and B are lvalue, handle for an object, occupies memory
    // rvalue = xvalue and prvalue
    // prvalue is the actual right value, no specific handle
    // literal values
    // "Fred" and "prvalue" are prvalue
    // xvalue is a temporary nameless object
    // Name("Xvalue) is an xvalue
    return 0;
}


// rule of three
// guarantees that your program run flawlessly with no problem
// rule of five
// guarantees that your program run flawlessly with no problem as fast as possible
// for efficiency




// when you return something to a function, copy constructor will be called
// to create that temporary nameless object
// if you pass something to an object to another object,
// then that temporary nameless object gets passed to the other object
// now that other object has a copy of the temporary nameless object (it receives a copy)
// then use the temporary nameless object to dynamically allocate memory, copying, etc.
// and throw away the temporary nameless object and the destructor will be called
// and all the temporary nameless objects will be destroyed and removed from memory
