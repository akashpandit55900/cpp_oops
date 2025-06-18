/*
    You can return a structure from a function in C++ just like any other data type. This is very common when you want a function to return multiple values packed in a struct.
*/

#include<iostream>
using namespace std;

// Define a structure
struct Student {
    int roll;
    string name;
    float marks;
};

// Function that returns a Student structure
Student getStudent() {
    Student s;
    s.roll = 101;
    s.name = "Ram";
    s.marks = 97;
    return s;
}

int main() {
    Student s1 = getStudent();  // Function call

    // Print returned struct data
    cout << "Roll: " << s1.roll << endl;
    cout << "Name: " << s1.name << endl;
    cout << "Marks: " << s1.marks << endl;

    return 0;
}
