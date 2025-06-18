/*
    Here's a simple example where a structure in C++ contains a function — which is allowed in C++ (but not in C):

    - Code is just like a class, but with no access modifiers
    
    - The structure behaves almost like a class, except members are public by default.

    🧠 When to Use:
        ✅ Use **struct** when:
        - You are creating a simple data structure (like a record or POD — Plain Old Data).
        - You want all members to be public by default.

        ✅ Use **class** when:
        - You need encapsulation, inheritance, abstraction, etc.
        - You want members to be private by default.

*/

//✅ Example: Structure with a Member Function
#include<iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;

    // Member function inside structure
    int area() {
        return length * breadth;
    }

    void display() {
        cout << "Length: " << length << ", Breadth: " << breadth << endl;
        cout << "Area: " << area() << endl;
    }
};

int main() {
    Rectangle r1;

    r1.length = 10;
    r1.breadth = 5;

    r1.display();

    return 0;
}
