#include <iostream>
using namespace std;

// whatever inside the class its explaining how
// the objects are gonna look like
// and objects had nothing to do with the class
class Container {
    int m_data;
    static int m_cnt;
public:
    Container(int data = 1) {
        m_data = data; // reading all the data in the container
        m_cnt++; // adding 1 to know how many objects have
    }
    ostream& display(ostream& ostr = cout) {
        ostr << m_data << " (" << noOfInstances() <<")" << endl; 
        // display data first C[0] then noOfInstances (how many in m_cnt)
        // display new data added C[3] then noOfInstances (how many in m_cnt)
        return ostr;
    }
    static int noOfInstances() { // class function class method
        // cout << m_data << endl; can only access the static members
        return m_cnt;
    }
    ~Container() {
        m_cnt--; // removing 1
    }
};

// Constructor
// initialize m_cnt to 0
// :: is a scope resolution
// initalization happens at compile time
int Container::m_cnt = 0;

int main()  {
    Container C[3] = {10, 20, 30};
    C[0].display(); // display C[0] = 10
    Container* p;
    p = new Container(40); // adding new data
    p->display(); // display C[3] = 40
    delete p;
    C[1].display();
    cout << Container::noOfInstances() << endl;
    return 0;
}

// instantiation
// creating something or an object of a class
// an instance of car is car c, c becomes an instance of car
// integer i, i is an instance of integer
// shared value between instances of the object
// container a b c d e, a b c d e are instances of container

// compound type
// put two things together
// array, vector, list, map, set, stack, queue, deque, priority queue
// container is a compound type

// cout set(ios::left) 
// left is a scope resolution
// left is the static variable inside the ios class
// accessible by all instances of ios
// therefore when you set it to left, everyday shares the left on the ostream

// scope resolutions are class variable, they are static variables
