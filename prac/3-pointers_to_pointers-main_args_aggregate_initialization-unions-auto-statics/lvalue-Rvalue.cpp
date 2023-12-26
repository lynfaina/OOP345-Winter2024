#include <iostream>
using namespace std;

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
        cout << "destruction" << endl;
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
    cout << N << endl;
}

int main () {
    Name A = "Jack"; // constructor
    // cout << "Name Jack has created" << endl;
    Name B = A; // copy constructor
    // cout << "Name Jack has copied" << endl;
    Name C = Name("John"); // creating a copy of a nameless object
    // copy constructor was not called
    // John just created (constructor)
    // nameless objects are never copied
    // Name C = "John"; the same with this from Name A = "Jack" (lvalue)
    cout << "After Name Creations!" << endl;

    cout << A << endl; // displays Jack // A is a lvalue, Jack is an prvalue
    cout << B << endl; // displays copied Jack // B is a lvalue, Jack is an prvalue
    cout << C << endl; // displays John // C is a lvalue, John is an prvalue
    cout << Name("John") << endl; // displays John // xvalue
    // L value can stands on both sides
    // R value can only stand on the right side
    cout << Name("Nicole") << endl; // calls the R value because its a nameless object // xvalue
    // it doesn't have any reference attached to it
    // displays Nicole

    prnName(Name("Yonghoon")); // prnName(Name N = Name("Yonghoon")); // prnName is an lvalue, Yonghoon is xvalue
    // this will be the same as Name C = Name("John");
    // temporary nameless object gets created
    // being passed by value to prnName means the copy constructor
    // of N needs to be called to call to do this name
    // which will never be called because its already a namesless object

   
    return 0;
}