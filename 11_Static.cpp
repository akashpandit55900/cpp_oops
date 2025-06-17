/*
1. Static Variables

    a. Inside Functions
    When a variable is declared as static inside a function, it maintains its value between function calls. Unlike regular local variables, which are destroyed and recreated each time the function is called, a static variable retains its value throughout the program's execution.

    b. Inside Classes
    When a variable is declared as static inside a class, it is shared among all instances of the class. It means that there is only one copy of the variable, regardless of how many objects of the class are created.

    - static varible must be defined outside / declared outside the class
    -  static variables belong to the class, not any specific object.
    - ❗But: You can still access a static variable using an object — it’s just not recommended.

    Access Method	            Allowed?	    Recommended?	   
    ClassName::variable	        ✅ Yes	        ✅ Yes	    
    object.variable	            ✅ Yes	        ❌ No	   


2.  Static Function in C++ (within a class)
    A static function in C++ is a function tied to the class itself, not individual objects, and can be used to operate on shared static data.

    A static function in C++ is a class-level function that:
    - Belongs to the class, not to any specific object.
    - Can be called without creating an object.
    - Can access only static members (not non-static members or this pointer).
*/


// 1) static variable outside the class
#include <iostream>
using namespace std;

void countCalls() {
    static int count = 0; // Initialized only once
    // int count = 0; // Normal varibale, initialize during each function call
    count++;
    cout << "Function called " << count << " times.\n";
}

int main() {
    countCalls(); // Output: Function called 1 times.
    countCalls(); // Output: Function called 2 times.
    countCalls(); // Output: Function called 3 times.
    return 0;
}




// 2) static variable inside the class
#include<iostream>
using namespace std;

class Counter{
    public:
        static int count; // Declaration of static member variable
};

int Counter :: count = 0; // static variable must be initialized outside

int main(){

    // Accessing and modifying the static variable through an object, but it is same for all object (only one copy for all object)
    Counter obj;
    obj.count++;
    cout << obj.count << endl; // Output: 1
    obj.count++;
    cout << obj.count << endl; // Output: 2

    // Accessing the  static variable using the class name
    cout << Counter::count << endl;  // Output: 2

    return 0;
}



// 3) Static Function in C++ (within a class)
#include <iostream>
using namespace std;

class Counter {
private: 
    static int count; // Declaration of static member variable

public:
    static void increment() {
        count++;
        cout << "Count is now: " << count << endl;
    }
};

int Counter::count = 0;  // static variable must be initialized outside

int main() {
    // Counter obj;
    // obj.increment();
    // obj.increment();

    Counter::increment();  // ✅ Call without object
    Counter::increment();

    return 0;
}
