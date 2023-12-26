#include <iostream>
using namespace std;

int main(int argc, char* argv[]) { // char* argv[] is a pointer of character array
// int main(int argc, char** argv) { another syntax
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }
    return 0;
}

// argc is the number of counter for arguments on the cmd line
// array of c-strings is argv
// a[0] is the name of the program
// a[1] is the second argument
// a[2] is the third argument .....