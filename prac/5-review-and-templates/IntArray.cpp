#include <iostream>
#include "IntArray.h"
using namespace std;
namespace sdds {
	// default constructor
	IntArray::IntArray(int size) {
		if (size <= 0) size = 1; // size set to 1 if size if <= 0
		m_data = new int[m_size = size]; // allocate memory to the size we want
		// and set the attribute to the size we had
	}
	// copy constructor
	IntArray::IntArray(const IntArray& cp) {
		m_data = new int[m_size = cp.m_size]; // created a dynamic array
		// to the size of what we are going to copy
		for (int i = 0; i < m_size; i++) {
			m_data[i] = cp.m_data[i];
			// copied every single individual one-by-one
			// from the one that we are copying to the current one
			// the size is set to the size of the other one
		}
	}
	// assignment operator
	IntArray& IntArray::operator=(const IntArray& cp) {
		if (this != &cp) { // check if its not self copy
			delete[] m_data; // delete the current data
			// the ff below are the same from the copy constructor
			m_data = new int[m_size = cp.m_size];
			for (int i = 0; i < m_size; i++) {
				m_data[i] = cp.m_data[i];
			}
		}
		return *this;
	}
	// destructor
	IntArray::~IntArray() {
		delete[] m_data; // deletes the function
	}
	int IntArray::size() const {
		return m_size; // returns what is the size of the function
	}
	int& IntArray::operator[](int index) {
		if (index < 0) index = 0; // index set to 0 if index is < 0
		if (index >= m_size) { 
			resize(index + 1); // resizes the memory to the size that it has
		}
		return m_data[index]; // returns the element at the index that they wanted
	}
	const int& IntArray::operator[](int index)const {
		if (index < 0) index = 0; // index set to 0 if index is < 0
		return m_data[index % m_size]; // does modulus to make sure that it cannot
		// get out of here
		// cannot change the content of the element 
	}

	// displays comma separated
	std::ostream& IntArray::display(std::ostream& ostr)const {
		ostr << operator[](0);
		for (int i = 1; i < size(); i++) {
			ostr << "," << (*this)[i];
		}
		return ostr;
	}

	void IntArray::resize(int newsize) {
		int* temp = new int[newsize]; 	// resizes the memory by creating a memory
		// creating a temporary dynamic array with the new size that we want
		// to resize it to
		for (int i = 0; i < m_size && i < newsize; i++) {
			temp[i] = m_data[i]; // one-by-one copy everything
		}
		m_size = newsize; // set the size to the new size
		delete[] m_data; // delete the old thing 
		m_data = temp; // set the data to the new one
	}
	// operator overloads prints everything comma separated
	// and that was the dynamic integer array that is created
	std::ostream& operator<<(std::ostream& ostr, const IntArray& Ro) {
		return Ro.display(ostr);
	}
}
