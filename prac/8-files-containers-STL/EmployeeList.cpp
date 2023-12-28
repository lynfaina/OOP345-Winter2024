#include <list>
#include <iostream>
#include "Employee.h"
using namespace std;
int main() {
    list<Employee> E; // list of employees
    list<Employee>::iterator i; // created an iterator
    E.push_back({ "Larry Burns", 11234}); // push these 3 things
    E.push_back({ "Carl Carlson", 21234});
    E.push_back({ "Frank Grimes", 31234});
    for (i = E.begin(); i != E.end(); i++) // start from the beginning go to the end
        std::cout << *i << std::endl; // show them one by one
    cout << "-------------------" << endl;
    E.insert(--E.end(), {"Homer Simpson", 123}); // insert before the last one
    for (i = E.begin(); i != E.end(); i++)
        std::cout << *i << std::endl; // homer added here
    cout << "-------------------" << endl;
    E.erase(++E.begin()); // erase one after the beginning and its gonna remove that one
    cout << "after erase" << endl;
    for (i = E.begin(); i != E.end(); i++)
        std::cout << *i << std::endl;
    std::cout << std::endl;
    return 0;
}

// iterators inside a list to add something to the end
// right before the end or right after beginning
