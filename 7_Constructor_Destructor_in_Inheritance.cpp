/*
** Constructor in Inheritance:
When a class is derived from a base class, the constructors of both the base and derived classes are invoked in a specific order:

1) Base class constructor is called first.
2) Derived class constructor is called next.

- Why this order?
The derived class depends on the base class for part of its initialization. So, the base class must be fully constructed before the derived class can be initialized.

** Destructor in Inheritance:
A destructor is responsible for cleaning up resources when an object is destroyed. In inheritance, destructors follow this order:

1) Derived class destructor is called first.
2) Base class destructor is called next.

- The reason is that the derived class may hold resources that depend on the base class, so the derived class's resources should be released before the base class is destroyed.


*/

// Default Base Constructor Called
// #include <iostream>
// using namespace std;

// class Base {
// public:
//     Base() {
//         cout << "Base constructor called" << endl;
//     }
//     ~Base() {
//         cout << "Base destructor called" << endl;
//     }
// };

// class Derived : public Base {
// public:
//     Derived() {
//         cout << "Derived constructor called" << endl;
//     }
//     ~Derived() {
//         cout << "Derived destructor called" << endl;
//     }
// };

// int main() {
//     Derived obj;
//     return 0;
// }


// ** Calling Parameterized Base Class Constructor:
// If the base class has a parameterized constructor, you need to explicitly call it from the derived class constructor using an initializer list.

// Example 1 (Allowed ✅)
// #include <iostream>
// using namespace std;

// class Base {
// public:
 
// };

// class Derived : public Base {
// public:

//     Derived(int x, int y){
//         cout << "Derived class constructor with values: " << x << " & " << y << endl;
//     }
// };

// int main() {
//     Derived obj(10, 20);
//     return 0;
// }

//Example 2:  NOt Allowed (❌)
// #include <iostream>
// using namespace std;

// class Base {
// public:
//     Base(int x) {
//         cout << "Base class constructor with value: " << x << endl;
//     }
// };

// class Derived : public Base {
// public:
//     Derived(int x, int y){
//         cout << "Derived class constructor with values: " << x << " & " << y << endl;
//     }
// };

// int main() {
//     Derived obj(10, 20);
//     return 0;
// }

//Example 3: Allowed (✅)
// #include <iostream>
// using namespace std;

// class Base {
// public:
//     Base(){
//         cout << "Base class constructor called" << endl;
//     }
//     Base(int x) {
//         cout << "Base class constructor with value: " << x << endl;
//     }
// };

// class Derived : public Base {
// public:
//     Derived(int x, int y){
//         cout << "Derived class constructor with values: " << x << " & " << y << endl;
//     }
// };

// int main() {
//     Derived obj(10, 20);
//     return 0;
// }


//Example 4: Allowed (✅)
#include <iostream>
using namespace std;

class Base {
public:
    Base(int x) {
        cout << "Base class constructor with value: " << x << endl;
    }
};

class Derived : public Base {
public:
     // Calling base class constructor from derived class using initializer list
    Derived(int x, int y) : Base(x) {
        cout << "Derived class constructor with value: " << y << endl;
    }
};

int main() {
    Derived obj(10, 20);
    return 0;
}

/*
Notes:
1) Derived class -> parameterized constructor, and Base class -> no constructor => Allowed (✅)
2) Derived class -> parameterized constructor, and Base class -> parameterized constructor => Not Allowed (❌) (now, base class contains a constructor, but by default non-parameterized constructor is called, so it will give error, so ethier call it explicitly from derived class parameterized constructor or declare a default constructor in base class)
*/