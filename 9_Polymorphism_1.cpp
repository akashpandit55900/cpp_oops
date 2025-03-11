/* 

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
