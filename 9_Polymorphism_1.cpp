/* 
    A virtual function in C++ is a member function declared in a base class using the virtual keyword, which allows it to be overridden in any derived class. This mechanism supports runtime polymorphism (or dynamic binding), meaning that the decision about which function to call is made at runtime based on the actual type of the object, not the type of the pointer or reference that points to it.

    Key Points
    1) Declaration:
    You declare a virtual function in the base class by preceding its declaration with the virtual keyword.

    2) Overriding:
    In a derived class, you can override the virtual function to provide specialized behavior. Although the override keyword is optional, it is recommended for clarity and compile-time checking.

    3) Dynamic Binding:
    When you call a virtual function through a base class pointer or reference, C++ determines at runtime which version of the function to invoke (the base or the derived version) based on the actual object type.


** Always remember this: 
    base class pointer can only point to a derived class object. (whatever the base class want, is inside the derived class)
    Vice - Versa is not possible (whatever the derived class want, is not always present inside the base class)

    1) Allowed
        Parent *p1 = &c;
        p1->getInfo();

    2) Not Allowed
        Child *c1 = &p;
        c1->getInfo();


**  IMP NOTE: 
    a) Method overriding can only occur if a function is virtual in the base class.
    b) Without marking a function as virtual in the base class, a derived class function with the same name and parameters will hide the base class function instead of overriding it.

    1) First Way: Using the Scope Resolution Operator
    This approach does not achieve runtime polymorphism. Instead, it simply calls a specific function by explicitly qualifying it with the class name (scope resolution).
*/
#include <iostream>
using namespace std;

class Parent {
public:
    void getInfo() {
        cout << "Parent Class Function\n";
    }
};

class Child : public Parent {
public:
    void getInfo() {
        cout << "Child Class Function\n";
    }
};

int main() {
    Parent p;
    p.getInfo(); // Calls Parent's getInfo()

    Child c;
    c.getInfo(); // Calls Child's getInfo()

    c.Parent::getInfo(); // Calls Parent's getInfo() using scope resolution

    return 0;
}

// 2) Second Way: Using Virtual Functions
// This approach does achieve runtime polymorphism by marking getInfo() as a virtual function in the Parent class.
//The override keyword is optional but helps improves readability.
#include <iostream>
using namespace std;

class Parent {
public:
    virtual void getInfo() { // Virtual function for polymorphism
        cout << "Parent Class Function\n";
    }

    void Greet() { // Non-virtual function
        cout << "Hi I am from Parent\n";
    }
};

class Child : public Parent {
public:
    void getInfo() override { // Overrides Parent's getInfo()
        cout << "Child Class Function\n";
    }

    void Greet() { // Hides Parent's Greet()
        cout << "Hi I am from Child\n";
    }
};

int main() {
    // Child c;
    // Parent* p = &c; // Base class pointer pointing to derived class object
    Parent* p = new Child(); 
    
    p->getInfo(); // Calls Child's getInfo() due to virtual function (runtime polymorphism)
    //Jab getInfo() call karne jayega tab dikhega ki ye toh vitual function hai toh isse jarur child class ne override kiya hoga, so lets go to child class getInfor();
    p->Greet();   // Calls Parent's Greet() since Greet() is non-virtual

    return 0;
}

/*
    - Without Virtual Functions (Function Hiding)
    1) Function Hiding:
    If the base class method (e.g., draw()) is not marked as virtual, and the derived class defines a method with the same name and signature, the derived version hides the base version.

    2) Pointer Behavior:
    When you use a base class pointer (e.g., Shape* ptr) that points to a derived class object (e.g., a Circle object), calling ptr->draw() will invoke the base class version. This is because the decision is made at compile time (static binding) based solely on the pointer's type, not on the actual object type.

    3) Accessing the Base Method:
    You can still call the base class version explicitly using the scope resolution operator (e.g., obj2.Shape::draw();).

    - With Virtual Functions (True Method Overriding)
    1) Runtime Polymorphism:
    If the base class method is declared with the virtual keyword, then the derived class method overrides it. This allows dynamic binding at runtime.

    2) Pointer Behavior:
    With a base class pointer pointing to a derived object, calling the method (e.g., ptr->draw()) will invoke the derived class version, thanks to the virtual mechanism. calls to pointer jisko point kar raha hai

    3) Accessing the Base Method:
    Once the method is overridden through virtual, a base class pointer calling draw() will always dispatch to the derived class version (if the object is actually of the derived type). To access the parent's version in this scenario, you must explicitly call it with something like obj2.Shape::draw().

*/