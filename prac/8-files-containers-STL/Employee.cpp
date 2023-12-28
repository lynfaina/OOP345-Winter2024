#include "Employee.h"
#include <cstring>
#include <iostream>

void Employee::setName(const char* name) {
    delete[] m_name;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}

Employee::Employee() : m_name(nullptr), m_empno(-1) {}

Employee::Employee(const char* name, unsigned long empno) : m_empno(empno) {
    setName(name);
}

Employee::Employee(const Employee& e) : m_empno(e.m_empno) {
    setName(e.m_name);
}

Employee& Employee::operator=(const Employee& e) {
    if (this != &e) {
        m_empno = e.m_empno;
        setName(e.m_name);
    }
    return *this;
}

Employee::Employee(Employee&& e) : m_name(e.m_name), m_empno(e.m_empno) {
    e.m_name = nullptr;
    e.m_empno = -1;
}

Employee& Employee::operator=(Employee&& e) {
    if (this != &e) {
        delete[] m_name;
        m_name = e.m_name;
        m_empno = e.m_empno;
        e.m_name = nullptr;
        e.m_empno = -1;
    }
    return *this;
}

Employee::~Employee() {
    delete[] m_name;
}

std::istream& Employee::read(std::istream& is) {
    char buffer[200];
    cout << "Enter name: ";
    is.getline(buffer, 200, '\n');
    setName(buffer);
    cout << "Enter employee number: ";
    is >> m_empno;
    is.ignore(); // ignore the newline character
    return is;
}

std::ostream& Employee::print(std::ostream& os) const {
    os << m_name << ": " << m_empno;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Employee& E) {
    return E.print(os);
}

std::istream& operator>>(std::istream& is, Employee& E) {
    return E.read(is);
}
