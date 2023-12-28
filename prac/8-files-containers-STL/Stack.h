#ifndef SDDS_STACK_H
#define SDDS_STACK_H
template <typename T>
class Stack;
template <typename T>
class Node {
    Node<T>* m_next = nullptr; // next pointer that points to the next node
    T m_data; // it has data
    Node(T data, Node<T>* next = nullptr) : m_next(next), m_data(data) {}  // Use member initializer list
    friend class Stack<T>; // this node is owned by a stack of its own type
};
template <typename T>
class Stack {
    Node<T>* top = nullptr; // stak has a top
public:
    Stack<T>& push(T data) { // it has a push
        top = new Node<T>(data, top); // it creates a new node and makes the next of that node point to the top
        // and sets the top to the node
        // pushing to the top of the node
        return *this;
    }
    T pop() { // it has a pop
        T val; // receives the value
        val = top->m_data; // out of the top node
        Node<T>* todel = top;
        top = top->m_next; // makes the top one point to the next
        delete todel; // deletes the top
        return val; // returns the value
    }
    operator bool() { // is empty
    // a stack is empty if the top is null
        return top != nullptr;
    }
    virtual ~Stack() { // destructor
    // pops until there is nothing
        while (*this) {
            pop();
        }
    }
};


#endif // SDDS_STACK_H