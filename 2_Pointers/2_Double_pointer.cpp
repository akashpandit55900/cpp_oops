/*
    🔁 What is a Double Pointer in C++?
    A double pointer (also known as a pointer to a pointer) is a variable that stores the address of another pointer. That is:

*/

#include <iostream>
using namespace std;

int main(){
    int a = 5;
    int* p = &a;     // p stores address of a
    int** q = &p;    // q stores address of p

    cout << &a << endl;
    cout << p << endl;
    cout << *q << endl;

    cout << &p << endl;
    cout << q << endl;

    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;
    cout << "**q = " << **q << endl;
    return 0;
}