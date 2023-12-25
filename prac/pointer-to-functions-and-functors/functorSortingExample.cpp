#include <iostream>
using namespace std;
// order options
// an enumaration when its creates constant values that
// are starting from zero automatically
// enum class Order { // g++ -std=c++11 functorSortingExample.cpp -o a
enum Order {         
    ascending, descending
};


// enum Weekdays {
//     sun, mon, tue, wed, thu, fri, sat
//     // 0, 1, 2, 3, 4, 5, 6
//     sun=1, mon, tue, wed, thu, fri, sat
//     // 1, 2, 3, 4, 5, 6, 7
//     // if you don't mention anything, it starts from 0
//     // if you do mention something, it starts from that
//     sun=1, mon, tue, wed, thu, fri=10, sat
//     // 1, 2, 3, 4, 5, 10, 6
// };

// enum struct Boolean {
//     false, true // false = 0, true = 1
// };


// order comparison
class Compare { // functor
    Order order; // it has an Order
public:
    Compare(Order o) : order(o) {} // when creating Compare, pass the Order to it
    // so the comparison acts accordingly and initialized the order to the value
    bool operator()(int& a, int& b) const { // operator that is comparing the two values
        // return order == Order::ascending ? a > b : a < b; // g++ -std=c++11 functorSortingExample.cpp -o a
        return order == ascending ? a > b : a < b; // if ascending, return a > b
        // if descending, return a < b
    }
};

void sort(int* a, int n, const Compare& comp) { // pass a const Compare functor to it
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(comp(a[j], a[j + 1])) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void display(int* a, int n) {
    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
        cout << endl;
    }
}

int main() {
    int a[] = {1, 5, 2, 3, 6, 7, 2};
    int n = sizeof a / sizeof(int);

    // sort(a, n, Compare(Order::ascending)); // g++ -std=c++11 functorSortingExample.cpp -o a
    sort(a, n, Compare(ascending));
    display(a, n);

    // sort(a, n, Compare(Order::descending)); // g++ -std=c++11 functorSortingExample.cpp -o a
    sort(a, n, Compare(descending));
    display(a, n);
    return 0;
}