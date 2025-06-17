/*

1) Encapsulation in C++:
        Encapsulation is the phenomenon where data (attributes) and methods (functions) are bundled together within a single unit, i.e., a class. The key idea is to protect the data from being accessed directly from outside the class and instead, control access through member functions.

        - wrapping up of data member and member functions in a single unit is called as Encapsulation.
        single unit is actually a class, 
        
        - It is used to implement data hiding - achieved  by making use of private access modifiers
        - control access by making proper use of access modifier

        - Encapsulation promotes data hiding, controlled access.
        - e.g make a random class.
*/

#include <iostream>
using namespace std;

class EncapsulatedClass {
private:
    int secretData;  // Private member, cannot be accessed directly

public:
    // Setter function to set the value of private member
    void setData(int value) {
        secretData = value;
    }

    // Getter function to access the value of private member
    int getData() {
        return secretData;
    }
};

int main() {
    EncapsulatedClass obj;
    obj.setData(42); 
    cout << "Secret Data: " << obj.getData() << endl;  

    // obj.secretData = 10; // This will give an error because secretData is private

    return 0;
}
