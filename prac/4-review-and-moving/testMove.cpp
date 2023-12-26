#include <iostream>
using namespace std;
//using namespace sdds;

constexpr char nl = '\n';
class Tracer {
        bool m_trace{}; // on and off the message
        Tracer() = default; // nobody can instantiate it
        // put the default constructor in a private section
        // nobody can instantiate it but the Tracer itself
    public:
        static Tracer& instantiate() {
            static Tracer T; // this is a member of the Tracer class,
            // it call its constructor
            // Tracer gets created 
            return T; // and then return it
            // the second time this function is hit, because its static
            // its not gonna get created again
            // e.g. if somebody calls Tracer::instantiate() twice
            // it will only create one object, its going to get
            // the reference of the first object
        } // instantiate a Tracer
        // make it a singleton
        // there can only be one Tracer
        // static function belons to class, not the object
        Tracer(const Tracer&) = delete; // copy constructor
        Tracer& operator=(const Tracer&) = delete; // assignment operator
        Tracer& trace(bool value = true) { // set by default to true
            m_trace = value;
            return *this;
        } // set by default to true
        const Tracer& operator<<(const char* message) const { // Prints the message only if tracing is enabled
            if(m_trace) cout << (message ? message : "(NULLstr)");
            return *this;
        }
        const Tracer& operator<<(int val) const{ // Prints the integer value only if tracing is enabled
            if(m_trace) cout << val;
            return *this;
        }
        const Tracer& operator<<(double val) const { // Prints the double value only if tracing is enabled
            if(m_trace) cout << val;
            return *this;
        }
        const Tracer& operator<<(char ch) const { // Prints the character only if tracing is enabled
            if(m_trace) cout << ch;
            return *this;
        }
    };

Tracer& tracer = Tracer::instantiate(); 

const int ReadBufferSize = 50;
class CStr{
    public:
        static void cpy(char* des, const char* src) {
            while(*des++ = *src++); // strcpy (fix for gcc on linux)
            // copy characters from src to des until it encounters the null terminator
        }
        static int len(const char* str) {
            const char* end = str;
            while(*end++); // iterate trhough the string until it encounters the null terminator
            return static_cast<int>(end - str) - 1; // length of the string
        }
        static void allocNcpy(char*& des, const char* src)  {
            des = new char[len(src) + 1]; // allocate memory for the string
            cpy(des, src);
        }
        static char* read(std::istream& is) { // reading any size of Cstr dynamically and return it
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
                    CStr::cpy(temp, data); // copy the already read test into temp
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

    // move constructor
    Name(Name&& N) {
        operator=(move(N)); // need to include move, if not,  Name& operator=(const Name& N) will be called
        // but we don't want that to happen
        // move(N) to extract an L value of an object
        // move means that this operator= function should be moved
        // when nameless object are created and they are about to die, they will move
        // move means && reference will be called instead of & reference
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
    tracer.trace();
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
    Name D = getName(); // calls the Name getName() method
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
