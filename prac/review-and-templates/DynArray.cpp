#include <iostream>
#include <utility>  // for std::move
#include "DynArray.h"
using namespace std;
using namespace sdds;
struct Container {
	int m_data;
	//Container(int value = 10) { // it works cuz now it has a default constructor
	//// Container(int value) { // no appropriate default constructor available
	//// to call DynArray<T>::DynArray(size_t size) 
	//// because we want to create an array of containers and it cannot set it to anything (m_data = new T[m_size = size];)
	//	m_data = value;
	//}
	Container& operator=(int value) {
		m_data = value;
		return *this;
	}
};
ostream& operator<<(ostream& ostr, const Container C) {
	return ostr << C.m_data;
}
int main() {
	// instantiate DynArray D
	// if you want to instantiate as a template
	// you have to carry the signature with it
	// templated classes carry the signature of what
	// type that they need to create
	// include <double> instead
	// classes don't carry signture to instantiate a class template,
	// you have to mention which one you are doing
	// same as to resolve a function template call by adding signature
	DynArray<Container> C(4);
	int i;
	for (i = 0; i < C.size(); i++) {
		C[i] = i + 10;
	}
	cout << C << endl;

	// to call the move assignment operator
	DynArray<Container> B = std::move(C); // moving the contents of C to B
	cout << "C after move = " << C << endl; // C is empty
	cout << "B after move = " << B << endl; // B has the contents of C
	// free up the memory before the program ends
	C.~DynArray();
	B.~DynArray();
	return 0;
}