#include <iostream>
#include <string>
using namespace std;
bool isAdult(int num, string& err) { // receives an integer and returns a boolean
    bool res = true;
    if(!(num>=18 && num <=65)) {
        err = "No children or Seniors";
        res = false;
    }
    return res; // return the condition
}
bool validNoOfStudents(int num, string& err) { // exactly the same as above
    bool res = true;
    if(!(num >=10 && num <=35)) {
        err = "Invalid number of students";
        res = false;
    }
    return res;
}
// pointer to a function
int getInt(bool (*isValid)(int, string&)); // changed the validation signature to accept the string
// to tell the user that wanted to use the getInt, you have to write your validation function
// to check validat an integer and if the condition is false. set the error message to the proper thing
int main() {
	cout << "Validate an age" << endl;
    cout << "Enter an age: ";
    int age = getInt(isAdult); // pass the address of that logic to getInt 
    cout << "age: " << age << endl;
    cout << "Enter the number of students: ";
    int stno = getInt(validNoOfStudents); // pass the address of that logic to getInt 
    cout << stno << " students in class." << endl;
	return 0;
}
int getInt(bool (*isValid)(int, string&)) { // receiving a pointer to any function that accepts an integer and returns a boolean
// changed the validation signature to accept the string
// changed to string& so it can be passed by reference and it can actually change something if needed
    int num{};
    bool done = false;
    string errMes{}; // 
    do {
        cin >> num;
        if(cin.fail()) { // if it failed
            cin.clear(); // clear
            cout << "Invalid integer, try again...\n> "; // if the user input only characters
        }
        else { // if did not fail
            if(cin.peek() != '\n') { // take a look at the next character that is coming
            // see if its newline or not
            // if the user input numbers with characters
                cout << "Only an integer number please...\n> "; 
                // if its not newline it means they entered something after an integer
            }
            else if (isValid(num, errMes)) { // valid integer // call isAdult function
            // when auto validNoOfStudents(int num)->bool, then its pointer to functions
            // an array's name holds the piece of memory the data of the array is sitting it
            // the data in an array is what you use as data so the logic can process it
            // and a function is a piece of data which processes that array thing
            // so its logic but its still data, everything is data in memory
            // the function that you are creating, the name of the function holds the address of your logic in memory
            // changed to isValid(num) calling a function
            // changed isValid(num, errMes) to pass the error message
                done = true;
            }
            else { // not valid integer
                cout << errMes << "...\n> ";
            }
        }
        cin.ignore(1000, '\n'); // flush the buffer
    } while (!done);
    return num;
}