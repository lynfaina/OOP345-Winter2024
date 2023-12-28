#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
//#include <cstdint>
using namespace std;
class Employee {
    char* m_name = nullptr;
    //uintptr_t long m_empno = -1;
    unsigned long m_empno = ULONG_MAX;
    void setName(const char* name);
public:
    Employee();
    ~Employee();
    //Employee(const char* name, uintptr_t long empno);
    Employee(const char* name, unsigned long empno);
    Employee(const Employee& e);
    Employee& operator=(const Employee& e);
    Employee(Employee&& e);
    Employee& operator=(Employee&& e);
    std::istream& read(std::istream& is);
    std::ostream& print(std::ostream& os)const;
};
std::ostream& operator<<(std::ostream& os, const Employee& E);
std::istream& operator>>(std::istream& is, Employee& E);
#endif