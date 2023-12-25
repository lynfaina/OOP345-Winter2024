#ifndef SDDS_INTARRAY
#define SDDS_INTARRAY
#include <iostream>
namespace sdds {
	// created class IntArray to replace the integer arrays 
	class IntArray {
		int* m_data; // pointer to an integer for dynamic array
		int m_size; // size
		void resize(int newsize); // function to resize
	public:
		IntArray(int size = 1); // default constructor
		IntArray(const IntArray& cp); // copy constructor
		IntArray& operator=(const IntArray& cp); // copy assignment constructor
		int size()const; // size
		int& operator[](int index); // overloaded for normal access
		const int& operator[](int index)const; // overloaded for constant access
		virtual ~IntArray(); // to destroy the array
		std::ostream& display(std::ostream& ostr = std::cout)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const IntArray& Ro);
}


#endif // !SDDS_INTARRAY
