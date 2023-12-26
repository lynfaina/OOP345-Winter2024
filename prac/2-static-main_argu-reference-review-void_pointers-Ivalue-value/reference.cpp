#include <iostream>
#include <cstring>
using namespace std;

class Name {
    char* m_data{};
    static void alloCopy(char*& data, const char* src) {
    // alloCopy to do dynamic allocation, it has nothing to do with the class Name
        delete[] data;
        data = new char[strlen(src) + 1];
        strcpy(data, src);
    }
public:
    Name(const char* name) {
        alloCopy(m_data, name);
    }
    void display() const {
        cout << m_data << endl;
    }
};

// to allocate series of integers
void allocate(int* nums, size_t size) {
// if int* nums becomes int*& nums, new variable is created
// nums become a new name for n which doesn't exist anymore
    nums = new int[size];
}

int main(int argc, char* argv[], char* env[]) {
    int* n{};
    allocate(n, 30); 
    // allocate(int* nums = n, size_t size = 30); how function called
    // n is passing the address by value
    // nums is a copy you have in main
    // when calling, this is n and nums at the same time
    // there are not two different variables
    for(int i = 0; i < 30; i++) {
        n[i] = i;
    }
    delete[] n;
    return 0;
}

// abstraction