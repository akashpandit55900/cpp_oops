/*
    🔹 What is a Pointer?
    A pointer is a variable that stores the memory address of another variable.

    🔹 Pointer Declaration
    type* pointer_name;

    e.g.:
    int* p;      // pointer to int
    float* f;    // pointer to float
    char* c;     // pointer to char

    int x = 10;
    int* ptr = &x; // ptr stores the address of x

    &x means "address of x"
    int* ptr means "ptr is a pointer to an int"

    🔹 Why Use Pointers?
    - To access memory directly
    - To pass large structures/arrays efficiently
    - To implement dynamic memory allocation
    - For building data structures (linked lists, trees, etc.)
*/
#include <iostream>
using namespace std;

int main(){
    int x = 20;
    int* p = &x;

    cout << "Value of x: " << x << endl;       // 20
    cout << "Address of x: " << &x << endl;    // Some address (address of x)
    cout << "Pointer p: " << p << endl;        // Same address (p's value = address of x)
    cout << "Value at *p: " << *p << endl;     // 20

    // *p is the dereference operator: it gives the value stored at the address.

    // 🔹 Changing Values using Pointers
    int a = 5;
    int *ptr = &a;
    cout << "Before: "<< a << endl;

    *ptr = 22;
    cout << "After: "<< a << endl;

    // 🔹 Null Pointer - A pointer that doesn’t point to any memory.
    // int *ptr1 = NULL;
    int *ptr1 = nullptr;
    cout << ptr1 << endl; // Gives 0 as output
    // cout << *ptr1 << endl; //Gives error -> accesing null


    // 🔹 Dangling Pointer
    // When a pointer points to memory that has been deallocated or goes out of scope.
    int *ptr2;
    {
        int y = 55;
        ptr2 = &y;
        cout << *ptr2 << endl; //55
    }
    cout << ptr2 << endl;
    cout << *ptr2 << endl; //55

    // 🔹 Pointer Arithmetic
    int arr[] = {11, 22, 33, 44, 55};
    int* ptr3 = arr;

    cout << arr << endl; //Points to base address arr[0]
    cout << ptr3 << endl; //Points to base address arr[0]
    cout << *ptr3 << endl; //value at arr[0]

    for(int i=0; i<4; i++){
        cout << *(ptr3 + i) << " ";
    }cout << endl;
    
    ptr3++; //moves to next element
    cout << *ptr3 << endl; //now points to arr[1]
    ptr3--;
    cout << *ptr3 << endl; //now again points to arr[0]
    /*
        Operators:
        - p++ moves to next element
        - p-- moves to previous
        - p + n moves n steps forward
        - p - n moves n steps backward
    */

    return 0;
}


