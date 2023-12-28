#include <iostream>
#include "Stack.h"
#include "Employee.h"
using namespace std;
int main() {
    Stack<double> d;
    d.push(1.2).push(2.3).push(3.5); // last push is the top
    while (d) {
        cout << d.pop() << endl;
    }
    Stack<Employee> E;
    E.push({ "Larry Burns", 11234});
    E.push({ "Carl Carlson", 21234});
    E.push({ "Frank Grimes", 31234});
    E.push({ "Homer Simpson", 123}); // last push is the top
    while (E) { 
        cout << E.pop() << endl;
    }
    return 0;
}
