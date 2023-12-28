#include <iostream>
using namespace std;
int main() {
    int i;
    double d = 10;
    char str[] = "A Cstring!";
    for(i = 0; i < 5; i++) {
        // syntax of exceptions
        // block statements are called try and catch
        // the statement is called throw
        try {
            if(i == 0) {
                throw d; // throw the d object
            }
            if(i == 1) {
                throw str; // throw the str object
            }
            throw i; // if non of them happens, throw the i itself
            cout << "This will never happen!!!!!" << endl;
        }
        // catch can be many
        // one of them is gonna catch what you try to throw from there
        // if none of them catches, program will terminate (unhandled exception)
        catch (double de) { // catch for a double
            cout << "A double exception is here: " << de << endl;
        }
        catch (const char* cstre) { // receive a const char*
            cout << "A cString exception is here: " << cstre << endl;        
        }
        catch (...) { // general exception
            cout << "Something was thrown, I don't know what!" << endl;
        }
    }
    
    return 0;
}

// with an exception handling, you put all the things that are supposed to go perfectly
// back to back and you do all error handling in the catch statements that you have
// so your logic is not gonna have some nested if statements, if any of those
// things go wrong, you go to the catch statement, you handle the error and you
// go back up and try again