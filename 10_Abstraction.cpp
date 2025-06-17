/* Abstraction 
In C++, abstraction is a concept in object-oriented programming (OOP) that hides the internal implementation details and only exposes essential information to the user. 

1) 1st way to implement abstraction is using access modifiers (private, protected, and public) to control what information and functions are exposed to the outside world. Access modifiers help hide unnecessary details (private/protected) and allow only essential information to be accessible (public).

2) 2nd way in which abstraction is often implemented through abstract classes and pure virtual functions.

    ** Abstract Classes
        - An abstract class is a class that cannot be instantiated on its own; it is designed to be a base(template) class for other classes.
        - Abstract classes contains at least 1 pure virtual functions.

    ** Pure Virtual Functions
        - A pure virtual function is a function declared in a base class that has no definition in that class.
        - A functions with no implementation in the base class. A pure virtual function is declared by assigning = 0 to the function prototype.
        - Derived classes must provide an implementation for all pure virtual functions in the base class.

    ** Syntax of an Abstract Class with Pure Virtual Functions
        // It is an Abstract class, as it contains a pure virtual function
        class Demo {
            public:
                virtual void fun() = 0; // Pure virtual function
        };

    If a class contains at least one pure virtual function, it becomes abstract and cannot be instantiated.
    Any class inheriting from AbstractClass must provide an implementation for  pure virtual function.


    So, there is no abstract keyword, any class with at least one pure virtual function will be abstract class, and the class that inherit the abstact class, will compulsorily override all those pure virtual functions (if not overrided these methods then the implemented class will again be an abstract class)
*/

#include <iostream>
using namespace std;

class AbstractClass {
public:
    virtual void display() = 0; // Pure virtual function, making this class abstract
    void timepass(){
        cout << "Do nothing\n";
    }
};

class DerivedClass : public AbstractClass {
public:
    void display() override {
        cout << "Implementing display in DerivedClass\n";
    }
};

int main() {
    // AbstractClass obj; // Error: cannot instantiate abstract class
    
    DerivedClass obj;
    obj.display(); // Works as DerivedClass implements display()
    obj.timepass();
    return 0;
}
