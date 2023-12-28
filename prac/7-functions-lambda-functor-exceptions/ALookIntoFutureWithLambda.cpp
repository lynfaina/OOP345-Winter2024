#include <iostream>
#include <vector> // if we want to use an array
#include <algorithm>
using namespace std;
int main() {
    vector<int> v = { 3, 1, 4, 1, 5, 9, 2, 6 }; // vector of integers // an array of integers
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; }); // sort is an algorithm
    // v.begin() means from the beginning of v, go right to the end of v (v.end())
    // and pass the logic for sorting to it in the lambda
    for(int n : v) { // for int n in v 
        cout << n << " ";
    }
    cout << endl;
    return 0;
}

// standard template library for sorting
// sort() is an algorithm
// vector is in vector
// v.begin() beginning of the vector, v.end() end of the vector
// [](int a, int b) { return a > b; } the function to sort with it