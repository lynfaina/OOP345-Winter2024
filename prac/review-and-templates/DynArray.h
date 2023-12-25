#ifndef SDDS_DYNARRAY
#define SDDS_DYNARRAY
#include <iostream>
#include <utility> 
namespace sdds {
	/* 
	 * Step 1 - change the type of the focus of the class to templated type
	 * Step 2 - add the signature of the template to all the Class names other than:
	 *			a. the name of the class coming right after the template
	 *			b. Constructor names
	 *			c. Destructor name
	 * Step 3 - add the template to every single scope, even if its a one liner
	 */

	// classes cannot create signature
	// created class DynArray to replace the integer arrays 
	template <typename T> // template signature // template is of type T
	class DynArray {
		T* m_data; // pointer to an integer for dynamic array // change int to template type T
		// an array of type T
		size_t m_size; // size // int to size_t to make sure we understand thats the size and we know that
		// size_t its a C++ thing for anything thats more than 0
		void resize(size_t newsize); // function to resize // int to size_t
	public:
		DynArray(size_t size = 1); // default constructor // int to size_t // DynArray here is a Constructor name so do not add the <T> signature
		DynArray(const DynArray<T>& cp); // copy constructor // DynArray here is a Constructor name so do not add the <T> signature
		// DynArray& is an argument thats being passed so add the <T> signature
		DynArray<T>& operator=(const DynArray<T>& cp); // copy assignment constructor // change two DynArray& here as well 
		DynArray(DynArray<T>&& cp); // move constructor
		DynArray<T>& operator=(DynArray<T>&& cp); // move assignment constructor
		size_t size()const; // size // int to size_t
		T& operator[](size_t index); // overloaded for normal access // int to type T // int to size_t
		const T& operator[](size_t index)const; // overloaded for constant access // int to type T // int to size_t
		virtual ~DynArray(); // to destroy the array // DynArray here is a Destructor name so do not add the <T> signature
		std::ostream& display(std::ostream& ostr = std::cout)const;
	};
	template <typename T> // Step 3
	std::ostream& operator<<(std::ostream& ostr, const DynArray<T>& Ro); // DynArray& is an argument thats being passed so add the <T> signature


	// default constructor
	template <typename T> // add the template
	DynArray<T>::DynArray(size_t size) { // DynArray:: add the signature like this DynArray<T>
	// ::DynArray is a Constructor name so don't add the signature
	// change int to size_t
		if (size == 0) size = 1; // size set to 1 if size if <= 0 // <= change to == because size_t cannot less than to 0
		m_data = new T[m_size = size]; // allocate memory to the size we want // int to type T because its the array that we want to create
		// and set the attribute to the size we had
	}

	// copy constructor
	template <typename T> // add the template
	DynArray<T>::DynArray(const DynArray<T>& cp) { // DynArray:: add the signature like this DynArray<T>
	// ::DynArray is a Constructor name so don't add the signature
	// DynArray& to DynArray<T>&, argument thats being passed 
		m_data = new T[m_size = cp.m_size]; // created a dynamic array // new int to new type T
		// to the size of what we are going to copy
		for (size_t i = 0; i < m_size; i++) { // int to size_t because we are comparing it with m_size to prevent warnings
			m_data[i] = cp.m_data[i];		// copy assignment
			// the array element (m_data) is of type T
			// we have an object of type T being assigned to another object of type T
			// when we have an object being assigned to another object of the same type
			// copy assignment will be called
			// copied every single individual one-by-one
			// from the one that we are copying to the current one
			// the size is set to the size of the other one
		}
	}
	// assignment operator
	template <typename T> // add the template 
	DynArray<T>& DynArray<T>::operator=(const DynArray<T>& cp) { // DynArray& return value will add the type T to DynArray<T>&
	// DynArray:: not a Constructor nor Destructor name, change it to DynArray<T>::
	// DynArray& to DynArray<T>&, argument thats being passed 
		if (this != &cp) { // check if its not self copy
			delete[] m_data; // delete the current data
			// the ff below are the same from the copy constructor
			m_data = new T[m_size = cp.m_size]; // new int to new T
			for (size_t i = 0; i < m_size; i++) { // int to size_t because we are comparing it with m_size to prevent warnings
				m_data[i] = cp.m_data[i];    // copy assignment of the template will be called not the class
				// m_data[i] is a type
				// cp.m_data[i] is a type
			}
		}
		return *this;
	}

	// move constructor
	template <typename T> // add the template
	DynArray<T>::DynArray(DynArray<T>&& cp) {
        operator=(std::move(cp)); // need to include move, if not,  Name& operator=(const Name& N) will be called
        // but we don't want that to happen
        // move(N) to extract an L value of an object
        // move means that this operator= function should be moved
        // when nameless object are created and they are about to die, they will move
        // move means && reference will be called instead of & reference
    }

	// move assignment
	template <typename T>
	DynArray<T>& DynArray<T>::operator=(DynArray<T>&& cp) {
    	if (this != &cp) {
        	// delete[] m_data;  // delete the current data // causing a warning
        	m_data = cp.m_data;
        	m_size = cp.m_size;
        	cp.m_data = nullptr;
        	cp.m_size = 0;
    	}
    	return *this;
	}

	// destructor
	template <typename T> // add the template 
	DynArray<T>::~DynArray() { // DynArray:: add the signature like this DynArray<T>
	// ::~DynArray is a Destructor name so don't add the signature
		delete[] m_data; // deletes the function
	}
	template <typename T> // add the template 
	size_t DynArray<T>::size() const { // returning the size of int array so int to size_t // DynArray:: to DynArray<T>::
		return m_size; // returns what is the size of the function
	}
	template <typename T> // add the template 
	T& DynArray<T>::operator[](size_t index) { // it returns an element so int& to T&
	// its a member of DynArray so DynArray:: to DynArray<T>::
	// int to size_t, it receives the index at size_t
		// if (index < 0) index = 0; // index set to 0 if index is < 0 // size_t should not be less than 0 so remove this line
		if (index >= m_size) {
			resize(index + 1); // resizes the memory to the size that it has
		}
		return m_data[index]; // returns the element at the index that they wanted
	}

	template <typename T>
	const T& DynArray<T>::operator[](size_t index) const {
    // Ensure that m_size is not zero before performing the modulus operation
    	if (m_size == 0 && index == 0) { // if m_data and m_size is empty
        // Handle the case where m_size is zero (you can choose an appropriate action)
        	std::cout << "nullptr" << std::endl;
    	} else { // if m_data and m_size is not empty
    	// Perform the modulus operation only if m_size is not zero
    		return m_data[index % m_size];
		}
	}

	// displays comma separated
	template <typename T> // add the template 
	std::ostream& DynArray<T>::display(std::ostream& ostr)const { // DynArray:: to DynArray<T>::
		ostr << operator[](0);      // T must be insertable into ostream using << operator
		// operator[](0) it means an element of the array which means an object of type T
		// object of type T involved in an operation <<
		// ostream << T insertion
		for (size_t i = 1; i < size(); i++) { // int to size_t because we are comparing it with m_size to prevent warnings
			ostr << "," << (*this)[i];
		}
		return ostr;
	}

	template <typename T> // add the template 
	void DynArray<T>::resize(size_t newsize) { // DynArray:: to DynArray<T>:: // int to size_t
		if (newsize == 0) newsize = 1;
		// change all temp to newArray
		T* newArray = new T[newsize]; 	// resizes the memory by creating a memory // it creates an int* temp so change it to T* temp and
		// create a new int array in it so new int to new T
		// creating a temporary dynamic array with the new size that we want
		// to resize it to
		// no arg constructor or default constructor
		for (size_t i = 0; i < m_size && i < newsize; i++) { // int to size_t
			newArray[i] = m_data[i]; // one-by-one copy everything
		}
		m_size = newsize; // set the size to the new size
		delete[] m_data; // delete the old thing 
		m_data = newArray; // set the data to the new one
	}
	// operator overloads prints everything comma separated
	// and that was the dynamic integer array that is created
	template <typename T> // add the template 
	std::ostream& operator<<(std::ostream& ostr, const DynArray<T>& Ro) { // DynArray& to DynArray<T>&
		return Ro.display(ostr);
	}
}


#endif // !SDDS_DYNARRAY
