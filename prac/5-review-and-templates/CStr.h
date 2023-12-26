// Review lvalue, xvalue, prvalue
#pragma
#ifndef SDDS_CSTR_H
#define SDDS_CSTR_H
#include <iostream>
namespace sdds {
    const int ReadBufferSize = 50;
    // constexpr int ReadBufferSize = 50;
    // buffer size means a chunks of memory that's gonna add everytime 
    // e.g. it creates 50, 50 bytes gets from the console if it passes
    // that makes it 100, makes it 150
    // and when everything is done, it resizes it exact and returns the value
    // when we use const it makes it read only which happens at runtime
    // compiler has no idea that this is const
    // we can use constexpr if we want to make it compile time
    // this happens at compile time, compiler can optimize the code
    // based on that value
    class CStr {
    public:
        static void cpy(char* des, const char* src);
        static int len(const char* str);
        static void allocNcpy(char*& des, const char* src);
        static char* read(std::istream& is);
    };
}
#endif // !SDDS_CSTR_H