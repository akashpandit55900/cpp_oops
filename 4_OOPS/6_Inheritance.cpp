/*
    1. Definition of Inheritance
        Inheritance allows a class (derived class) to inherit properties and behaviors (methods) from another class (base class). This promotes code reusability and establishes a relationship between classes.

        Parent / Base /  Super 
        |       |       |
        Child / Derieved / Sub class

    2. Types of Inheritance
        - Single Inheritance: A class inherits from one base class.
        - Multiple Inheritance: A class inherits from more than one base class.
        - Multilevel Inheritance: A class is derived from another derived class.
        - Hierarchical Inheritance: Multiple classes inherit from a single base class.
        - Hybrid Inheritance: A combination of two or more types of inheritance.
        
        *Visual Representation -> image.png

    3. Mode of Inheritance
        Refer C++ OOPS\Mode_Of_Inheritance.png (Remember from top to bottom)
        Private members of the base class cannot be inherited through any mode of inheritance

*/

// Derived Class syntax
// class derived_class_name : access_modifier base_class_name
// {
//     // body of the derived class
// };


// 1) Single Inheritance 
#include<iostream>
using namespace std;

class Base{
    public:
        void display(){
           cout << "Base class method" << endl;
        }
};

class Derived : public Base{
    public:
        void show(){
            cout << "Derived class method" << endl;
        }
};

int main() {
    Derived obj;
    obj.display();  // Calls Base class method
    obj.show();     // Calls Derived class method
    return 0;
}


// 2) Multiple Inheritance

#include <iostream>
using namespace std;

class Base1 {
public:
    void display1() {
        cout << "Base1 class method" << endl;
    }
};

class Base2 {
public:
    void display2() {
        cout << "Base2 class method" << endl;
    }
};


class Derived : public Base1, public Base2{
    public:
        void show() {
            cout << "Derived class method" << endl;
        }
};

int main() {
    Derived obj;
    obj.display1(); // Calls Base1 class method
    obj.display2(); // Calls Base2 class method
    obj.show();     // Calls Derived class method
    return 0;
}


// 3. Multilevel Inheritance

#include <iostream>
using namespace std;

class Base {
public:
    void baseMethod() {
        cout << "Base class method" << endl;
    }
};

class Intermediate : public Base{
    public:
        void intermediateMethod() {
            cout << "Intermediate class method" << endl;
        }
}

class Derived : public Intermediate{
    public:
        void derivedMethod() {
            cout << "Derived class method" << endl;
        }
}

int main() {
    Derived obj;
    obj.baseMethod();        // Calls Base class method
    obj.intermediateMethod(); // Calls Intermediate class method
    obj.derivedMethod();     // Calls Derived class method
    return 0;
}


// 4. Hierarchical Inheritance

#include <iostream>
using namespace std;

class Base {
public:
    void display() {
        cout << "Base class method" << endl;
    }
};

class Derived1 : public Base {
public:
    void show1() {
        cout << "Derived1 class method" << endl;
    }
};

class Derived2 : public Base {
public:
    void show2() {
        cout << "Derived2 class method" << endl;
    }
};

int main() {
    Derived1 obj1;
    Derived2 obj2;

    obj1.display();  // Base class method (accessed by Derived1)
    obj1.show1();    // Derived1 class method

    obj2.display();  // Base class method (accessed by Derived2)
    obj2.show2();    // Derived2 class method

    return 0;
}


// 5. Hybrid Inheritance
#include <iostream>
using namespace std;

class Base1 {
public:
    void display1() {
        cout << "Base1 class method" << endl;
    }
};

class Base2 {
public:
    void display2() {
        cout << "Base2 class method" << endl;
    }
};

class Intermediate : public Base1, public Base2 {
public:
    void intermediateMethod() {
        cout << "Intermediate class method" << endl;
    }
};

class Derived : public Intermediate {
public:
    void derivedMethod() {
        cout << "Derived class method" << endl;
    }
};

int main() {
    Derived obj;
    obj.display1();         // Base1 class method
    obj.display2();         // Base2 class method
    obj.intermediateMethod(); // Intermediate class method
    obj.derivedMethod();    // Derived class method
    return 0;
}

// Explanation:
// Hybrid inheritance combines multiple inheritance (Base1, Base2) and multilevel inheritance (Intermediate -> Derived).

