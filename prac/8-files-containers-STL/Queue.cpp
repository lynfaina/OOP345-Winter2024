#include <utility>
#include <iostream>
#include "Queue.h"
using namespace std;

size_t Queue::m_serial = 0;
size_t Queue::serial() {
    return m_serial;
}
Qnode::Qnode(const double& data, Qnode* prev, Qnode* next):
    m_data(data), m_next(next), m_prev(prev) {}

Queue::Queue() {
    m_serial++;
}
Queue::Queue(size_t size) : Queue(size, {}) {
    m_serial++;
}
Queue::Queue(size_t size, const double& data) {
    while (size--) {
        (push_back(data));
    }
    m_serial++;
}
Queue::Queue(const Queue& Q) {
    operator=(Q);
    m_serial++;
}
Queue::Queue(Queue&& Q)noexcept {
    operator=(std::move(Q));
    m_serial++;
}
Queue::~Queue() {
    clear();
    m_serial--;
}
Queue& Queue::operator=(const Queue& Q) {
    clear();
    for (size_t i = {}; i < Q.size(); push_back(Q[i++]));
    return *this;
}
Queue& Queue::operator=(Queue&& Q)noexcept {
    clear();
    m_head = Q.m_head;
    m_tail = Q.m_tail;
    m_size = Q.m_size;
    Q.m_head = Q.m_tail = nullptr;
    Q.m_size = 0;
    return *this;
}
size_t Queue::size()const {
    return m_size;
}
bool Queue::empty()const {
    return m_head == nullptr;
}
double& Queue::operator[](size_t index) {
    if (empty())push_back({});
    index %= size();
    Qnode* cur = m_head;
    for (size_t i = 0; i < index; i++, cur = cur->m_next);
    return cur->m_data;
}
const double& Queue::operator[](size_t index)const {
    index %= size();
    Qnode* cur = m_head;
    for (size_t i = 0; i < index; i++, cur = cur->m_next);
    return cur->m_data;
}
double& Queue::front() {
    return m_head->m_data;
}
const double& Queue::front()const {
    return m_head->m_data;
}
double& Queue::back() {
    return m_tail->m_data;
}
const double& Queue::back()const {
    return m_tail->m_data;
}
void Queue::push_back(const double& data) {
    Qnode* new_tail = new Qnode(data, m_tail);
    if (m_head) // not empty, at least one
        m_tail = m_tail->m_next = new_tail;
    else    
        m_head = m_tail = new_tail;
    
    m_size++;
}
void Queue::push_front(const double& data) {
    Qnode* new_head = new Qnode(data, nullptr, m_head);
    if (m_tail) // not empty, at least one
        m_head = m_head->m_prev = new_head;
    else    
        m_tail = m_head = new_head;
    
    m_size++;
}
void Queue::pop_back() {
    if (m_tail) { // if (!empty())
        if (m_tail == m_head) m_head = nullptr;
        Qnode* toDelete = m_tail;
        m_tail = m_tail->m_prev;
        m_tail->m_next = nullptr;
        delete toDelete;
        m_size--;
    }
}
void Queue::pop_front() {
    if (m_head) { // if (!empty())
        if (m_tail == m_head) m_tail = nullptr;
        Qnode* toDelete = m_head;
        m_head = m_head->m_next;
        m_head->m_prev = nullptr;
        delete toDelete;
        m_size--;
    }
}
void Queue::clear() {
    Qnode* toDel = m_head;
    while (toDel) {
        m_head = m_head->m_next;
        delete toDel;
        toDel = m_head;
    }
    m_size = 0;
}



int main() {
    Queue q1; // Default constructor
    std::cout << "Queue 1 Size: " << q1.size() << std::endl; // Output: 0

    Queue q2(5); // Constructor with size
    std::cout << "Queue 2 Size: " << q2.size() << std::endl; // Output: 5

    Queue q3(3, 7.5); // Constructor with size and initial value
    std::cout << "Queue 3 Size: " << q3.size() << std::endl; // Output: 3

    Queue q4 = q3; // Copy constructor
    std::cout << "Queue 4 Size: " << q4.size() << std::endl; // Output: 3

    Queue q5(std::move(q4)); // Move constructor
    std::cout << "Queue 5 Size: " << q5.size() << std::endl; // Output: 3
    std::cout << "Queue 4 Size after move: " << q4.size() << std::endl; // Output: 0

    // Accessing elements
    q5[0] = 10.2;
    std::cout << "Front of Queue 5: " << q5.front() << std::endl; // Output: 10.2
    std::cout << "Back of Queue 5: " << q5.back() << std::endl;   // Output: 7.5

    // Pushing and popping elements
    q5.push_back(15.3);
    std::cout << "Queue 5 Size after push_back: " << q5.size() << std::endl; // Output: 4
    q5.pop_front();
    std::cout << "Queue 5 Size after pop_front: " << q5.size() << std::endl; // Output: 3

    return 0;
}