/*
    The Diamond Problem is a classic issue in multiple inheritance, and C++ provides a powerful (but sometimes complex) way to handle it using virtual inheritance.

    💎 What is the Diamond Problem?
    Ambiguity caused by multiple inheritance when a class inherits from two classes that both inherit from the same base.

    🧱 Structure:
    Imagine the following class hierarchy:

    class A {
        public:
            void display() { cout << "A\n"; }
    };
    class B : public A {};
    class C : public A {};
    class D : public B, public C {};

    🧭 Diagram (Diamond Shape):
     A
    / \
   B   C
    \ /
     D

    Now, class D inherits from both B and C, and both B and C inherit from A.

    😵 What’s the Problem?
    When you try to access A's member through D, ambiguity occurs:
    D obj;
    obj.display();  // ❌ Error: ambiguous
    
    ❓Why ambiguous?
    Because D has two copies of class A — one through B and one through C.

    ✅ Solution in C++: Virtual Inheritance
    Ambiguity caused by multiple inheritance when a class inherits from two classes that both inherit from the same base.
    Virtual inheritance tells the compiler: "Hey, if this base class is inherited more than once, just keep one shared instance."

    🔁 Without virtual inheritance:
    You get two copies of the base class → ❌ ambiguity when accessing base class members.

    🔄 With virtual inheritance:
    You get one shared copy of the base class → ✅ no ambiguity, clean access.
*/

//🧱 1) Without Virtual Inheritance (resolve ambiguity manually)
#include<iostream>
using namespace std;

class Vehicle{
    public: 
        void startEngine(){
            cout << "Engine started (Vehicle)\n";
        }
};

class Car : public Vehicle{};
class Truck : public Vehicle{};
class PickupTruck : public Car, public Truck{};

int main(){
    // Vehicle obj;
    // obj.startEngine();

    PickupTruck obj;
    // obj.startEngine(); //❌ Error: request for member 'startEngine' is ambiguous
    /*
        ❌ What went wrong?
        Pickup inherits two copies of Vehicle: one from Car and one from Truck.

        So when we try obj.startEngine(), the compiler says:
        "Which Vehicle's startEngine()? The one from Car or Truck?"
        → ❌ Ambiguous!
    */

    //To resolve ambiguity manually:
    //Use Class name with the scope resolution operator
    obj.Car::startEngine();
    obj.Truck::startEngine();

    return 0;
}



// 2) ✅ Solution: Use Virtual Inheritance (Permanent Solution)
// Virtual inheritance is a special type of inheritance in C++ used specifically to avoid duplication of a base class when multiple paths to it exist (like in the diamond problem).

/*
    The virtual keyword must be applied at the point where the base class is first inherited.
    class Car : virtual public Vehicle {};   // 👈 makes Vehicle shared
    class Truck : virtual public Vehicle {}; // 👈 makes Vehicle shared
    class Pickup : public Car, public Truck {}; // ✅ this works perfectly
*/

#include<iostream>
using namespace std;

class Vehicle{
    public: 
        void startEngine(){
            cout << "Engine started (Vehicle)\n";
        }
};

class Car : virtual public Vehicle{};
class Truck : virtual public Vehicle{};
class PickupTruck : public Car, public Truck{};

int main(){

    PickupTruck obj;
    obj.startEngine(); // ✅ No ambiguity now!

    /*
        🟢 What changed?
            We changed Car and Truck to inherit Vehicle virtually:
            Now Pickup only contains one shared instance of Vehicle.
            So obj.startEngine(); knows exactly which one to call → ✅ No ambiguity
    */
    return 0;
}
