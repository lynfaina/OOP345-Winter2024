#include <iostream>
using namespace std;
auto isAdult(int num)->bool { // receives an integer and returns a boolean
    return num>=18 && num <=65; // return the condition
}
auto validNoOfStudents(int num)->bool { // exactly the same as above
    return num >=10 && num <=35;
}
auto getInt()->int;
auto main() -> int {
	cout << "Validate an age" << endl;
    cout << "Enter an age: ";
    int age = getInt();
    cout << "age: " << age << endl;
	return 0;
}
auto getInt()->int {
    int num;
    bool done = false;
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
            else if (isAdult(num)) { // valid integer // call isAdult function
            // when auto validNoOfStudents(int num)->bool, then its pointer to functions
            // an array's name holds the piece of memory the data of the array is sitting it
            // the data in an array is what you use as data so the logic can process it
            // and a function is a piece of data which processes that array thing
            // so its logic but its still data, everything is data in memory
            // the function that you are creating, the name of the function holds the address of your logic in memory
                done = true;
            }
            else { // not valid integer
                cout << "No children or Seniors permitted...\n> ";
            }
        }
        cin.ignore(1000, '\n'); // flush the buffer
    } while (!done);
    return num;
}