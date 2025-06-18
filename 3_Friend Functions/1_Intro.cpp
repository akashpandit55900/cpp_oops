/*
    🔹 What is a Friend Function?
    A friend function is a function that is not a member of a class, but it is given access to the private and protected members of the class.

    You declare a friend function using the friend keyword inside the class.

    🔹 Key Points
    --------------------------------------------------------------------------------------------
    | Feature           | Description                                                          |
    | ----------------- | -------------------------------------------------------------------- |
    | Access            | Can access private and protected members                             |
    | Belongs to class? | ❌ No – it's not a member function                                   |
    | Declaration       | Done inside the class using `friend` keyword                         |
    | Definition        | Done outside the class like a normal function                        |
    | Use case          | When external functions or other classes need access to private data |


    A friend function can be declared anywhere in the class — private, protected, or public.
    Its position doesn't matter because the friend keyword overrides access control.

    🧠 Why?
    - A friend function is not a member of the class.
    - The keyword friend is a grant of access, not affected by private/public placement.
    - So, whether you write it inside the private, protected, or public section, it still works the same way.

    ✅ Key Points:
    - A friend function can access private members, but only through an object.

    - It doesn't belong to the class, so you can't directly access member variables without an object.

    - The friend keyword just gives permission to access private/protected members of the class.

*/
#include <iostream>
using namespace std;

class Box {
private:
    int length;

public:
    Box(int length) {
        this->length = length;
    }

    // Friend function declaration
    friend void display(Box obj);
};

// Friend function definition
void display(Box obj) {
    obj.length = obj.length * 2;
    cout << obj.length << endl;
}

int main() {
    Box obj(10);
    display(obj); // Pass object to friend function
    return 0;
}
