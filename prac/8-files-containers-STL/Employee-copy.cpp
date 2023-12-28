#include "Employee-copy.h"
#include <iostream>
#include <iomanip>

Employee::Employee(double sal, int emp, const char* nm) : salary(sal), empno(emp) {
    strncpy(name, nm, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';  // Ensure null-termination
}

bool Employee::operator<(const Employee& other) const {
    return empno < other.empno;
}

std::ostream& Employee::print(std::ostream& os) const {
    return os << std::fixed << std::setprecision(2) << name << "," << empno << "," << salary;
}

std::istream& Employee::read(std::istream& is) {
    std::cout << "Enter employee number: ";
    is >> empno;

    std::cout << "Enter name: ";
    is.ignore();  // Ignore newline character left by previous extraction
    is.getline(name, sizeof(name));

    std::cout << "Enter salary: $";
    is >> salary;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Employee& E) {
    return E.print(os);
}

std::istream& operator>>(std::istream& is, Employee& E) {
    return E.read(is);
}
