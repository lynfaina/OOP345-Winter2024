#include <iostream>
#include <functional>
using namespace std;

int main() {
    long l = 210L;
    reference_wrapper<long> L = l; 
    // created a reference wrapper for a long so that long becomes the same thing as that L thing
    cout << L << endl;
    L += 10;
    cout << L << endl;
    return 0;
}