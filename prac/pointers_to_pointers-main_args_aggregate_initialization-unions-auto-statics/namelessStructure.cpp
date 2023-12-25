#include <iostream>
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
    // to copy into another structure of the same type
    void foo {
        auto n = m_name;
        // n is a local variable
        // auto takes care of the type
        // and sets to m_name
        // auto is for things that don't have name or type
    }
}

int main () {
    return 0;
}