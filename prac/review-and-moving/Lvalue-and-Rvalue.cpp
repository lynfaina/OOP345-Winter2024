#include <iostream>
using namespace std;

// L values and R values
// L value is anything that is sitting at left side of an assignment
// which means it has handle that yoy can put stuff in it
// R value or temporary stuff with no handle
class Name {
private:
    char* m_value{}; // = nullptr; // could have had it here
    // holds dynamically 
    // adding {} to know that m_value is nullptr
    // so we can remove the :m_value(nullptr) in the constructor
public:
    // constructor
    // receives either null or the value set by the user
    Name(const char* value = nullptr) {
        if(value) {
            int size = 0;
            // strlen
            while(value[size++]); // size = strlen + 1
            m_value = new char[size--]; // allocate size then size = -1
            // strcpy backwards, first null termination copied, if not at the first, go back once and copy the value, repeat
            // strcpy
            for(m_value[size] = value[size]; size; m_value[size] = value[--size]);
        }
    }
    // copy constructor
    // copies the name dynamically
    Name(const Name& N) {
        if(N.m_value) {
            int size = 0;
            // strlen
            while(N.m_value[size++]); // size = strlen + 1
            m_value = new char[size--]; // allocate size then size = -1
            // strcpy backwards, first null termination copied, if not at the first, go back once and copy the value, repeat
            // strcpy
            for(m_value[size] = N.m_value[size]; size; m_value[size] = N.m_value[--size]);
        }
    }
    ostream& print(ostream& os) const {
        if(m_value) os << m_value;
        return os;
    }
    ~Name() {
        //cout << "destruction" << endl;
        delete[] m_value;
    }
};

// ostream overloading
ostream& operator<<(ostream& os, const Name& N) {
    os << "lvalue: "; // left value because its a const reference
    return N.print(os);
}

ostream& operator<<(ostream& os, Name&& N) {
    os << "rvalue: "; // passed an rvalue which has && and not const
    return N.print(os);
}

void prnName(Name N) { // receiving a name by value
    cout << N << endl; // L value
}

int main () {

    // R values
    Name("Ali");
    // when you call the constructor, it creates a temporary nameless object
    // of type name and immediately dies at that line of code
    // Constructors are not functions
    // Constructos and Destructors are by-product of an object getting
    // created and destroyed
    Name X("Ali"); // L value
    // an object called X and its Ali but if no X it means
    // it is a nameless object but still creating an object
    // of type name, the Constructor is gonna get called
    // X is the handle to hold the object


    Name A = "Jack"; // constructor // L value
    // cout << "Name Jack has created" << endl;
    Name B = A; // copy constructor // L value
    // cout << "Name Jack has copied" << endl;
    Name C = Name("John"); // creating a copy of a nameless object // L value
    // copy constructor was not called
    // John just created (constructor)
    // nameless objects are never copied
    // Name C = "John"; the same with this from Name A = "Jack" (lvalue)

    cout << "After Name Creations!" << endl;

    prnName(Name("Yonghoon")); // prnName(Name N = Name("Yonghoon")); 
    // This is an lvalue because it is being passed by value and N
    // in the prnName function is an lvalue
    // this will be the same as Name C = Name("John");
    // temporary nameless object gets created
    // being passed by value to prnName means the copy constructor
    // of N needs to be called to call to do this name
    // which will never be called because its already a nameless object

    cout << X << endl;
    cout << A << endl; // displays Jack
    cout << B << endl; // displays copied Jack
    cout << C << endl; // displays John

    cout << Name("Yonghoon") << endl; // but this is an rvalue because its a temporary nameless object
    // and it got destroyed at the end of the function call
    // L value can stands on both sides
    // R value can only stand on the right side
    cout << Name("Nicole") << endl; // calls the R value because its a nameless object
    // it doesn't have any reference attached to it
    // displays Nicole

    

   
    return 0;
}