#include <iostream>
using namespace std;
// pointer to function to be passed to the logic
// so it can switch the logic instead of writing an if statement
template <typename T>
bool ascending(T a, T b) {
    return a > b;
}
template <typename T>
bool descending(T a, T b) {
    return a < b;
}
// bubble sort
// templated bubble sort
template <typename T>
void sort(T* arr, int n, bool(*comp)(T, T)) { // pass an array of any type, number of things, 
// it receives a pointer to a function for comparison that accepts two types and returns a boolean
// therefore this pointer to a function bool(*comp)(T, T), will gets created by a signature of a template
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(comp(arr[j], arr[j + 1])) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void display(T* a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

int main() {
    int a[] = {1, 5, 2, 3, 6, 7, 2};

    cout << "-------------------------------" << endl;
    sort(a, 7, ascending<int>); // ascending<int> is bool(*comp)(T, T)
    // the int specifies the template argument type for the comparison function
    // allowing the compiler to instantiate the correct version of the comparison
    // function for integers
    // to sort the array, we want a, 7 ascending and 
    // pass the <int> to the pointer to a function
    // pointer to a function to get created by an integer
    // because pointers are being passed and not the
    // signature of a function
    // in this way, the same sorting logic can be reused
    // for different types by changing the template argument
    display(a, 7);
    cout << "-------------------------------" << endl;
    sort(a, 7, descending<int>);
    display(a, 7);
    return 0;
}