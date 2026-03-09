#include <iostream>
using namespace std;

int main(){
    int a = 25;
    int* pointer = &a;

    cout << "Value of x: " << a << endl;
    cout << "Address of x: " << &a << endl;
    cout << "Pointer value: " << pointer << endl;
    cout << "Value using pointer: " << *pointer << endl;
}