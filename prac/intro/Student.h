#pragma once
class Student {
    int stno; // class scope
    // accessible within Student class
public:
    void display();
    Student();
};

extern const int MinPassGrade; 
// makes the file scope to global

// difference between using extern and #include
/* extern is when you declare a variable in cpp file as
 * a global scope and then extern it in the header file
 * then #include the header file in any cpp file then
 * you can use the definition within the cpp file
 * where the extern or global scope variable is used
*/
/* #include is when you include the header file in
 * any cpp file and copy the header file contents
 * in that cpp file including the extern in the
 * header file
*/
/* you cannot use the global scope inside the cpp
 * file if you didn't extern it in the header file
 * even though you include the header file in any
 * cpp file
*/