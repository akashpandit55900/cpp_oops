#include <iostream>
using namespace std;

class B;

class A{
    private:
        int data1;

    public:
        A(int data1){
            this->data1 = data1;
        }
    
    friend void manipulateData(A obj1, B obj2);
};

class B{
    private:
        int data2;

    public:
        B(int data2){
            this->data2 = data2;
        }
    
    friend void manipulateData(A obj1, B obj2);
};

void manipulateData(A obj1, B obj2){
    cout << "A's data before modification is data1 = " << obj1.data1 << endl;
    cout << "B's data before modification is data2 = " << obj2.data2 << endl;

    obj1.data1 += 2;
    obj2.data2 += 2;

    cout << "A's data after modification is data1 = " << obj1.data1 << endl;
    cout << "B's data after modification is data2 = " << obj2.data2 << endl;
    
    cout << "Some of both is: ";
    cout << obj1.data1 + obj2.data2 << endl;
}

int main(){
    A obj1(8);
    B obj2(18);
    manipulateData(obj1, obj2);

    return 0;
}