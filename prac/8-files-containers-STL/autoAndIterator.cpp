#include <vector>
#include <iostream>
using namespace std;

int main() {
    std::vector<double> prices; // initially empty
    // no iterator

    prices.push_back(10.43); // add 10.43
    prices.push_back(20.54); // add 20.54
    prices.push_back(32.43); // add 32.43
    for (auto i = prices.begin(); i != prices.end(); i++) // ++ is overloaded on it
    // if no iterator, use auto 
        std::cout << *i << " "; // has * in i it gives you the target of it, it accesses the value
    std::cout << std::endl;
    return 0;
}