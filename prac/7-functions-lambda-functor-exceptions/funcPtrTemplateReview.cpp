#include <iostream>
using namespace std;
// template <typename T1, typename T2>
// auto findMax(T1 a, T2 b) -> T1 { // T1 is the return type
// // if we want to find the maximum between an integer and a double
// // i want the return type to be of type integer
// // the first argument to be the type that is returned
//     T1 arg2 = T1(b); // casted the second argument to type T1 and put it in arg2
//     return a > arg2 ? a : arg2; // if T1 a is greater than arg2(T2 b), return T1 a, else return arg2(b)
// }
// // this template dictates if i do a find max with two different types
// // the maximum of the values will always have the type of the left argument


// pointer to function to be passed to the logic
// so it can switch the logic instead of writing an if statement
template <typename T>
bool ascending(T a, T b) {
    return a > b; // greater than
}
template <typename T>
bool descending(T a, T b) {
    return a < b; // less than
}
// bubble sort
// templated bubble sort
template <typename T>
void sort(T* arr, int n, bool(*comp)(T, T)) { // pass an array of any type, number of things, 
// it receives a pointer to a function for comparison that accepts two types and returns a boolean
// therefore this pointer to a function bool(*comp)(T, T), will gets created by a signature of a template
// when you have a pointer to a function and you want to use templates for them,
// you simply pass the pointer to the function but instead of signture of the function,
// you put the templated type bool(*comp)(T, T) where T is the templated type
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
    // when I want to sort an array of integers, 7 integers,
    // and I want to be descending and specialized the function
    // with int to tell to the compiler I want the int version
    // of this function pass to it
    // because sort is an integer and this is gonna be an integer
    // its a match, its going to sort
    display(a, 7);
    return 0;
}