/*
    🔧 What is DMA?
    Dynamic Memory Allocation (DMA) is the process of allocating memory during runtime (not at compile-time).
    This is useful when the amount of memory required is not known in advance.

    In C++, we use:
    new → to allocate memory
    delete → to deallocate memory

    In C, we use:
    malloc → to allocate memory
    free() → to deallocate memory

    ⚠️ Why is delete important?
        If you forget to use delete, memory is not freed, causing a memory leak — your program will consume memory unnecessarily.
    
    | Task             | Use            |
    | ---------------- | -------------- |
    | Allocate 1 int   | new int        |
    | Allocate int arr | new int[n]     |
    | Deallocate 1 int | delete ptr     |
    | Deallocate array | delete[] arr   |

*/

//✅ Syntax of new and delete:
#include <iostream>
using namespace std;

int main(){
    int *ptr = new int; // allocate memory
    *ptr = 55;

    cout << ptr << endl; // points to random memory location
    cout << *ptr << endl; // prints value stored at
    

    // delete ptr; // deallocate memory
    delete(ptr); // deallocate memory


    cout << ptr << endl; // points to random memory location
    cout << *ptr << endl; // Now it contains garbage value 
    

    int *arr = new int[5]; // allocate array of 5 ints

    // use the array
    for(int i=0; i<5; i++){
        arr[i] = 2*(i+1);
    }

    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }cout << endl;
    
    // free the array memory
    // delete(arr);
    // delete arr;
    delete[] arr;
    
    //Now it contains random values
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    return 0;
}