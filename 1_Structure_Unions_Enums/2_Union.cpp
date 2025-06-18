/*
    ✅ What is a Union?
    A union is similar to a structure, but only one member can store a value at a time because all members share the same memory location.

    ✅ Syntax:
    union UnionName {
        dataType member1;
        dataType member2;
        ...
    };

    ✅ Key Points:
    - Only one member can hold a valid value at a time.
    - Size of the union = size of the largest member.
    - Used for memory-efficient programs, especially in embedded systems.
    - Use only primitive types in the union
*/

#include <iostream>
using namespace std;

union Student {
    int rollNo;
    int marks;
};

int main() {
    Student s1;

    s1.rollNo = 4;        // ✅ sets the value at shared memory
    cout << s1.rollNo << endl;  // prints 4

    s1.marks = 89;        // ✅ overwrites the same memory
    cout << s1.marks << endl;   // prints 89

    // Now check again
    cout << "rollNo (after overwriting): " << s1.rollNo << endl;  // so variable name is diff, but same location, thats why it prints marks value as it was overrited
}
