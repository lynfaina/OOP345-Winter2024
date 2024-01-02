#pragma once
#include <iostream>
#include <fstream>
class Employee {
    double salary{};
    int empno{};
<<<<<<< HEAD
    char* name{};
public:
    static void strcpy(char* dest, const char* src);
=======
    char* name{}; // the name is not inside the class anymore compared to the previous Employee-copy.h file
    //  char name[52]; // this will end up with the garbage
    // because its gonna save the empno, the salary, and the address of the name
    // at the moment the program is running in the memory
    // but for this, for reading and writing, we don't only enter an object file system
    // but also the name
    // and we'll save the object that is all the same size in 
    // a binary file with exact record size then and put the name sequential in a file
    // but as we're writing the name, we'll gonna ask the C, tell me where the file, 
    // tellp to tell where the information is being written
    // so its gonna tell that this name is being written as address 952
    // we'll take that 952 and save it 
public:
    static void strcpy(char* des, const char* src);
>>>>>>> 751b4161cf9f622e405957a10f73969fb6fda493
    static size_t strlen(const char* s);
    Employee(double sal = 0.0, int emp = 0, const char* nm = "");
    Employee(const Employee&);
    Employee(Employee&&);
    Employee& operator=(const Employee&);
    Employee& operator=(Employee&&);
    ~Employee();
    bool operator<(const Employee& rOper)const;
    std::ostream& print(std::ostream& os)const;
    bool write(std::ofstream& ofs, std::ofstream& nfs)const;
    bool read(std::ifstream& ifs, std::ifstream& nfs);
};
std::ostream& operator<<(std::ostream& os, const Employee& E);