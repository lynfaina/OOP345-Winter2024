#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream file("nums.bin", ios::binary);
    double d;
    while (file.read((char*)&d, sizeof(d))) {
        cout << d << endl;
        file.seekg(1000 * sizeof(double)); // the action of seeking will not fail the iostream
        // to check and see if actually your seekg work, you have to do a tellg and see
        // if the address you went to is actually what you wanted
        if (file.fail()) // seeking will not fail, but reading will
            cout << "seekg failed" << endl;
    }
}