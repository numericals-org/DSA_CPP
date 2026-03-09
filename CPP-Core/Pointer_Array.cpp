#include <iostream>
using namespace std;

int main(){

    int arr[3] = {10,20,30};

    int* p = arr;

    cout << *p << endl;
    cout << *(p+1) << endl;
    cout << *(p+2) << endl;

}