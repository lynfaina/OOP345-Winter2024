#ifndef SICT_QUEUE_H
#define SICT_QUEUE_H
#include <cstddef> // for size_t
class Queue;
class Qnode {
    double m_data;
    Qnode* m_next;
    Qnode* m_prev;
    Qnode(const double& data={}, Qnode* prev = nullptr, Qnode* next = nullptr);
    friend class Queue;
};
class Queue {
    Qnode* m_head = nullptr;
    Qnode* m_tail = nullptr;
    size_t m_size = 0;
    static size_t m_serial;
public:
    Queue(); // getting created
    Queue(size_t size); // create a queue with an initial size
    Queue(size_t size, const double& data); // create a queue with a certain size and put values in it
    Queue(const Queue& Q); // copy a queue
    Queue(Queue&& Q)noexcept; // move a queue
    ~Queue(); // destroy a queue
    Queue& operator=(const Queue& Q); // assignment operator
    Queue& operator=(Queue&& Q)noexcept; // move assignment operator
    size_t size()const; // when created, it has a size that tells how much data it has
    bool empty()const; // empty or not
    double& operator[](size_t index); // index operator that you can deal with it it like an array
    const double& operator[](size_t index)const; // index operator that you can deal with it it like an array
    double& front(); // can see what is in the front
    const double& front()const;
    double& back(); // can see what is in the back
    const double& back()const;
    void push_back(const double& data); 
    void push_front(const double& data);
    void pop_back();
    void pop_front();
    void clear();
    static size_t serial();
};
#endif