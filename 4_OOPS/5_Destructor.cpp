/*
    ** Destructor ->
        - Opposite of  Constructor i.e it deallocates the memory.
        - A destructor is a special member function in C++ that is automatically called when an object goes out of scope or is explicitly deleted. Its primary purpose is to release (or free-up or deallocates) resources (like memory) that the object may have acquired during its lifetime.

        - Key Points:
            - The destructor has the same name as the class, preceded by a tilde (~) symbol.
            - It cannot have parameters and cannot be overloaded.
            - It is automatically invoked at the end of the object's lifetime, (will automatically delete statically allocated memory)
            - It is explicitly invoked, to free-up the Dynamically allocated memory 
            - DMA make use of 'new' keyword and to delete it we make use of 'delete' keyword

    ** Statically Allocated Memory:
        - Memory is allocated at compile time and has a fixed size.
        - Memory is allocated in the stack.
        - The memory remains allocated throughout the program's lifetime (until the function ends or program exits).
        - Managed by the compiler automatically, so manual deallocation is not required.
        - Size must be known at compile-time.
        - Variables like arrays, structures, or objects are usually stored in the stack.

        Advantages:
            - Easier to manage because memory allocation and deallocation are automatic.
            - Faster access due to stack allocation.

        Disadvantages:
            - Inflexible; size must be known at compile time and cannot change.
            - Stack space is limited, and large static allocations can cause issues.

    ** Dynamically Allocated Memory:
        - Memory is allocated at runtime using keyword like new in C++ or malloc in C.
        - Memory is allocated in the heap and is flexible—size can be determined during execution.
        - Manual deallocation is required using delete (C++) or free (C), otherwise memory leaks may occur.

        Advantages:
            - Flexible: You can allocate memory based on the program's requirements during runtime.
            - Can handle larger data since the heap has more space than the stack.
        
        Disadvantages:
            - Slower access compared to stack due to heap allocation.
            - Manual memory management is required, which can lead to memory leaks if not properly deallocated.

        - Is int arr[10] static and vector<int> arr; dynamic ?
            - int arr[10]; is statically allocated. The array's size (10 in this case) is determined at compile time and cannot be changed during the program's execution. It is stored in the stack, and its memory is automatically managed (deallocated when the array goes out of scope).

            - vector<int> arr; is dynamically allocated. The std::vector from the C++ Standard Library dynamically manages memory on the heap. It can grow and shrink during runtime as needed, and the memory is managed internally by the vector. You don't need to manually allocate or deallocate memory for a vector; it handles memory dynamically as elements are added or removed.

    ** Define memory leak ?
        A memory leak occurs when dynamically allocated memory in a program is not properly deallocated (freed) after it is no longer needed. As a result, the memory remains allocated and inaccessible, reducing the available memory for other operations. Over time, if memory leaks accumulate, they can lead to inefficient memory usage and potentially cause the program to run out of memory, leading to performance degradation or crashes.
*/
#include<iostream>
using namespace std;
class Parent{
    public: 
        int x;

    Parent(int x){
        this->x = x;
        cout << "Constructor is called and x is set to " << x << " and object is " << this << endl;
    }

    ~Parent(){
        cout << "Destructor is called and memory is freed-up for " << this->x << " and " << this << " object is died..." <<endl;
    }
};

int main(){
    Parent obj1(10);
    {
        Parent obj2(20);
    }
    return 0;
}