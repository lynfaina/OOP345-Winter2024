#include <iostream>
using namespace std;

// this will not gonna change the address of p in the main
/*void gotoNextElement(int* ptr) { // address of ar[1] goes get copied right here
    ptr++; // add 1 to ptr and the address is now ar[2]
    // ptr is a copy of p
}*/

void yetGotoNextOneLevelHigher(int*** ptr) {
    (**ptr)++;
} 

// this will gonna change the address of p in the main
// when actually wants to change the value
/* void gotoNextElement(int** ptr) { // interger-pointer, pointer ptr
    // ptr points to an integer pointer
    (*ptr)++; // &p copied here and ptr increased by 1 as well as the address or &p
} */
// another function
void gotoNextElement(int** ptr) { // interger-pointer, pointer ptr
    // ptr points to an integer pointer
    yetGotoNextOneLevelHigher(&ptr); // passed address of ptr
    // same as above but with a different syntax / function call
} 
// either of the two above and below works
void gotoNextElement(int*& ref) { // integer-pointer, reference ref
    // ref becomes a new name for p
    ref++;
}

int main () {
    int ar[6] = {10,20,30,40,50,60};
    int* p = ar;
    cout << "*p: " << *p << endl; // 10 // p holds the address of ar[0]
    p++; // add one to the address and goes to the next element
    cout << "*p: " << *p << endl; // 20

    // not gonna change the address of p in the main
    /* gotoNextElement(p); // passed the address of the pointer by value
    cout << "*p: " << *p << endl; // 20 */

    // will gonna change the address of p in the main
    gotoNextElement(&p); // passed the address of the pointer 
    cout << "*p: " << *p << endl; // 30
    gotoNextElement(p); // passed the address of the pointer by reference
    cout << "*p: " << *p << endl; // 40 
    gotoNextElement(&p); // passed the address of the pointer 
    // yetGotoNextOneLevelHigher(&ptr); function
    cout << "*p: " << *p << endl; // 50
    gotoNextElement(&p); // passed the address of the pointer 
    // yetGotoNextOneLevelHigher(&ptr); function
    cout << "*p: " << *p << endl; // 60

    /* gotoNextElement(&p); // passed the address of the pointer 
    cout << "*p: " << *p << endl; // 50
    // either of these two will print the next element 50
    gotoNextElement(p); // passed the address of the pointer by reference
    cout << "*p: " << *p << endl; // 50 */

    
    return 0;
}