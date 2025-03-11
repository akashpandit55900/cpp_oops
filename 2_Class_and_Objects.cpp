/*
    1) Class ->     A class is a template or blueprint (Dhacha, program design) or logical entity for creating objects. 
                    Since many objects can be created from a class, a class is also called as collection of objects.
                    A class is a collection of data members and member functions.
                    Whenever a class is declared, it doesn’t take any space in memory.
                    It is just a logica for creating objects (i.e. it doesn’t have any physical existence).
                    
                    => Data Members / Attributes / Properties / Variables
                    => Member Function / Method / Behavior / Function inside a class 

    2) Object ->   An object is an Instance of the class.
                   When an object is created, then only memory for that object is allocated based on the class definition. 
                   Every object shares the same class, but every object has its unique identity.

    3) Access Modifiers -> 
                   By default, everything in C++ is Private

                   a) private: data members and member functions are accessible only in its class 

                   b) public: data members and member functions are accessible to everyone (inside class or outside class)
                   
                   c) protected: data members and member functions are accessible inside class and to its derived class

    4) Getters and Setters -> 
                    They are the public functions inside the class that can access private members of class.
                    Usig Getters and Setters, we can access private members outiside the class.

                    Getters -> returns private data members
                    Setters -> sets private data members
                    
*/

//Program 1: Class and Objects
// #include<iostream>
// using namespace std;

// class Car{
//     public:
//         string brand;
//         string model;
//         int year;

//         void displayDetails() {
//             cout << "Brand: " << brand << "\nModel: " << model << "\nYear: " << year << endl;
//         }
// };

// int main(){

//     Car car1;
//     car1.brand = "Toyota";
//     car1.model = "Corolla";
//     car1.year = 2020;
//     car1.displayDetails();

//     cout << "\n";
//     Car car2;
//     car2.brand = "Mercedes";
//     car2.model = "Benz";
//     car2.year = 2022;
//     car2.displayDetails();

//     return 0;
// }


//Program 2: Getters and Setters
#include<iostream>
using namespace std;

class Car{
    private:
        string brand;
        string model;
        int year;

    public: 

        void setBrand(string b){
            brand = b;
        }
        string getBrand(){
            return brand;
        }

        void setModel(string m){
            model = m;
        }
        string getModel(){
           return model;
        }

        void setYear(int y){
            year = y;
        }
        int getYear(){
            return year;
        }
};

int main(){

    Car car1;
    car1.setBrand("Toyota");
    car1.setModel("Fortuner");
    car1.setYear(2022);
    
    cout << "Print car1 details: \n";
    cout << car1.getBrand() << "\n";
    cout << car1.getModel() << "\n";
    cout << car1.getYear() << "\n";
    return 0;
}
