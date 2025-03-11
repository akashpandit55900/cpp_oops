/*
1. Static Variables
    a. Inside Functions
    When a variable is declared as static inside a function, it maintains its value between function calls. Unlike regular local variables, which are destroyed and recreated each time the function is called, a static variable retains its value throughout the program's execution.
*/
// #include <iostream>
// using namespace std;

// void countCalls() {
//     static int count = 0; // Initialized only once
//     count++;
//     cout << "Function called " << count << " times.\n";
// }

// int main() {
//     countCalls(); // Output: Function called 1 times.
//     countCalls(); // Output: Function called 2 times.
//     countCalls(); // Output: Function called 3 times.
//     return 0;
// }

/*
b. Inside Classes
When a variable is declared as static inside a class, it is shared among all instances of the class. It means that there is only one copy of the variable, regardless of how many objects of the class are created.
*/

#include <iostream>
using namespace std;

class Counter {
public:
    static int count; // Declaration of static member variable

    Counter() {
        count++;
    }

    static void displayCount() {
        cout << "Count: " << count << endl;
    }
};

// Definition and initialization of static member variable
int Counter::count = 0;

int main() {
    Counter c1;
    Counter c2;
    Counter c3;
    Counter::displayCount(); // Output: Count: 2
    return 0;
}
