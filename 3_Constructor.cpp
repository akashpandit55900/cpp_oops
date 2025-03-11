/*
    1) Constructor  -> 
                - A constructor is a special method, that is automatically invoked (called) at the time of object creation.
                - It is used to initialize an object
                - It has the same name as that of the class
                - It doesnt have any return type (not even void)
                - It is always declared in public. (Bcz constructor are called in main function or object of a class is created from the main function)
                - Class doesnt take any memory, memory is only allocated if an object of that class is created and that happens only when constructor is called
                - If a user doesnt create the constructor then compiler will automatically add a default constructor that will initialize the data members to default values.

    2) Types of constructor -> 
        a) Default Constructor (or Non-Parameterized Constructor): A constructor that takes no arguments and initializes objects with default values.
        b) Parameterized Constructor: A constructor that takes arguments to initialize objects with specific values.
        c) Copy Constructor: A constructor that creates a new object as a copy of an existing object.
    
    3) this keyword ->
        The this keyword is a pointer in C++ that refers to the current object of the class. It is mainly used in the following scenarios:
        To access instance(class/properties) variables when local variables have the same name.
        e.g.:
        class Example {
            private:
                int value;

            public:
                Example(int value) {
                    this->value = value;  // Using 'this' to refer to the current object's value
                }
        };

    4) Constructor Overloading ->
        Constructor overloading is a feature in C++ that allows a class to have more than one constructor, each having different parameters.
        e.g.:
        class Example {
            public:
                // Default constructor
                Example() {
                    cout << "Default constructor" << endl;
                }

                // Parameterized constructor
                Example(int x) {
                    cout << "Parameterized constructor with value: " << x << endl;
                }

                // Another parameterized constructor
                Example(int x, int y) {
                    cout << "Two-parameter constructor with values: " << x << ", " << y << endl;
                }
        };
        int main() {
            Example obj1;            // Calls default constructor
            Example obj2(10);         // Calls parameterized constructor with 1 argument
            Example obj3(10, 20);     // Calls parameterized constructor with 2 arguments
            return 0;
        }

*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    int length;
    int breadth;

public:
    // Default constructor
    Rectangle() {
        length = 0;
        breadth = 0;
        cout << "Default constructor called. Length: " << length << ", Breadth: " << breadth << endl;
    }

    // Parameterized constructor
    Rectangle(int length, int breadth) {
        this->length = length;
        this->breadth = breadth;
        cout << "Parameterized constructor called. Length: " << length << ", Breadth: " << breadth << endl;
    }

    // Copy constructor
    // Rectangle(const Rectangle &rect) {
    Rectangle(Rectangle &obj) {
        this->length = obj.length;
        this->breadth = obj.breadth;
        cout << "Copy constructor called. Length: " << length << ", Breadth: " << breadth << endl;
    }

    // Function to display the area of the rectangle
    void displayArea() {
        cout << "Area of rectangle: " << length * breadth << endl;
    }
};

int main() {
    // Using default constructor
    Rectangle rect1;
    rect1.displayArea();

    // Using parameterized constructor
    Rectangle rect2(11, 5);
    rect2.displayArea();

    // Using copy constructor  (If user didnt add copy constructor's body, compiler will add its own or else you can write your own custom logic)
    Rectangle rect3 = rect2;
    // Rectangle rect3(rect2);
    rect3.displayArea();

    return 0;
}
