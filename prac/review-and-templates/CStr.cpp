// Review lvalue, xvalue, prvalue
#include <iostream>
#include "CStr.h"
using namespace std;
//using namespace sdds; // use this if you wanna include the main function in the cpp file
namespace sdds {
    void CStr::cpy(char* des, const char* src) {
        while (*des++ = *src++); // strcpy (fix for gcc on linux)
        // copy characters from src to des until it encounters the null terminator
    }
    int CStr::len(const char* str) {
        const char* end = str;
        while (*end++); // iterate trhough the string until it encounters the null terminator
        return static_cast<int>(end - str) - 1; // length of the string
    }
    void CStr::allocNcpy(char*& des, const char* src) {
        des = new char[len(src) + 1]; // allocate memory for the string
        cpy(des, src);
    }
    char* CStr::read(istream& is) { // reading any size of Cstr dynamically and return it
        char* data = new char[ReadBufferSize];
        char* str = data;
        int noOfBuffers = 1;
        bool done;
        do {
            done = true;
            cin.getline(str, ReadBufferSize, '\n'); // if cin fails, it means entry was greater than 50
            // to read data from the input stream
            if (cin.fail()) {
                noOfBuffers++; // keep track of number of buffers to add
                char* temp = new char[(ReadBufferSize - 1) * noOfBuffers + 1]; // allocate bigger memory
                CStr::cpy(temp, data); // copy the already read test into temp
                delete[] data; // delete the old (too short) memory
                data = temp; // point to the newly large allocated memory
                str = data + (ReadBufferSize - 1) * (noOfBuffers - 1); // set the read pointer to continue reading
                cin.clear(); // clear cin to read again
                done = false; // we are not done yet
            }
        } while (!done); // go back and continue reading if not done
        allocNcpy(str, data);
        delete[] data;
        return str;
    }
}

// like virtuals, you don't bring the virtual to the function definition
// the same as static functions, static declared in header file while
// static defined in cpp

/* int main() {
    char* str1;
    char* str2;

    // Test copying and length calculation
    const char* source = "Hello, World!";
    CStr::allocNcpy(str1, source);
    cout << "Copied String: " << str1 << endl;
    cout << "Length: " << CStr::len(str1) << endl;
    delete[] str1;

    // Test dynamic reading
    cout << "Enter a string (more than 50 characters allowed): ";
    str2 = CStr::read(cin);
    cout << "Read String: " << str2 << endl;
    delete[] str2;

    return 0;
} */