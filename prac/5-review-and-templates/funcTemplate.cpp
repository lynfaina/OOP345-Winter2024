#include <iostream>
using namespace std;
// template <typename T> // function template // old version
template <class T> // new version
void swap(T* a, T* b) { // double value first, then character
	T c;
	c = *a;
	*a = *b;
	*b = c;
}

int main() {

	double a = 2.3;
	double b = 4.5;
	char d = 'A';
	char e = 'B';
	swap(&a, &b); // based on the type of the call that you have for template
	// generate the function at compile time
	// when swap() called, &a is a double pass then T* a is now a double
	std::cout << "Swapped values are " <<
		a << " and " << b << std::endl; // a now becomes 4.5 while b now becomes 2.3
	swap(&d, &e); // when swap() called, &d is a char pass then T* a is now a char 
	std::cout << "Swapped values are " <<
		d << " and " << e << std::endl; // d now becomes 'B' while e now becomes 'A'
}