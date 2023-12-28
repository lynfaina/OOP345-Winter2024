#include <vector>
#include <iostream>
using namespace std;
int main() {
    std::vector<double> prices; // creates vector of doubles
    // std::vector<double> prices(8); // better to set to the size you want
    if (prices.empty())     // is price empty? // if its empty or not
        std::cout << "price is empty" << std::endl;
    prices.push_back(10.43); // add 10.43
    prices.push_back(20.54); // add 20.54
    prices.push_back(32.43); // add 32.43
    for (int i = 0; i < prices.size(); i++)
        std::cout << prices[i] << " "; // look at the elements, exactly like a regular array
    std::cout << std::endl;
    prices.front() = 54.11; // change 1st element // look, access, or modify the list
    prices.pop_back();     // remove last element // remove values
    for (int i = 0; i < prices.size(); i++)
        std::cout << prices[i] << " ";
    std::cout << std::endl;
    return 0;
}

// anytime you use an array, try to use vector instead
// vector is much more efficient than an array