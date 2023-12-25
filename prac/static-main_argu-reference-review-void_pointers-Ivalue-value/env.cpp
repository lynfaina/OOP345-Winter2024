#include <iostream>
using namespace std;

int main(int argc, char* argv[], char* env[]) {
    for (int i = 0; env[i]; i++) {
        cout << (i + 1) << "- " << env[i] << endl;
    }
    return 0;
}

// argc is the number of counter for arguments on the cmd line
// array of c-strings is argv
// a[0] is the name of the program
// a[1] is the second argument
// a[2] is the third argument .....

// env everything from the computer is in the env array