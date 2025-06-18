/*
    ✅ What is a Structure?
    A struct is a user-defined data type in C++ that groups different types of variables under one name.
    
    struct StructureName {
        dataType member1;
        dataType member2;
        ...
    };

    ✅ Key Points:
    - All members occupy separate memory.
    - You can access members using the dot (.) operator.
    - Structures can contain functions, too (in C++ only, not C).
    - always use primitive data types here for simplicity

    🧠 When to Use:
    - Use struct when you want to store all values simultaneously.
    - Use union when you want to store only one value at a time, and want to save memory.

*/

#include<iostream>
using namespace std;

struct Student{
    int rollNo;
    // string name; (occupy more space)
    char name[50];
    int marks;
};

int main(){
    Student s1 = {1, "Aman", 91};
    cout << s1.rollNo << " ";
    cout << s1.name << " ";
    cout << s1.marks << endl;

    Student s2;
    s2.rollNo = 2;
    s2.name = "Akshay";
    s2.marks = 96;
    cout << s2.rollNo << " ";
    cout << s2.name << " ";
    cout << s2.marks << endl;

    return 0;
}