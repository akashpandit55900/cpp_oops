/*
** Polymorphism
    - Polymorphism means "one entity having many forms."
    - In C++, it refers to the ability of a function, object, or operator to behave in different ways depending on the context. The same function or object can exhibit different behaviors when used with different types or in different situations.

** There are two types of polymorphism in C++:
        // Program run hone se pehle compile hota hai
    - A) Compile-time Polymorphism (Static Binding): Resolved during compilation. It includes:
        1) Function Overloading
            Function overloading allows multiple functions with the same name but with different parameter lists. The compiler differentiates them by their number and types of arguments.

        2) Constructor overloading
            Constructor overloading allows multiple Constructor with the same name but with different parameter lists. The compiler differentiates them by their number and types of arguments.

        3) Operator Overloading: (2 Example below)


    - B) Run-time Polymorphism (Dynamic Binding): Resolved during runtime. It includes:
        1) Function overriding (1 Example below)
        2) Virtual Functions (1 Example below)

    Q.: Why Run-time Polymorphism is called Dynamic Binding and compile-time Polymorphism is called as Static Binding?
    Ans.: The terms static and dynamic binding emphasize the timing of the decision-making process regarding which function to call, with static binding happening at compile time and dynamic binding at runtime.

*/


// 3) Operator Overloading

// Example 1
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Integer addition
    int a = 10, b = 20;
    int result1 = a + b;  // Uses built-in operator for integers
    cout << "Result of integer addition: " << result1 << endl; 

    // String concatenation
    string str1 = "abc", str2 = "def";
    string result2 = str1 + str2;  // Uses built-in operator for strings
    cout << "Result of string concatenation: " << result2 << endl;  

    return 0;
}

// Output:
// Result of integer addition: 30
// Result of string concatenation: abcdef

// Explanation:
// Integer Addition: The integers a and b are added using the + operator, which is already defined for int.
// String Concatenation: The strings str1 and str2 are concatenated using the + operator, which is defined for std::string.



// Example 2: Overloading of + operator to add two objects
//c1 + c2 calls c1.operator+(c2), adds the corresponding members from both objects, stores the result in a temporary object, and returns that object to where the addition expression was used.
//link -> https://chatgpt.com/share/67cff816-46ac-8006-a702-0ef04c3fd92e
#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex(float r, float i){
        this->real = r;
        this->imag = i;
    }

    // Overloading the + operator
    Complex operator + (Complex &obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Function to display complex number
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(1.5, 2.5);
    Complex c2(3.5, 4.5);
    Complex c3 = c1 + c2;  // Calls overloaded + operator
    // Complex c3 = c1 + c2 + c2 + c1;  // Calls overloaded + operator
    c3.display();  
    return 0;
}
