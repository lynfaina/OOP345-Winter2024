#include <iostream>
#include <fstream>
#include <iomanip>
#include "DEmployee.h"
using namespace std;
void Employee::strcpy(char* des, const char* src) {
    while (src && des && *src) *des++ = *src++;
    if(des)*des = 0;
}
size_t Employee::strlen(const char* s) {
    size_t i = 0;
    while (s && s[i])i++;
    return i;
}
Employee::Employee(double sal, int emp, const char* nm) {
    salary = sal;
    empno = emp;
    name = new char[strlen(nm) + 1];
    strcpy(name, nm);
}
Employee::Employee(const Employee& E) {
    operator=(E);
}
Employee::Employee(Employee&& E) {
    operator=(move(E));
}
Employee& Employee::operator=(const Employee& E) {
    if (this != &E) {
        delete[] name;
        name = new char[strlen(E.name) + 1];
        strcpy(name, E.name);
        salary = E.salary;
        empno = E.empno;
    }
    return *this;
}
Employee& Employee::operator=(Employee&& E) {
    if (this != &E) {
        delete[] name;
        name = E.name;
        E.name = nullptr;
        salary = E.salary;
        empno = E.empno;
    }
<<<<<<< HEAD
    return *this; 
=======
    return *this;
>>>>>>> 751b4161cf9f622e405957a10f73969fb6fda493
}
Employee::~Employee() {
    delete[] name;
}
bool Employee::operator<(const Employee& rOper) const {
<<<<<<< HEAD
    size_t = 0;
    while (name && rOper.name && name[i] && rOper.name[i] && name[i] == rOper.name)
    return name && rOper.name && name [i] < rOper.name[i];
=======
    size_t i = 0;
    while (name && rOper.name && name[i] && rOper.name[i] && name[i] == rOper.name[i]);
    return name && rOper.name && name[i] < rOper.name[i];
>>>>>>> 751b4161cf9f622e405957a10f73969fb6fda493
}
ostream& Employee::print(ostream& os)const {
    return os << name << "," << empno << "," << fixed << setprecision(2) << salary;
}
<<<<<<< HEAD
bool Employee::write(std::ofstream& ofs, ofstream& nfs)const {
    std::streampos nameLoc = nfs.tellp();
    size_t nameLen = strlen(name);
    nfs.write(name, nameLen);
    ofs.write((const char*)this, sizeof(*this));
    ofs.write((const char*)&nameLoc, sizeof(nameLoc));
    ofs.write((const char*)&nameLen, sizeof(nameLen));
    return ofs && nfs;
}
bool Employee::read(ifstream& ifs, ifstream& nfs) {
    std::streampos nameLoc{};
    size_t nameLen{};
    delete[] name;
    ifs.read((char*)this, sizeof(*this));
    ifs.read((char*)&nameLoc, sizeof(nameLoc));
    ifs.read((char*)&nameLen, sizeof(nameLen));
    name = new char[nameLen];
    ifs.read(name, nameLen);
    name[nameLen] = 0;
    return ifs && nfs;
}
=======
bool Employee::write(std::ofstream& ofs, ofstream& nfs) const { // writing one employee 
    std::streampos nameLoc = nfs.tellp();
    // nameLoc will be the address of the name inside the file
    // and then tell me what is the length of the name
    // because each one has different length, we need to know
    // how many we have to read after 
    size_t nameLen = strlen(name);
    nfs.write(name, nameLen); // write in nfs in the name file system,
    // Employee in file = *this (shallow assignment) // does exactly the same
    // shallow copy - copies one-by-one regardless of what is the data
        // if you put garbage, you get garbage
    // while deep copy is to look at the data, interpret it and pass it along
    // write the name up to name lenghts
    ofs.write((const char*)this, sizeof(*this)); // writing in the object // first we're writing the obejct itself
    // go to the beginning of the object
    // cast it into a constant character pointer
    // write this object into memory to size of this
        // which sizes are a double = 8 bytes
        // int = 8 bytes (64-bit)
        // char* = 8 bytes
        // 24 bytes total
    ofs.write((const char*)&nameLoc, sizeof(nameLoc)); // go to the address of name location and write it in a file
    ofs.write((const char*)&nameLen, sizeof(nameLen));
    // the sizes are always identical
    return ofs && nfs;
    // the data that we have from the class is now saved in two files
}
bool Employee::read(ifstream& ifs, ifstream& nfs) {
    // its gonna read the salary, the employee number, and some garbage address
    std::streampos nameLoc{};
    size_t nameLen{};
    delete[] name;
    // *this = Employee in file (shallow assignment) 
        // go to the address of the current object byte-by-byte, write it into the file
        // it looks like the first byte is 1/8 of that double
        // doesn't care its a double
        // it goes through the thing that 24 bytes one-by-one and writes it into the file
        // it doesn't know its employee, it just knows its an address in memory and this is its size 
        // shallow copy when you do not implement the copy constructor amd copy assignment
    ifs.read((char*)this, sizeof(*this));
    ifs.read((char*)&nameLoc, sizeof(nameLoc)); // read the name location from the file
    ifs.read((char*)&nameLen, sizeof(nameLen)); // read the name length from the file
    if (ifs) { // if the file was successfully opened
        name = new char[nameLen + 1]; // allocate enough space for the name // overwrite the name
        nfs.seekg(nameLoc);  // seek to the name location
        nfs.read(name, nameLen); // read into the name up to the name length character
        name[nameLen] = 0; // set the last character to 0
    } else {
        name = nullptr;
    }
    return ifs && nfs;
}
std::ostream& operator<<(std::ostream& os, const Employee& E) {
    return E.print(os);
}



// index file is a quicker way to search
>>>>>>> 751b4161cf9f622e405957a10f73969fb6fda493
