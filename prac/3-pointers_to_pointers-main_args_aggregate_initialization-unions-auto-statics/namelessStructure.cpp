#include <iostream>
#include <cstring> // added test
using namespace std;

class Student {
    // namesless classes
    struct {
        string first;
        string last;
    } m_name;
    // to access
    // m_name.first
    // m_name.last
    // nameless structure
    // if you put typedef then m_name becomes the name 
    // of the structure which is not a nameless class
    /* struct {
        string first;
        string last;
    } */ // this is the type
    // m_name is the instance
public:
    Student(string first, string last):m_name{first, last} {};

    // to copy into another structure of the same type
    void foo(const char* name) { // const char* name added test
        auto n = m_name;
        // n is a local variable
        // auto takes care of the type
        // and sets to m_name
        // auto is for things that don't have name or type
    }

    // added test
    string getFirstName() const {
        return m_name.first;
    }

    string getLastName() const {
        return m_name.last;
    }
};

int main () {
    // added tests
    Student s("nicole", "garcia");
    s.foo("nicole");

    cout << s.getFirstName() << " " << s.getLastName() << endl;

    return 0;
}