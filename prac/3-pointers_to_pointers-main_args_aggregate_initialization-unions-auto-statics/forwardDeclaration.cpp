#include <iostream>
using namespace std;

class Person; // forward declaration
// we have prototype for function, prototype for variables by using extern keyword
// now we have prototype for classes
// it tells the class Title that a Person is a class, create a pointer out of it
// but if we bring the class Person after the class Title, we will get an error
// because class Person has a Title tlt which is not a reference or pointer
// because the Title needs to get built and the forward declaration of the class Title
// has no information of the Constructor of the Title or the functionalities of the Title
// NOTE: ALWAYS PUT THE CLASS AT THE TOP THAT IS USING THE OTHER CLASSES POINTER OR REFERENCE
// AND FORWARD DECLARE THE CLASS
class Title {
    string titlename;
    Person* givenTo[100]{}; // the title is only given up to 100 people
    unsigned int num{};
public:
    Title(string title = ""):titlename(title) {
    }
    void giveto(Person* person) {
        if(num < 100) givenTo[num++] = person;
    }
};

// if we want to create the Person, because Person has the Title
// we need to put the Class Person after the class Title
// because class Title is being given to the Person (Person* givenTo[100]{};),
// it needs to know what the person is being given to
// so we need to forward declare the class Person because it is being used in the class Title
// because class Person has a reference or a pointer in the class Title
// e.g. we have Person* givenTo[100]{}; which pointers to a Person
class Person {
    struct {
        string first;
        string last;
    } name;
    Person* marriedTo{};
    Title tlt;
    // Person marriedTo; like forward declaration only pointers and refs are allowed
public:
    Person(string first, string last, Title tlt):name{first, last}, tlt(tlt){}
};


// added for testing
int main() {
    // Example usage
    Title title("Duke");
    Person person("John", "Doe", title);

    // Do something with title and person...

    return 0;
}