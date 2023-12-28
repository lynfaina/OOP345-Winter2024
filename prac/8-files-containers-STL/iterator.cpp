#include <vector>
#include <iostream>
using namespace std;

int main() {
    std::vector<double> prices; // initially empty
    std::vector<double>::iterator i; // i can literally replace an element in the vector
    // simulated pointer to the element of a container
    // traverses through the list
    // iterator works for all the containers

    prices.push_back(10.43); // add 10.43
    prices.push_back(20.54); // add 20.54
    prices.push_back(32.43); // add 32.43
    for (i = prices.begin(); i != prices.end(); i++) // ++ is overloaded on it
        std::cout << *i << " "; // has * in i it gives you the target of it, it accesses the value
        // an all the operatores and things (i++ and *i) are overloaded so it
        // actually looks like a pointer but its not
        // i = prices.begin();
            // set the iterator to point to the very first element of the vector, start from the first one
        // i != prices.end();
            // while it is not the last one
        // i++;
            // add one by way to it
        // *i
            // access the value of the element
    std::cout << std::endl;
    return 0;
}